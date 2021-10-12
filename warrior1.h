#include <tuple>
#include <map>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <list>



using namespace std;
const long long INF = 1e8;

class Observer {
public:
	virtual ~Observer() {};
	virtual void upd(const std::string& message_from_subject) = 0;
};

class Subject {
public:
	virtual ~Subject() {};
	virtual void add(Observer* observer) = 0;
	virtual void erase(Observer* observer) = 0;
	virtual void notification() = 0;
};


class Warrior :Subject {//1

private:
	std::list<Observer*> observers;
	std::string message;

public:
	void add(Observer* _observer)override {
		observers.push_back(_observer);
	}
	void erase(Observer* _observer)override {
		observers.remove(_observer);
	}
	void notification()override {
		for (auto x : observers)
			x->upd(message);
	}

	string makeMessage(string _message) {
		message = _message;
		notification();
		return message;
	}

	virtual int getHealth() = 0;

	virtual int getArmour() = 0;

	virtual int getAttack() = 0;

	virtual int removeHealth(int) = 0;

	virtual string info() = 0;

	virtual ~Warrior() = default;
};//1

class Terran : public Warrior {//2
private:
	int health = 100;
	int attack = 100;
	int armour = 100;

	int getHealth() {
		return health;
	}

	int getAttack() {
		return attack;
	}

	int getArmour() {
		return armour;
	}


	int removeHealth(int amount) {
		health -= amount;
		return health;
	}


	string info() {
		return "Terran";
	};

};//2

class Battlecruiser : public Terran {//3
public:
	string info() {
		return "Battlecruiser";
	};
};

class Goliath : public Terran {//3
public:
	string info() {
		return "Goliath";
	};
};

class Protoss : public Warrior {//2
private:
	int health = 100;
	int attack = 100;
	int armour = 100;


	int getHealth() {
		return health;
	}

	int getAttack() {
		return attack;
	}

	int getArmour() {
		return armour;
	}

	int removeHealth(int amount) {
		health -= amount;
		return health;
	}

	string info() {
		return "Protoss";
	};
};

class Archon : public Protoss {//3
public:
	string info() {
		return "Archon";
	};
};

class Dragoon : public Protoss {//3
public:
	string info() {
		return "Dragoon";
	};
};

class Zerg : public Warrior {//2
private:
	int health = 100;
	int attack = 100;
	int armour = 100;

	int getHealth() {
		return health;
	}

	int getAttack() {
		return attack;
	}

	int getArmour() {
		return armour;
	}

	int removeHealth(int amount) {
		health -= amount;
		return health;
	}

	string info() {
		return "Zerg";
	};
};

class InfestedTerran : public Zerg {//3
public:
	string info() {
		return "Infested Terran";
	};
};

class Zealot : public Zerg {//3

public:
	string info() {
		return "Zealot";
	};
};


enum Squad {
	TerranSquad = 0,
	ProtossSquad,
	ZergSquad,
};

enum WarriorType {
	Battlecruiser_TRN = 0,
	Goliath_TRN,
	Archon_PTS,
	Dragoon_PTS,
	InfestedTerran_ZRG,
	Zealot_ZRG,
};



class Factory {
public:
	virtual Warrior* createWarrior(Squad, WarriorType) = 0;

	virtual ~Factory() = default;
};

class TerranFactory : public Factory {
public:
	Warrior* createWarrior(Squad squad, WarriorType type) override {
		switch (squad, type) {
		case (TerranSquad, Battlecruiser_TRN):
			return new Battlecruiser;
		case (TerranSquad, Goliath_TRN):
			return new Goliath;
		}
	}
};

class ProtossFactory : public Factory {
public:
	Warrior* createWarrior(Squad squad, WarriorType type) override {
		switch (squad, type) {
		case (ProtossSquad, Archon_PTS):
			return new Archon;
		case (ProtossSquad, Dragoon_PTS):
			return new Dragoon;
		}
	}
};

class ZergFactory : public Factory {
public:
	Warrior* createWarrior(Squad squad, WarriorType type) override {
		switch (squad, type) {
		case (ZergSquad, InfestedTerran_ZRG):
			return new InfestedTerran;
		case (ZergSquad, Zealot_ZRG):
			return new Zealot;
		}
	}
};



class combatBase :public Observer {

public:
	combatBase(/*Warrior& _subject*/) /*: subject(_subject)*/ {
		//this->subject.add(this);
		health = 100;
		maximumNumberOfUnits = 5;
		cntOfUnits = 0;
	}
	void upd(const std::string& message_from_subject) override {
		message_from_subject_ = message_from_subject;
		PrintInfo();
	}
	//void RemoveMeFromTheList() {
		//subject.erase(this);
	//}
	void PrintInfo() {
		cout << this->message_from_subject_ << "\n";
	}

	Warrior* createUnit(Squad squad, WarriorType warriorType) {
		auto terranFactory = new TerranFactory;
		auto protossFactory = new ProtossFactory;
		auto zergFactory = new ZergFactory;

		Warrior* battleUnit = 0;

		switch (squad) {
		case TerranSquad:
			battleUnit = (terranFactory->createWarrior(squad, warriorType));
			battleUnit->add(this);
			subject = battleUnit;
			return battleUnit;
		case ProtossSquad:
			battleUnit = (protossFactory->createWarrior(squad, warriorType));
			battleUnit->add(this);
			subject = battleUnit;
			return battleUnit;

		case ZergSquad:
			battleUnit = (zergFactory->createWarrior(squad, warriorType));
			battleUnit->add(this);
			subject = battleUnit;
			return battleUnit;
		}
		return battleUnit;
	}
	void eraseObserverInfo() {
		subject->erase(this);
	}
	int getHealth() {
		return health;
	}
	int getCntOfUnits() {
		return cntOfUnits;
	}
	int getMaximumCntOfUnits() {
		return maximumNumberOfUnits;
	}
	int removeHealth(int amount) {
		health -= amount;
		return health;
	}
private:
	int health, maximumNumberOfUnits, cntOfUnits;
	string message_from_subject_;
	Warrior* subject;
};



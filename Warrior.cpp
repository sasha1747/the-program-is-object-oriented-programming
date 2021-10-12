/*#include <tuple>
#include <map>
#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;
const long long INF = 1e8;





class Warrior {//1
	vector<combatBase*>subscribers;

	void addSubscriber(combatBase* _subscriber) {
		subscribers.push_back(_subscriber);
	}

	void removeSubscriber(combatBase* _subscriber) {
		for (int ind = 0; ind < subscribers.size(); ind++)
			if (subscribers[ind] == _subscriber)
				subscribers.erase(subscribers.begin() + ind);
	}
protected:
	void startUpd(string message) {
		for (int ind = 0; ind < subscribers.size(); ind++) {
			subscribers[ind]->upd(message);
		}
	}

public:

	virtual int getHealth() = 0;

	virtual int getArmour() = 0;

	virtual int getAttack() = 0;

	virtual int removeHealth(int) = 0;

	virtual string info() = 0;

	virtual bool hasDied() = 0;

	virtual ~Warrior() = default;
};//1

class Terran : public Warrior {//2
private:
	int health = 100;
	int attack = 100;
	int armour = 100;


	bool hasDied() {
		if (health <= 0) {
			string message = info() + " " + "has died\n";
			startUpd(message);
			return 1;
		}
		return 0;
	}

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

	bool hasDied() {
		if (health <= 0) {
			string message = info() + " " + "has died\n";
			startUpd(message);
			return 1;
		}
		return 0;
	}

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

	bool hasDied() {
		if (health <= 0) {
			string message = info() + " " + "has died\n";
			startUpd(message);
			return 1;
		}
		return 0;
	}

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
*/
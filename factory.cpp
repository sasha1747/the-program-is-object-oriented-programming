/*#include "Warrior.cpp"
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
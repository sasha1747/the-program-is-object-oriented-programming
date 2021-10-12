#include "warrior1.h"
using namespace std;
class Iter {
private:
	//int stk;
	int sumOfInd;
	int cSize;
public:
	Iter(int beggin, int _cSize) {
		//stk = beggin;
		sumOfInd = beggin;
		cSize = _cSize;
	}
	void first() {
		sumOfInd = 0;
	}
	void next() {
		sumOfInd++;
	}
	void prev() {
		sumOfInd--;
	}
	/*bool isDone() {
		return ind == stk->sp + 1;
	}*/
	tuple<int, int> currentItem() {
		int posi = sumOfInd / cSize;
		//return stk->items[ind];
		int posj = sumOfInd % cSize;
		return (tuple<int, int>(posi, posj));
	}
};
class Scene {

private:
	map<tuple<int, int>, Warrior*> unitsOnScene;
	map<tuple<int, int>, combatBase*> basesOnScene;
	bool check(int i, int j) {
		return(i < fieldSize&& j < fieldSize);
	}
public:
	int fieldSize;
	//int si, sj;
	friend class Iter;
	combatBase createBase() {
		return(*new combatBase());
	}
	void createGameField() {
		std::cout << "Insert coin and specify the size of the playing field:";
		std::cin >> fieldSize;
		for (int i = 0; i < fieldSize; i++) {
			if (i == 0 or i == fieldSize - 1) {
				for (int j = 0; j < fieldSize; j++) {
					std::cout << "X  ";
				}
				std::cout << "\n";
			}
			else {
				for (int j = 0; j < fieldSize; j++) {
					if (j == 0) {
						std::cout << "X  ";
					}
					else if (j == fieldSize - 1) {
						std::cout << "X\n";
					}
					else {
						std::cout << "   ";
					}
				}
			}
		}
	}

	void printGameField() {
		system("cls");
		for (int i = 0; i < fieldSize; i++) {
			if (i == 0 or i == fieldSize - 1) {
				for (int j = 0; j < fieldSize; j++) {
					std::cout << "X  ";
				}
				std::cout << "\n";
			}
			else {
				for (int j = 0; j < fieldSize; j++) {
					if (j == 0) {
						std::cout << "X  ";
					}
					else if (j == fieldSize - 1) {
						std::cout << "X\n";
					}
					else if (unitsOnScene.count(tuple<int, int>(i, j)) != 0) {
						if (unitsOnScene[tuple<int, int>(i, j)]->info() == "Battlecruiser")
							std::cout << "B  ";
						if (unitsOnScene[tuple<int, int>(i, j)]->info() == "Goliath")
							std::cout << "G  ";
						if (unitsOnScene[tuple<int, int>(i, j)]->info() == "Archon")
							std::cout << "A  ";
						if (unitsOnScene[tuple<int, int>(i, j)]->info() == "Dragoon")
							std::cout << "D  ";
						if (unitsOnScene[tuple<int, int>(i, j)]->info() == "Infested Terran")
							std::cout << "I  ";
						if (unitsOnScene[tuple<int, int>(i, j)]->info() == "Zealot")
							std::cout << "Z  ";
						//std::cout << "!  ";
					}
					else
						std::cout << "   ";
				}
			}
		}
	}

	/*Warrior* createUnit(Squad squad, WarriorType warriorType) {
		auto terranFactory = new TerranFactory;
		auto protossFactory = new ProtossFactory;
		auto zergFactory = new ZergFactory;

		Warrior* battleUnit = 0;

		switch (squad) {
		case TerranSquad:
			battleUnit = (terranFactory->createWarrior(squad, warriorType));
			return battleUnit;
		case ProtossSquad:
			battleUnit = (protossFactory->createWarrior(squad, warriorType));
			return battleUnit;

		case ZergSquad:
			battleUnit = (zergFactory->createWarrior(squad, warriorType));
			return battleUnit;
		}
		return battleUnit;
	};*/


	void addUnit(Warrior* unit, int x, int y) {
		if (!(check(x, y))) {
			cout << "Incorrect coordinates\n";
			return;
		}
		unitsOnScene.insert(make_pair(tuple<int, int>(x, y), unit));
	}

	void addBase(combatBase* base, int x, int y) {
		if (!(check(x, y))) {
			cout << "Incorrect coordinates\n";
			return;
		}
		basesOnScene.insert(make_pair(tuple<int, int>(x, y), base));
	}


	void totalUnitsOnMap() {
		cout << "Total units on a map: " << unitsOnScene.size() << endl;
	}


	void totalBasesOnMap() {
		cout << "Total bases on a map: " << basesOnScene.size() << endl;
	}

	//void totalUnitRemaining() {
		//cout << "Total units remaining: " << (fieldSize - 2) * (fieldSize - 2) - unitsOnScene.size() << endl;
	//}


	/*void allUnitInfo() {
		cout << "Here is all game units: " << endl;
		cout << "__________________________________________" << endl;
		for (auto const& [k, v] : unitsOnScene) {
			std::cout << v->info() << " is available at coordinate: (" << std::get<0>(k) << ", " << std::get<1>(k)
				<< ")" << std::endl;
		}
		cout << "__________________________________________" << endl;
	}*/


	tuple<int, int> coordinate(int x, int y) {
		return tuple<int, int>(x, y);
	}

	void getValueUnitFrom(int x, int y) {
		if (unitsOnScene.count(tuple<int, int>(x, y)) != 0)
			cout << unitsOnScene[tuple<int, int>(x, y)]->info() << endl;
		else
			cout << "There is nothing in this cell\n";
	}

	void moveUnit(Warrior* unit, int x, int y) {//если кто-то был в клетке, в которую мы перемещаем, то этот кто-то удаляется
		if (!(check(x, y))) {
			cout << "Incorrect coordinates\n";
			return;
		}
		tuple<int, int> st(-INF, -INF);
		for (auto x : unitsOnScene) {
			if (x.second == unit) {
				st = x.first;
				//x.second = nullptr;
				unitsOnScene.erase(x.first);
				break;
			}
		}
		if (st == tuple<int, int>(-INF, -INF))
			cout << "Unit not found\n";
		else
			unitsOnScene[tuple<int, int>(x, y)] = unit;
		return;
	}

	//void remove() {

		//       for (auto const & [k, v] : unitsOnScene)
		//       {
		//           std::cout << "Coordinate: " << std::get<0>(k) << std::get<1>(k) << " Value: " << v->info() << std::endl;
		//       }
		//
		//      unitsOnScene[changeCoordinateValue(3, 5)] = 0;
	//};

	//coordinate


	void getUnitAttack(Warrior* unit) {
		cout << unit->getAttack() << endl;
	};

	void getUnitArmour(Warrior* unit) {
		cout << unit->getArmour() << endl;
	};

	string getUnitInfo(Warrior* unit) {
		return unit->info();
	};
	int getUnitHealth(Warrior* unit) {
		return(unit->getHealth());
	};
	void removeUnitHealth(int ammount, Warrior* unit) {
		unit->removeHealth(ammount);
		if (getUnitHealth(unit) <= 0) {
			unit->makeMessage("Unit " + getUnitInfo(unit) + " has died\n");
			auto thisUnit = findTheCoordinatesOfTheUnit(unit);
			unitsOnScene.erase(thisUnit);
		}
	};
	int getBaseHealth(combatBase* base) {
		return(base->getHealth());
	};

	void removeBaseHealth(int ammount, combatBase* base) {
		base->removeHealth(ammount);
		if (getBaseHealth(base) <= 0) {
			auto thisBase = findTheCoordinatesOfTheBase(base);
			basesOnScene.erase(thisBase);
			base->eraseObserverInfo();
		}
	}

	void removeBase(combatBase* base) {
		auto thisBase = findTheCoordinatesOfTheBase(base);
		basesOnScene.erase(thisBase);
		base->eraseObserverInfo();
	}

	void removeBaseFromCoord(int i, int j) {
		if (!(check(i, j))) {
			cout << "Incorrect coordinates\n";
			return;
		}
		basesOnScene.erase(tuple<int, int>(i, j));
		basesOnScene[tuple<int, int>(i, j)]->eraseObserverInfo();
	}


	//Iter* createIterator(int Csize) const;
	Iter* createIterator(int cSize)const {
		return new Iter(0, cSize);
	}

	void removeUnit(Warrior* unit) {
		unit->makeMessage("Unit " + getUnitInfo(unit) + "has died\n");
		auto thisUnit = findTheCoordinatesOfTheUnit(unit);
		unitsOnScene.erase(thisUnit);
	};

	void removeUnitFromCoord(int i, int j) {
		if (!(check(i, j))) {
			cout << "Incorrect coordinates\n";
			return;
		}
		unitsOnScene.erase(tuple<int, int>(i, j));
	}

	tuple<int, int> findTheCoordinatesOfTheUnit(Warrior* unit) {
		for (auto x : unitsOnScene) {
			if (x.second == unit) {
				return(x.first);
			}
		}
		return(tuple<int, int>(-INF, -INF));
	}

	tuple<int, int> findTheCoordinatesOfTheBase(combatBase* base) {
		for (auto x : basesOnScene) {
			if (x.second == base) {
				return(x.first);
			}
		}
		return(tuple<int, int>(-INF, -INF));
	}

	//void getIsUnitDied(Warrior* unit) {
		//if (unit->hasDied()) {
			//tuple<int, int>coord = findTheCoordinatesOfTheUnit(unit);
		//	remove(get<0>(coord), get<1>(coord));
		//}
	//}
};
/*#ifndef BASE_H
#define BASE_H

#include "warrior1.h"


using namespace std;

class combatBase{
public:
	//virtual void addSubscriber(combatBase* _subscriber) = 0;
	//virtual void removeSubscriber(combatBase* _subscriber) = 0;

	Warrior* createUnit(Squad squad, WarriorType warriorType);

	int health, maximumNumberOfUnits, cntOfUnits;

	combatBase() {
		health = 100;
		maximumNumberOfUnits = 5;
		cntOfUnits = 0;
		//randomDistribution = rand() % 1000000 + 1;
	}
	void upd(string message) {
		cout << message;
		cntOfUnits--;
	}


};


#endif*/
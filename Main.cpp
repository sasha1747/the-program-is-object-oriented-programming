#include "Scene.cpp"
Scene scene;
int main() {
	scene.createGameField();
	//combatBase base1 = *new combatBase();
	combatBase base1 = scene.createBase();
	Warrior* terran = base1.createUnit(TerranSquad, Battlecruiser_TRN);
	scene.addUnit(terran, 8, 8);
	Warrior* terran1 = base1.createUnit(TerranSquad, Goliath_TRN);
	scene.addUnit(terran1, 5, 5);
	scene.addBase(&base1, 7, 8);
	scene.removeBaseHealth(1000, &base1);
	scene.printGameField();
	scene.removeUnitHealth(1000, terran);
	scene.removeUnitFromCoord(1, 100);
	scene.printGameField();
	Scene scene1 = scene;
	scene1.printGameField();
	Iter I = *scene.createIterator(scene.fieldSize);
	//I.next();
	/*while (1) {
		tuple<int, int> check = I.currentItem();
		I.next();
		check = I.currentItem();
	}*/
	scene.moveUnit(terran, 3, 7);
	scene.getValueUnitFrom(3, 7);
	scene.printGameField();
	return 0;
}
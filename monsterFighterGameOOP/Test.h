#ifndef TEST_H
#define TEST_H
#include "Creature.h"

// 2.1 creatureGetterTest();
void creatureGetterTest(Creature& creature)
{
	std::cout << "Creature name: " << creature.getName() << '\n';
	std::cout << "Creature symbol: " << creature.getSymbol() << '\n';
	std::cout << "Creature health: " << creature.getHealth() << '\n';
	std::cout << "Creature damage: " << creature.getDamage() << '\n';
	std::cout << "Creature gold: " << creature.getGold() << '\n';
}
#endif
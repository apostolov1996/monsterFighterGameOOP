#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include "Test.h"
#include "Constants.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max)
{
	static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) }; // static used for efficiency, so we only calculate this value once
	// evenly distribute the random number across our range
	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
    std::rand(); //get rid of first result
	for (int i{ 0 }; i < 10; ++i)
	{
		Monster m{ Monster::getRandomMonster() };
		creatureGetterTest(m);
	}
	return 0;
}
#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include "Test.h"
#include "Constants.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<string>

int getRandomNumber(int min, int max)
{
	static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) }; // static used for efficiency, so we only calculate this value once
	// evenly distribute the random number across our range
	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}
void printLogo();
void printMenu();
void printInstructions();
int getMenuOperation();
void fightMonster(Player& player);

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
    std::rand(); //get rid of first result

	printLogo();
	std::string playerName{};
	std::cout << "Enter your name: ";
	std::cin >> playerName;
	Player player{ playerName };


	int operation{};
	bool repeat{true};
	
	
	while (repeat)
	{
		std::cout << "\n\nHello, " << playerName << ".\n"; 
		printMenu();
		operation = getMenuOperation();
		switch (operation)
		{
		case 1:
			fightMonster(player);
			break;
		case 2:
			printInstructions();
			break;
		case 3:
			std::cout << "Case 3:\n";
			repeat = false;
			break;
		}
	}
	std::cout << "Goodbye!\n";
	return 0;
}
#include <iostream>
#include "Constants.h"
#include "Creature.h"
#include "Player.h"
#include "Monster.h"

// LOGO INFORMATION---------------------------------------------------------------------------------
void printLogo()
{
	std::cout << "Welcome to DUNGEON FIGHTER\n\n";
}
void printMenu()
{
	std::cout << "\n\nMAIN MENU\n";
	std::cout << "1) Start new game.\n";
	std::cout << "2) Instructions.\n";
	std::cout << "3) Exit.\n";
}
void printInstructions()
{
	std::cout << "\n\nINSTRUCTIONS\n";
	std::cout << "- The player encounters one randomly generated monster at a time.\n\n";
	std::cout << "- For each monster, the player has two choices: (R)un or (F)ight.\n\n";
	std::cout << "- If the player decides to Run, they have a 50% chance of escaping.\n\n";
	std::cout << "- If the player escapes, they move to the next encounter with no ill effects.\n\n";
	std::cout << "- If the player does not escape, the monster gets a free attack, and the player chooses their next action.\n\n";
	std::cout << "- If the player chooses to fight, the player attacks first. The monster's health is reduced by the player's damage.\n\n";
	std::cout << "- If the monster dies, the player takes any gold the monster is carrying. The player also levels up, increasing their level, health and damage by 1.\n\n";
	std::cout << "- If the monster does not die, the monster attacks the player back. The player's health is reduced by the monster's damage.\n\n";
	std::cout << "- The game ends when the player has died (loss) or reached level 20 (win)\n\n";
	std::cout << "- If the player dies, the game should tell the player what level they were and how much gold they had.\n\n";
	std::cout << "- If the player wins, the game should tell the player they won, and how much gold they had\n\n";
}
// INPUT REQUESTS-----------------------------------------------------------------------------------
int getInteger()
{
	int x{};
	while (true)
	{
		std::cin >> x;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid input, try again.\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return x;
		}
	}
}

char getChar()
{
	char ch{};
	while (true)
	{
		std::cin >> ch;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid input, try again.\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return ch;
		}
	}
}
// OPERATIONS---------------------------------------------------------------------------------------

int getMenuOperation()
{
	int operation{};
	while (true)
	{
		std::cout << "Operation: ";
		operation = getInteger();
		if (operation >= 1 && operation <= 3)
		{
			return operation;
		}
		std::cout << "Invalid input, try again.\n";
	}
}

char getPlayerOperation()
{
	char operation{};
	while (true)
	{
		std::cout << "(R)un or (F)ight: ";
		operation = getChar();
		if (operation == 'R' || operation == 'F' || operation=='r' || operation=='f')
		{
			return operation;
		}
		std::cout << "Invalid input, please try again.\n";
	}
}

// GAMEPLAY FUNCTIONS-------------------------------------------------------------------------------
int getRandomNumber(int min, int max);
// The monster attacks the player, 50% chance to miss, 50% chance to hit.
void attackPlayer(Player& player, Monster& monster, bool miss)
{
	if (miss)
	{
		std::cout << "You successfully fled.\n";
	}
	else 
	{
		std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage.\n";
		player.reduceHealth(monster.getDamage());
		std::cout << "You have " << player.getHealth() << " health now.\n";
	}
}

void attackMonster(Player& player, Monster& monster)
{
	bool loop{ !player.isDead() };
	while (loop) {
		std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage.\n";
		monster.reduceHealth(player.getDamage());
		if (monster.isDead())
		{
			std::cout << "You killed the " << monster.getName() << ".\n";
			player.levelUp();
			player.addGold(monster.getGold());
			std::cout << "You are now level " << player.getLevel() << ".\n";
			std::cout << "You have " << player.getHealth() << " health now.\n";
			std::cout << "You found " << monster.getGold() << " gold.\n";
			loop = false;
		}
		else
		{
			attackPlayer(player, monster, false);
			loop = !player.isDead();
		}
	}
}

void fightMonster(Player& player)
{
	while(!player.isDead() && !player.hasWon()) {
		std::cout << "\n\n";
		Monster monster{ Monster::getRandomMonster() };
		std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << "). \n";
		char playerOperation{ getPlayerOperation() };
		if (playerOperation == 'R' || playerOperation=='r')
		{
			attackPlayer(player, monster, static_cast<bool>(getRandomNumber(0, 1)));
		}
		else
		{
			attackMonster(player, monster);
		}
	}
	if (!player.hasWon())
	{
		std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
	}
	else
	{
		std::cout << "Congratulations. You won! You have " << player.getGold() << "gold .\n";
	}
}


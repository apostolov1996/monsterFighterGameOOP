#ifndef PLAYER_H
#define PLAYER_H
#include "Constants.h"
#include "Creature.h"
class Player :public Creature 
{
private:
	int m_level{ 1 };
public:	
	// 3.1 Default player constructor:
	Player() :Creature()
	{
		std::cout << "Player: Default constructor has been used.\n";
	}
	// 3.2 Non Default player constructor:
	Player(const std::string& name) :Creature(name, PLAYER_SYMBOL, PLAYER_START_HEALTH, PLAYER_START_DAMAGE, PLAYER_START_GOLD)
	{
		std::cout << "Player: Non default constructor has been used.\n";
	}
	// 3.3 getLevel():
	const int& getLevel() const { return m_level; }
	// 3.4 Level up function:
	void levelUp()
	{
		++m_level;
		++m_damage;
	}
	// 3.5 hasWon Function:
	bool hasWon() { return (m_level >= PLAYER_MAX_LEVEL); }
};
#endif
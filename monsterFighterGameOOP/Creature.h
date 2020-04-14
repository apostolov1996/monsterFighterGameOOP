#ifndef CREATURE_H
#define CREATURE_H
#include <string>
#include <iostream>
class Creature
{
protected:
	std::string m_name;
	char m_symbol;
	int m_health;
	int m_damage;
	int m_gold;
public:
	// 1.1 Default creature constructor:
	Creature() : m_name{ "" }, m_symbol{ '\0' }, m_health{ 0 }, m_damage{ 0 }, m_gold{ 0 }
	{
		/*std::cout << "Creature: Default constructor has been used.\n";*/
	}
	// 1.2 Non Default creature constructor (Non-const):
	Creature(const std::string& name, char symbol, int health, int damage, int gold) :
		m_name{ name }, m_symbol{ symbol }, m_health{ health }, m_damage{ damage }, m_gold{ gold }
	{
		/*std::cout << "Creature: Non default constructor has been used.\n";*/
	}
	// 1.3 getName():
	const std::string& getName() const { return m_name; }
	// 1.4 getSymbol():
	const char& getSymbol() const { return m_symbol; }
	// 1.5 getHealth():
	const int& getHealth() const { return m_health; }
	// 1.6 getDamage():
	const int& getDamage() const { return m_damage; }
	// 1.7 getGold():
	const int& getGold() const { return m_gold; }
	// 1.8 redueHealth():
	void reduceHealth(int source)
	{
		m_health -= source;
	}
	// 1.9 isDead():
	bool isDead()
	{
		return (m_health <= 0);
	}
	// 1.10 addGold()
	void addGold(int source)
	{
		m_gold += source;
	}
};
#endif
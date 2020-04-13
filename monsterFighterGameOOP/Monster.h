#ifndef MONSTER_H
#define MONSTERH_H
#include "Creature.h"
#include "Constants.h"
#include <string>
#include <string_view>
#include <array>

int getRandomNumber(int min, int max);
class Monster : public Creature
{
	// Monster types:
public:
	enum Type {
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};
	// Monster const struct, used to generate a random monster:
private:
	struct MonsterData {
		std::string_view name;
		char symbol;
		int health;
		int damage;
		int gold;
	};
	// Monster std::array cotainer, used to contain data related to the monster stats:
	static constexpr std::array<MonsterData, Monster::MAX_TYPES> monsterData{
		{{DRAGON_NAME, DRAGON_SYMBOL, DRAGON_HEALTH, DRAGON_DAMAGE, DRAGON_GOLD},
		{ORC_NAME, ORC_SYMBOL, ORC_HEALTH, ORC_DAMAGE, ORC_GOLD},
		{SLIME_NAME, SLIME_SYMBOL, SLIME_HEALTH, SLIME_DAMAGE, SLIME_GOLD}}
	};
	// Monster consturctor implementation, here I link the Creature non default constructor:
public:
	Monster(Type type) : Creature(
		monsterData[type].name.data(),
		monsterData[type].symbol,
		monsterData[type].health,
		monsterData[type].damage,
		monsterData[type].gold
		)
	{
		std::cout << "A monster has been created.\n";
	}
	static Monster getRandomMonster()
	{
		return (Monster(static_cast<Type>(getRandomNumber(0, MAX_TYPES-1))));
	}
};
#endif
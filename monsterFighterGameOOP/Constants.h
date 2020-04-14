#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>
#include <string_view>
//------------------------------------------------------
// PLAYER CONSTS:
const char PLAYER_SYMBOL = '@';
const int PLAYER_START_HEALTH = 10;
const int PLAYER_START_DAMAGE = 1;
const int PLAYER_START_GOLD = 0;
const int PLAYER_MAX_LEVEL = 20;
// WHEN LEVEL UP:
const int PLAYER_INCREASE_HEALTH = 1;
const int PLAYER_INCREASE_DAMAGE = 1;
//------------------------------------------------------
// MONSTER SETTINGS:

//DRAGON SETTINGS:
constexpr std::string_view DRAGON_NAME = "dragon";
const char DRAGON_SYMBOL = 'D';
const int DRAGON_HEALTH = 20;
const int DRAGON_DAMAGE = 4;
const int DRAGON_GOLD = 100;

//ORC SETTINGS:
constexpr std::string_view ORC_NAME = "orc";
const char ORC_SYMBOL = 'o';
const int ORC_HEALTH = 4;
const int ORC_DAMAGE = 2;
const int ORC_GOLD = 25;

//SLIME SETTINGS:
constexpr std::string_view SLIME_NAME = "slime";
const char SLIME_SYMBOL = 's';
const int SLIME_HEALTH = 1;
const int SLIME_DAMAGE = 2;
const int SLIME_GOLD = 10;
//------------------------------------------------------
#endif

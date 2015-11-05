#include <string>
#include "attack.h"

using namespace std;

class pokemon
{
public:
  pokemon(){};
  pokemon(int lvl) {level = lvl; hp = lvl * 10;};
  string pkmn, nickname, type;
  int level, hp;
  attack* moves[4];
}; // class pokemon

class squirtle: public pokemon
{
public:
  squirtle(int lvl) {level = lvl; hp = lvl* 10; pkmn = "Squirtle"; type = "Water";};
};

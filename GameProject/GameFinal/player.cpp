#include "player.h"

using namespace std;

player::player(){};

player::player(string nam, int health)
{
  name = nam;
  hp = health;
  inv = new inventory(0);
  inv->potion++;
}

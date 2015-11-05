#ifndef INVENTORY_H
  #define INVENTORY_H
  #include "inventory.h"
#endif // INVENTORY_H
#include <string>

using namespace std;

class player{
  public:
    player();
    player(string nam, int health);
    string name;
    int hp;
    inventory* inv;
}; // class player

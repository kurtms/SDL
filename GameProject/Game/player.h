#include "inventory.h"
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

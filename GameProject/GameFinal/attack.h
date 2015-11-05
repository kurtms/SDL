#include <string>

using namespace std;

class attack
{
  public:
  attack() {};
  attack(string nam, int p, int pwr, int ac) {name = nam; pp = p; pow = pwr; acc = ac;}
  string name;
  int pp, pow, acc;
  string type;
}; // class attack

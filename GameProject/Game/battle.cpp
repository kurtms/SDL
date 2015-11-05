#include "player.h"
#include "battle.h"

bool battle(player* plyr)
{
  squirtle* enemy = new squirtle(10);
  char i, j;
  while(enemy->hp > 0)
  {
    cout << string(50, '\n');
    cout << "A wild " << enemy->pkmn << " appeared" << endl;
    cout << enemy->pkmn << " HP:" << enemy->hp << endl;
    cout << "Your HP:" << plyr->hp << endl;
    cout << "Battle!" << endl << "1. Attack" << endl << "2. Potion" << endl << "3. Run" << endl;
    cin >> i;
    if(i == '1')
    {
      enemy->hp -= rand() % 100;
      cout << "The wild " << enemy->pkmn << " attacked!" << endl;
      plyr->hp -= rand() % 25;
      if(plyr->hp <= 0)
      {
        cout << "You blacked out" << endl;
        return 1;
      }
    }
    if(i == '2')
    {
      cout << plyr->inv->potion << " potions left" << endl << "Use one?" << endl << "y/n" << endl;
      cin >> j;
      if(j == 'y')
      {
        if(plyr->inv->potion > 0)
        {
          plyr->inv->potion--;
          plyr->hp += 15;
          if(plyr->hp > 100)
          {
            plyr->hp = 100;
          }
          cout << "The wild " << enemy->pkmn << " attacked!" << endl;
          plyr->hp -= rand() % 25;
        }
        else
        {
          cout << "No potions left!" << endl;
        }
      }
    }
    if(i == '3')
    {
      cout << "Got away safely!" << endl;
      break;
    }
  }
  return 0;
}

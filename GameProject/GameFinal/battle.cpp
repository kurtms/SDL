#include "player.h"
#include "battle.h"
#ifndef MAP_H
  #define MAP_H
  #include "map.h"
#endif // MAP_H

bool battle(player* plyr, SDL_Surface* screen, SDL_Window* win, SDL_Renderer* render)
{
  mapData* mapDat = new mapData;
  mapDat->mapName = "maps/battle.txt";
  SDL_Event e;
  printRoute(2,4, fileToMap(mapDat), 100, 100, plyr, screen, e, render);
  SDL_UpdateWindowSurface(win);
  squirtle* enemy = new squirtle(10);
  SDL_Delay(1000);
  char i = '3', j;
  while(enemy->hp > 0)
  {
    cout << string(50, '\n');
    cout << "A wild " << enemy->pkmn << " appeared" << endl;
    cout << enemy->pkmn << " HP:" << enemy->hp << endl;
    cout << "Your HP:" << plyr->hp << endl;
    cout << "Battle!" << endl << "1. Attack" << endl << "2. Potion" << endl << "3. Run" << endl;
    //cin >> i;
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

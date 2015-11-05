#ifndef PLAYER_H
  #define PLAYER_H
  #include "player.h"
#endif // PLAYER_H
#ifndef GAME_H
  #define GAME_H
  #include "game.h"
#endif // GAME_H
#include "menu.h"
#include "save.h"

using namespace std;

void printMenu(game* game)
{
  cout << string(50, '\n');
  char i;
  cout << "1. Save" << endl
       << "2. Close" << endl;
  cin >> i;
  switch(i)
  {
//    case('3'):
//      cout << "Idk, like 3 maybe? (dont want to deal with paramaters rn..." << endl;
//      cin >> i;
    case('1'):
      save(game);
      cout << "Saved!" << endl;
      cin >> i;
    case('2'):
      break;
  }
}

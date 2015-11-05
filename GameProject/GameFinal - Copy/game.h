#include <sdl.h>
#include <cstdio>
#include <ctime>
#include <string>
#ifndef PLAYER_H
  #define PLAYER_H
  #include "player.h"
#endif // PLAYER_H

const int SCREEN_HEIGHT = 400;
const int SCREEN_WIDTH = 400;

const int mx = SCREEN_WIDTH, my = SCREEN_HEIGHT; // map size

using namespace std;

class game
{
public:
  int x, y;
  string curMap;
  player* plyr;
  game(int X, int Y, string map, player* p) {x = X; y = Y; curMap = map; plyr = p;};
};

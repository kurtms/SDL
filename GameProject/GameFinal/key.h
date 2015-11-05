#include <SDL.h>
#include <iostream>
#ifndef GAME_H
  #define GAME_H
  #include "game.h"
#endif // GAME_H
#ifndef MAP_H
  #define MAP_H
  #include "map.h"
#endif // MAP_H

using namespace std;

void movement(SDL_Event e, char** map, game* gam, int &x, int &y);

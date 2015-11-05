#ifndef GAME_H
  #define GAME_H
  #include "game.h"
#endif // GAME_H
#include <SDL.h>

enum keys
{
  up,
  down,
  left,
  right,
  best,
  other
};

class display
{
public:
  SDL_Window* window;
  SDL_Event e;
  int SCREEN_WIDTH;
  int SCREEN_HEIGHT;
  bool quit;
  display(){SCREEN_WIDTH = 400; SCREEN_HEIGHT = 400;};
};

keys key(SDL_Event e, game* gm);

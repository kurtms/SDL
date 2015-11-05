#include "window.h"
#ifndef GAME_H
  #define GAME_H
  #include "game.h"
#endif // GAME_H

keys key(SDL_Event e, game* gm)
{
  SDL_Keycode k = e.key.keysym.sym;
  if(k == SDLK_UP)
  {
    up_updateBoard(gm);
    return up;
  }
  if(k == SDLK_DOWN)
  {
    down_updateBoard(gm);
    return down;
  }
  if(k == SDLK_LEFT)
  {
    left_updateBoard(gm);
    return left;
  }
  if(k == SDLK_RIGHT)
  {
    right_updateBoard(gm);
    return right;
  }
  if(k == SDLK_SPACE)
  {
    key(bestMove(gm), gm);
    return best;
  }
  return other;
}

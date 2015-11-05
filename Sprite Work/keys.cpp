#ifndef SDL_H
  #define SDL_H
  #include "SDL_lib.h"
#endif
#ifndef KEYS_H
  #define KEYS_H
  #include "keys.h"
#endif
#include <iostream>
using namespace std;

void keys(SDL_Keycode key, SDL_Rect* sprite, SDL_Rect* dest, SDL_Texture* spriteSheet)
{
  if(key == SDLK_DOWN)
  {
    sprite->x = 56; sprite->y = 40;
    dest->y += 15;
    SDL_RenderClear(render);
    SDL_RenderCopy(render, spriteSheet, sprite, dest);
    SDL_RenderPresent(render);
  }
  if(key == SDLK_UP)
  {
    sprite->x = 56; sprite->y = 8;
    dest->y -= 15;
  }
  if(key == SDLK_RIGHT)
  {
    sprite->x = 56; sprite->y = 105;
    dest->x += 15;
  }
  if(key == SDLK_LEFT)
  {
    sprite->x = 56; sprite->y = 72;
    dest->x -= 15;
  }
}



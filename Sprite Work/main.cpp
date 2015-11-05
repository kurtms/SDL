#include "SDL_lib.h"
#include <iostream>
using namespace std;

void comRender(SDL_Rect* sprite, SDL_Rect* dest)
{
  SDL_Delay(50);
  SDL_RenderClear(render);
  SDL_RenderCopy(render, background, NULL, NULL);
  SDL_RenderCopy(render, spriteSheet, sprite, dest);
  SDL_RenderPresent(render);
}

void comRender_NODELAY(SDL_Rect* sprite, SDL_Rect* dest)
{
  SDL_RenderClear(render);
  SDL_RenderCopy(render, background, NULL, NULL);
  SDL_RenderCopy(render, spriteSheet, sprite, dest);
  SDL_RenderPresent(render);
}

void keys(SDL_Keycode key, SDL_Rect* sprite, SDL_Rect* dest)
{
  if(key == SDLK_DOWN)
  {
    if(sprite->x != 56 && sprite->y != 40)
    {
      sprite->x = 56; sprite->y = 40;
      comRender_NODELAY(sprite, dest);
      return;
    }
    sprite->x = 79; sprite->y = 40;
    dest->y += 5; // 15
    comRender(sprite, dest);
    sprite->x = 101;
    dest->y += 5;
    comRender(sprite, dest);
    sprite->x = 56;
    dest->y+= 6;
    comRender(sprite, dest);
    SDL_FlushEvents(0, SDL_TRUE);
  }
  if(key == SDLK_UP)
  {
    if(sprite->x != 55 && sprite->y != 8)
    {
      sprite->x = 55; sprite->y = 8;
      comRender_NODELAY(sprite, dest);
      return;
    }
    sprite->x = 99; sprite->y = 8;
    dest->y -= 5;
    comRender(sprite, dest);
    sprite->x = 77;
    dest->y -= 5;
    comRender(sprite, dest);
    sprite->x = 55;
    dest->y -= 6;
    comRender(sprite, dest);
    SDL_FlushEvents(0, SDL_TRUE);
  }
  if(key == SDLK_RIGHT)
  {
    if(sprite->x != 59 && sprite->y != 105)
    {
      sprite->x = 58; sprite->y = 105;
      comRender_NODELAY(sprite, dest);
      return;
    }
    sprite->x = 101; sprite->y = 105;
    dest->x += 5;
    comRender(sprite, dest);
    sprite->x = 80;
    dest->x += 5;
    comRender(sprite, dest);
    sprite->x = 59;
    dest->x += 6;
    comRender(sprite, dest);
    SDL_FlushEvents(0, SDL_TRUE);
  }
  if(key == SDLK_LEFT)
  {
    if(sprite->x != 58 && sprite->y != 74)
    {
      sprite->x = 58; sprite->y = 74;
      comRender_NODELAY(sprite, dest);
      return;
    }
    sprite->x = 81; sprite->y = 74;
    dest->x -= 5;
    comRender(sprite, dest);
    sprite->x = 102;
    dest->x -= 5;
    comRender(sprite, dest);
    sprite->x = 58;
    dest->x -= 6;
    comRender(sprite, dest);
    SDL_FlushEvents(SDL_KEYDOWN, SDL_KEYDOWN);
  }
}

int main(int argc, char* arg[])
{
  start();
  load();
  SDL_Rect sprite; SDL_Rect dest;
  sprite.x = 56; sprite.y = 40; sprite.w = 20; sprite.h = 30;
  dest.x = 0; dest.y = 0; dest.w = 20; dest.h = 30;
  SDL_RenderCopy(render, background, NULL, NULL);
  SDL_RenderCopy(render, spriteSheet, &sprite, &dest);
  while(!quit)
  {
    if(e.type == SDL_QUIT)
    {
      quit = true;
    } // if window is exited
    SDL_RenderPresent(render); // update Screen
    SDL_Delay(10); // keeps CPU and framerate down
    while(SDL_PollEvent(&e))
    {
      if(e.type == SDL_KEYDOWN)
      {
        keys(e.key.keysym.sym, &sprite, &dest); // interpret each keypress
      }
    }
  }
  close();
  return 0;
}


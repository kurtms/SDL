#include <SDL.h>
#ifndef GAME_H
  #define GAME_H
  #include "game.h"
#endif // GAME_H
#ifndef WINDOW_H
  #define WINDOW_H
  #include "window.h"
#endif // WINDOW_H
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
  SDL_Init(SDL_INIT_VIDEO);
  srand(time(NULL));
  display* dsp = new display();
  dsp->window = SDL_CreateWindow("2048", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, dsp->SCREEN_WIDTH, dsp->SCREEN_HEIGHT, 0);
  SDL_Surface* icon = SDL_LoadBMP("tiles/windowIcon.bmp");
  SDL_SetWindowIcon(dsp->window, icon);
  game* gm = new game;
  gm->window = SDL_GetWindowSurface(dsp->window);
  initialize(gm);
  printBoard(gm);
  SDL_UpdateWindowSurface(dsp->window);
  while(!dsp->quit)
  {
    SDL_Delay(70);
    while(SDL_PollEvent(&dsp->e))
    {
      SDL_Delay(1);
      if(dsp->e.type == SDL_QUIT)
      {
        dsp->quit = true;
        break;
      }
      if(dsp->e.type == SDL_KEYDOWN)
      {
        // dsp->e.key.keysym.sym = SDLK_SPACE;
        if(key(dsp->e, gm) != other)
        {
          newPiece(gm);
          printBoard(gm);
          SDL_UpdateWindowSurface(dsp->window);
          if(gameLost(gm))
          {
            SDL_Delay(500);
            SDL_Rect dest;
            dest.w = 80;
            dest.h = 80;
            dest.x = 0;
            dest.y = 0;
            for(int y = 0; y < 5; y++)
            {
              dest.x = 0;
              for(int x = 0; x < 5; x++)
              {
                SDL_BlitSurface(gm->game_over, &dest, gm->window, &dest);
                SDL_UpdateWindowSurface(dsp->window);
                SDL_Delay(50);
                dest.x += 80;
              }
              dest.y += 80;
            }
            SDL_BlitSurface(gm->game_over, NULL, gm->window, NULL);
            SDL_UpdateWindowSurface(dsp->window);
            while(!dsp->quit)
            {
              SDL_Delay(70);
              while(SDL_PollEvent(&dsp->e))
              {
                if(dsp->e.type == SDL_QUIT)
                {
                  delete dsp;
                  delete gm;
                  SDL_Quit();
                  return 0;
                }
              }
            }
          }
        }
      }
    }
  }
  delete dsp;
  delete gm;
  SDL_Quit();
  return 0;
}

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
#include <math.h>

using namespace std;

int main(int argc, char* argv[])
{
  SDL_Init(SDL_INIT_VIDEO);
  srand(time(NULL));
  display* dsp = new display();
  dsp->window = SDL_CreateWindow("2048", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, 0);
  int highestDeg = 0, gameNum = 1;
  bool highScore = false;
  game* gm = new game;
  gm->window = SDL_GetWindowSurface(dsp->window);
  initialize(gm);
  while(1)
  {
    while(!dsp->quit)
    {
      while(1)
      {
        dsp->e.key.keysym.sym = SDLK_SPACE;
        key(dsp->e, gm);
        newPiece(gm);
        if(gameLost(gm))
        {
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
              dest.x += 80;
            }
            dest.y += 80;
          }
          for(int y = 0; y < 5; y++)
          {
            for(int x = 0; x < 5; x++)
            {
              if(gm->board[x][y]->deg > highestDeg)
              {
                highestDeg = gm->board[x][y]->deg;
                highScore = true;
              }
            }
          }
          if(1) //highScore)
          {
            cout << "Game " << gameNum << ": " << pow(2,highestDeg) << endl;
            dsp->quit = true;
            highScore = false;
            break;
          }
        }
      }
    }
    for(int y = 0; y < 5; y++)
    {
      for(int x = 0; x < 5; x++)
      {
        gm->board[x][y]->deg = 0;
      }
    }
  dsp->quit = false;
  gameNum++;
  }
  delete gm;
  delete dsp;
  SDL_Quit();
  return 0;
}

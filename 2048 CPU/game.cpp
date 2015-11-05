#ifndef GAME_H
  #define GAME_H
  #include "game.h"
#endif // GAME_H
#include <iostream>
#include "math.h"
#include <SDL.h>
#include <cstdlib>

using namespace std;

SDL_Event bestMove(game* gm)
{
  int hDeg = 0;
  SDL_Event dir;
  dir.key.keysym.sym = SDLK_UP;
  for(int y = 0; y < 5; y++)
  {
    for(int x = 0; x < 5; x++)
    {
      if(y > 0 && gm->board[x][y]->deg == gm->board[x][y-1]->deg && gm->board[x][y]->deg > hDeg) // check up match
      {
        hDeg = gm->board[x][y]->deg;
        dir.key.keysym.sym = SDLK_UP;
      }
      if(y < 4 && gm->board[x][y]->deg == gm->board[x][y+1]->deg && gm->board[x][y]->deg > hDeg) // check down match
      {
        hDeg = gm->board[x][y]->deg;
        dir.key.keysym.sym = SDLK_DOWN;
      }
      if(x > 0 && gm->board[x][y]->deg == gm->board[x-1][y]->deg && gm->board[x][y]->deg > hDeg) // check left match
      {
        hDeg = gm->board[x][y]->deg;
        dir.key.keysym.sym = SDLK_LEFT;
      }
      if(x < 4 && gm->board[x][y]->deg == gm->board[x+1][y]->deg && gm->board[x][y]->deg > hDeg) // check right match
      {
        hDeg = gm->board[x][y]->deg;
        dir.key.keysym.sym = SDLK_RIGHT;
      }
    }
  }
  return dir;
}

void initialize(game* gm)
{
  gm->tile_default = SDL_LoadBMP("tiles/default.bmp");
  gm->tile_2 = SDL_LoadBMP("tiles/2.bmp");
  gm->tile_4 = SDL_LoadBMP("tiles/4.bmp");
  gm->tile_8 = SDL_LoadBMP("tiles/8.bmp");
  gm->tile_16 = SDL_LoadBMP("tiles/16.bmp");
  gm->tile_32 = SDL_LoadBMP("tiles/32.bmp");
  gm->tile_64 = SDL_LoadBMP("tiles/64.bmp");
  gm->tile_128 = SDL_LoadBMP("tiles/128.bmp");
  gm->tile_256 = SDL_LoadBMP("tiles/256.bmp");
  gm->tile_512 = SDL_LoadBMP("tiles/512.bmp");
  gm->tile_1024 = SDL_LoadBMP("tiles/1024.bmp");
  gm->tile_2048 = SDL_LoadBMP("tiles/2048.bmp");
  gm->game_over = SDL_LoadBMP("tiles/game_over.bmp");
  gm->board = new number**[5];
  for(int i = 0; i < 5; i++)
  {
    gm->board[i] = new number*[5];
  }
  for(int i = 0; i < 5; i++)
  {
    for(int j = 0; j < 5; j++)
    {
      gm->board[i][j] = new number(i, j);
    }
  }
  gm->board[1][1]->deg++;
  gm->board[2][2]->deg++;
  //printBoard(gm);
}

bool gameLost(game* g)
{
  for(int x = 0; x < 5; x++)
  {
    for(int y = 0; y < 5; y++)
    {
      if(g->board[x][y]->deg == 0)
      {
        return false; // viable moves
      }
      if(y < 4)
      {
        if(g->board[x][y]->deg == g->board[x][y+1]->deg)
        {
          return false; // viable moves
        }
      }
      if(x < 4)
      {
        if(g->board[x][y]->deg == g->board[x+1][y]->deg)
        {
          return false; // viable moves
        }
      }
    }
  }
  return true; // game is lost
}

void printBoard(game* g)
{
  SDL_FillRect(g->window, NULL, 100000);
  SDL_Rect dest;
  dest.h = 80;
  dest.w = 80;
  dest.x = 0;
  dest.y = 0;
  for(int y = 0; y < 5; y++)
  {
    dest.x = 0;
    for(int x = 0; x < 5; x++)
    {
      switch(g->board[x][y]->deg)
      {
      case(1):
        SDL_BlitSurface(g->tile_2, NULL, g->window, &dest);
        break;
      case(2):
        SDL_BlitSurface(g->tile_4, NULL, g->window, &dest);
        break;
      case(3):
        SDL_BlitSurface(g->tile_8, NULL, g->window, &dest);
        break;
      case(4):
        SDL_BlitSurface(g->tile_16, NULL, g->window, &dest);
        break;
      case(5):
        SDL_BlitSurface(g->tile_32, NULL, g->window, &dest);
        break;
      case(6):
        SDL_BlitSurface(g->tile_64, NULL, g->window, &dest);
        break;
      case(7):
        SDL_BlitSurface(g->tile_128, NULL, g->window, &dest);
        break;
      case(8):
        SDL_BlitSurface(g->tile_256, NULL, g->window, &dest);
        break;
      case(9):
        SDL_BlitSurface(g->tile_512, NULL, g->window, &dest);
        break;
      case(10):
        SDL_BlitSurface(g->tile_1024, NULL, g->window, &dest);
        break;
      case(11):
        SDL_BlitSurface(g->tile_2048, NULL, g->window, &dest);
        break;
      case(0):
        break;
      default:
        SDL_BlitSurface(g->tile_default, NULL, g->window, &dest);
        break;
      }
      dest.x += 80;
    }
    dest.y += 80;
  }
}

void newPiece(game* g)
{
  bool space;
  for(int x = 0; x < 5; x++)
  {
    for(int y = 0; y < 5; y++)
    {
      if(g->board[x][y]->deg == 0)
      {
        space = true;
      }
    }
  }
  if(!space)
  {
    return;
  }
  while(1)
  {
    for(int y = 0; y < 5; y++)
    {
      for(int x = 0; x < 5; x++)
      {
        if(rand() % 20 == 0 && g->board[x][y]->deg == 0)
        {
          g->board[x][y]->deg++;
          if(rand() % 4 == 0)
          {
            g->board[x][y]->deg++;
          }
          return;
        }
      }
    }
  }
}

void up_updateBoard(game* g)
{
  for(int x = 0; x < 5; x++)
  {
    for(int y = 0; y < 5; y++)
    {
      if(g->board[x][y]->deg == 0)
      {
        for(int i = 1; y+i < 5; i++)
        {
          if(g->board[x][y+i]->deg != 0)
          {
            g->board[x][y]->deg = g->board[x][y+i]->deg;
            g->board[x][y+i]->deg = 0;
            break;
          }
        }
      }
      if(g->board[x][y]->deg != 0)
      {
        for(int i = 1; y+i < 5; i++)
        {
          if(g->board[x][y+i]->deg == g->board[x][y]->deg)
          {
            g->board[x][y]->deg++;
            g->board[x][y+i]->deg = 0;
            break;
          }
          if(g->board[x][y+i]->deg != 0)
          {
            break;
          }
        }
      }
    }
  }
}

void down_updateBoard(game* g)
{
  for(int x = 0; x < 5; x++)
  {
    for(int y = 4; y > -1; y--)
    {
      if(g->board[x][y]->deg == 0)
      {
        for(int i = -1; y+i > -1; i--)
        {
          if(g->board[x][y+i]->deg != 0)
          {
            g->board[x][y]->deg = g->board[x][y+i]->deg;
            g->board[x][y+i]->deg = 0;
            break;
          }
        }
      }
      if(g->board[x][y]->deg != 0)
      {
        for(int i = -1; y+i > -1; i--)
        {
          if(g->board[x][y+i]->deg == g->board[x][y]->deg)
          {
            g->board[x][y]->deg++;
            g->board[x][y+i]->deg = 0;
            break;
          }
          if(g->board[x][y+i]->deg != 0)
          {
            break;
          }
        }
      }
    }
  }
}

void left_updateBoard(game* g)
{
  for(int y = 0; y < 5; y++)
  {
    for(int x = 0; x < 5; x++)
    {
      if(g->board[x][y]->deg == 0)
      {
        for(int i = 1; x+i < 5; i++)
        {
          if(g->board[x+i][y]->deg != 0)
          {
            g->board[x][y]->deg = g->board[x+i][y]->deg;
            g->board[x+i][y]->deg = 0;
            break;
          }
        }
      }
      if(g->board[x][y]->deg != 0)
      {
        for(int i = 1; x+i < 5; i++)
        {
          if(g->board[x+i][y]->deg == g->board[x][y]->deg)
          {
            g->board[x][y]->deg++;
            g->board[x+i][y]->deg = 0;
            break;
          }
          if(g->board[x+i][y]->deg != 0)
          {
            break;
          }
        }
      }
    }
  }
}

void right_updateBoard(game* g)
{
  for(int y = 0; y < 5; y++)
  {
    for(int x = 4; x > -1; x--)
    {
      if(g->board[x][y]->deg == 0)
      {
        for(int i = -1; x+i > -1; i--)
        {
          if(g->board[x+i][y]->deg != 0)
          {
            g->board[x][y]->deg = g->board[x+i][y]->deg;
            g->board[x+i][y]->deg = 0;
            break;
          }
        }
      }
      if(g->board[x][y]->deg != 0)
      {
        for(int i = -1; x+i > -1; i--)
        {
          if(g->board[x+i][y]->deg == g->board[x][y]->deg)
          {
            g->board[x][y]->deg++;
            g->board[x+i][y]->deg = 0;
            break;
          }
          if(g->board[x+i][y]->deg != 0)
          {
            break;
          }
        }
      }
    }
  }
}

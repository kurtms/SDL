#include <SDL.h>
#include <iostream>
#ifndef GAME_H
  #define GAME_H
  #include "game.h"
#endif // GAME_H
#ifndef KEY_H
  #define KEY_H
  #include "key.h"
#endif // KEY_H

using namespace std;

void movement(SDL_Event e, char** map, game* gam, int &x, int &y)
{
  if(e.type == SDL_KEYDOWN)
	{
		switch(e.key.keysym.sym)
		{
			case(SDLK_UP):
				if(y > 0 && (map[x][y-1] != ' ' && map[x][y-1] != 'W'))
        {
          y--;
          break;
        }
				break;
			case(SDLK_DOWN):
        if(y < my-1 && (map[x][y+1] != ' ' && map[x][y+1] != 'W'))
        {
          y++;
          break;
        }
				break;
			case(SDLK_LEFT):
        if(x > 0 && (map[x-1][y] != ' ' && map[x-1][y] != 'W'))
        {
          x--;
          break;
        }
			  break;
		  case(SDLK_RIGHT):
        if(x < mx-2 && (map[x+1][y] != ' ' && map[x+1][y] != 'W'))
        {
          x++;
          break;
        }
				break;
			case(SDLK_s):
        gam->x = x;
        gam->y = y;
        //gam->curMap = map->mapName;
        //printMenu(gam);
        break;
      default:
        break;
		}
	}
}

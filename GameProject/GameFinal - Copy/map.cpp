#include <sdl.h>
#include "game.h"
#ifndef PLAYER_H
  #define PLAYER_H
  #include "player.h"
#endif // PLAYER_H
#include "map.h"

using namespace std;

void printRoute(int x, int y, char** map, int mx, int my, player* plyr, SDL_Surface* screen)
{
  SDL_FillRect(screen, NULL, 0);
  SDL_Surface* route = SDL_LoadBMP("route.bmp");
	SDL_Rect dstrect; dstrect.x = 0; dstrect.y = 0; dstrect.w = 16; dstrect.h = 16;
  SDL_Rect srcrect; srcrect.x = 103; srcrect.y = 1; srcrect.w = 16;	srcrect.h = 16;
	SDL_Rect chrect; chrect.x = 392; chrect.y = 103; chrect.w = 16; chrect.h = 16;
	SDL_Rect grsrect; grsrect.x = 120; grsrect.y = 1; grsrect.w = 16; grsrect.h = 16;
	SDL_Rect wtrrect; wtrrect.x = 188; wtrrect.y = 18; wtrrect.w = 16; wtrrect.h = 16;
	SDL_Rect doorrect; doorrect.x = 358; doorrect.y = 290; doorrect.w = 16; doorrect.h = 16;
  int cx_s = x, cy_s = y;
  if(y - 10 < 0)
  {
    cy_s = 10;
  }
  else
    if(y + 10 > my)
    {
      cy_s = my - 10;
    }
  if(x - 10 < 0)
  {
    cx_s = 10;
  }
  else
    if(x + 10 > mx)
    {
      cx_s = mx - 10;
    }
  for(int cy = cy_s - 10; cy < cy_s + 10; cy++) // camera y control
  {
    for(int cx = cx_s - 10; cx < cx_s + 10; cx++) // camera x control
    {
      if(cx == x && cy == y)
      {
			  SDL_BlitSurface(route, &chrect, screen, &dstrect);
				dstrect.x += 16;
      } // blit character surface
      else
      {
        switch(map[cx][cy])
        {
				case('P'):
				  SDL_BlitSurface(route, &srcrect, screen, &dstrect);
					break;
        case('G'):
	        SDL_BlitSurface(route, &grsrect, screen, &dstrect);
	        break;
        case('B'):
	        SDL_BlitSurface(route, &grsrect, screen, &dstrect);
					break;
        case('W'):
	        SDL_BlitSurface(route, &wtrrect, screen, &dstrect);
	        break;
				case('0'):
	        SDL_BlitSurface(route, &doorrect, screen, &dstrect);
					break;
				case('1'):
	        SDL_BlitSurface(route, &doorrect, screen, &dstrect);
					break;
				case('2'):
	        SDL_BlitSurface(route, &doorrect, screen, &dstrect);
					break;
				default:
				  break; // for void blocks
        }
				dstrect.x += 16;
      } // blit non character surface
		}
		dstrect.y += 16;
		dstrect.x = 0;
  }
}

char** fileToMap(mapData* mapData)
{
  char** map = new char*[100];
  for(int i = 0; i < 100; ++i)
  {
    map[i] = new char[100];
    for(int j = 0; j < 100; ++j)
    {
      map[i][j] = ' ';
    }
  }
  ifstream file (mapData->mapName.c_str());
  int x = 0, y = 0, n;
  char z;
  string info, token;
  while(getline(file, info, ' '))
  {
    if(info == "\n")
    {
      break;
    }
    adjMap* adj;
    adj = new adjMap;
    n = atoi(info.c_str());
    getline(file, info, ' ');
    adj->mapName = info;
    getline(file, info, ' ');
    adj->x = atoi(info.c_str());
    getline(file, info, ' ');
    adj->y = atoi(info.c_str());
    mapData->adjList[n] = adj;
  }
  getline(file, info);
  while(file.get(z))
  {
    if(z == '\n')
    {
      y++;
      x = 0;
      if(!(file.get(z)))
      {
        break;
      }
    }
    *(*(map + x) + y) = z;
    x++;
  } // sets map array as file
  file.close();
  return map;
}

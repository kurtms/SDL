#include <sdl.h>
#include <SDL_image.h>
#include "game.h"
#ifndef PLAYER_H
  #define PLAYER_H
  #include "player.h"
#endif // PLAYER_H
#include "map.h"

using namespace std;

void printRoute(int x, int y, char** map, int mx, int my, player* plyr, SDL_Surface* screen, SDL_Event e, SDL_Renderer* render)
{
  SDL_FillRect(screen, NULL, 0);

  // start of sprite clipping
  SDL_Surface* route = SDL_LoadBMP("route.bmp");
  SDL_Texture* sprite = SDL_CreateTextureFromSurface(render, IMG_Load("spriteSheet.png"));
	SDL_Rect dstrect; dstrect.x = 0; dstrect.y = 0; dstrect.w = 16; dstrect.h = 16;
  SDL_Rect srcrect; srcrect.x = 103; srcrect.y = 1; srcrect.w = 16;	srcrect.h = 16;
	SDL_Rect grsrect; grsrect.x = 120; grsrect.y = 1; grsrect.w = 16; grsrect.h = 16;
	SDL_Rect wtrrect; wtrrect.x = 188; wtrrect.y = 18; wtrrect.w = 16; wtrrect.h = 16;
	SDL_Rect doorrect; doorrect.x = 358; doorrect.y = 290; doorrect.w = 16; doorrect.h = 16;
  SDL_Rect treasrect; treasrect.x = 120; treasrect.y = 35; treasrect.w = 16; treasrect.h = 16;
  SDL_Rect endrect; endrect.x = 18; endrect.y = 562; endrect.w = 16; endrect.h = 16;

  SDL_Rect uprect; uprect.x = 55; uprect.y = 9; uprect.w = 32; uprect.h = 32;
  SDL_Rect downrect; downrect.x = 55; downrect.y = 40; downrect.w = 30; downrect.h = 30;
  SDL_Rect leftrect; leftrect.x = 34; leftrect.y = 2; leftrect.w = 30; leftrect.h = 30;
  SDL_Rect rtrect; rtrect.x = 83; rtrect.y = 2; rtrect.w = 30; rtrect.h = 30;

  SDL_Rect spriteM[4];
  spriteM[K_UP] = uprect;
  spriteM[K_DOWN] = downrect;
  spriteM[K_RIGHT] = rtrect;
  spriteM[K_LEFT] = leftrect;
  // end of sprite clipping

  int sx = SCREEN_WIDTH/16 - 10;
  int sy = SCREEN_HEIGHT/16 - 10;
  int cx_s = x, cy_s = y;
  if(y - sy < 0)
  {
    cy_s = sy;
  }
  else
    if(y + sy > my)
    {
      cy_s = my - sy;
    }
  if(x - sx < 0)
  {
    cx_s = sx;
  }
  else
    if(x + sx > mx)
    {
      cx_s = mx - sx;
    }
  for(int cy = cy_s - sy; cy < cy_s + sy; cy++) // camera y control
  {
    for(int cx = cx_s - sx; cx < cx_s + sx; cx++) // camera x control
    {
      if(cx == x && cy == y)
      {
        dstrect.h = 30; dstrect.w = 30;
			  switch(e.key.keysym.sym)
        {
				case(SDLK_UP):
	        SDL_RenderCopy(render, sprite, &spriteM[K_UP], &dstrect);
	        break;
				case(SDLK_DOWN):
	        SDL_RenderCopy(render, sprite, &spriteM[K_DOWN], &dstrect);
	        break;
				case(SDLK_RIGHT):
	        SDL_RenderCopy(render, sprite, &spriteM[K_RIGHT], &dstrect);
	        break;
				case(SDLK_LEFT):
	        SDL_RenderCopy(render, sprite, &spriteM[K_LEFT], &dstrect);
	        break;
        default:
	        SDL_RenderCopy(render, sprite, &spriteM[K_DOWN], &dstrect);
	        break;
        }
				dstrect.w = 16; dstrect.h = 16;
      } // blit character surface
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
        case('T'):
				  SDL_BlitSurface(route, &treasrect, screen, &dstrect);
					break;
        case('A'):
	        SDL_BlitSurface(route, &endrect, screen, &dstrect);
					break;
 				default:
				  break; // for void blocks
        }
				dstrect.x += 16;
       // blit non character surface
		}
		dstrect.y += 16;
		dstrect.x = 0;
  }
  SDL_FreeSurface(route);
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

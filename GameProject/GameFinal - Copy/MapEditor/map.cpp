#include <sdl.h>
#include "map.h"

const int SCREEN_HEIGHT = 700;
const int SCREEN_WIDTH = 700;
int m_y = 50, m_x = 50;
using namespace std;

int main(int argc, char* args[])
{
  string mapName;
  cout << "Enter map name to edit: ";
  cin >> mapName;
  mapData* mapDat = new mapData();
  mapDat->mapName = mapName;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* win = SDL_CreateWindow("Map Editor", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  SDL_Surface* icon = SDL_LoadBMP("windowIcon.bmp");
  SDL_SetWindowIcon(win, icon);
  SDL_Surface* screen = SDL_GetWindowSurface(win);
  SDL_FillRect(screen, NULL, 0);
  SDL_UpdateWindowSurface(win);
  SDL_Surface* route = SDL_LoadBMP("route.bmp");

  // start of sprite clipping
	SDL_Rect dstrect; dstrect.x = 0; dstrect.y = 0; dstrect.w = 16; dstrect.h = 16;
  SDL_Rect srcrect; srcrect.x = 103; srcrect.y = 1; srcrect.w = 16;	srcrect.h = 16;
	SDL_Rect grsrect; grsrect.x = 120; grsrect.y = 1; grsrect.w = 16; grsrect.h = 16;
	SDL_Rect wtrrect; wtrrect.x = 188; wtrrect.y = 18; wtrrect.w = 16; wtrrect.h = 16;
	SDL_Rect doorrect; doorrect.x = 358; doorrect.y = 290; doorrect.w = 16; doorrect.h = 16;
  // end of sprite clipping

  SDL_Event e;
  char** map;
  bool quit = false;
  int framerate = 0;
  while(!quit)
  {
    dstrect.x = 0; dstrect.y = 0;
    map = fileToMap(mapDat);
    SDL_PollEvent(&e);
  	if(e.type == SDL_QUIT)
    {
			quit = true;
    }
    if(framerate == 2000)
		{
			SDL_UpdateWindowSurface(win);
      SDL_FillRect(screen, NULL, 0);
			framerate = 0;
		}
	  framerate++;
    for(int cy = 0; cy <= m_y; cy++) // camera y control
		{
      for(int cx = 0; cx <= m_x; cx++) // camera x control
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
      dstrect.y += 16;
      dstrect.x =0;
	  }
    for(int i = 0; i < 100; ++i)
    {
      delete [] map[i];
    } // delete map (memory leak)
    delete [] map;
  }
  return 0;
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
  string fileLoc = "../../../bin/Debug/maps/";
  string fileType = ".txt";
	fileLoc = fileLoc + mapData->mapName.c_str() + fileType;
  ifstream file (fileLoc.c_str());
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

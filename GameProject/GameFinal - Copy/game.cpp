#ifndef KEY_H
  #define KEY_H
  #include "key.h"
#endif // KEY_H
#ifndef GAME_H
  #define GAME_H
  #include "game.h"
#endif // GAME_H
#include "battle.h"
#ifndef MAP_H
  #define MAP_H
  #include "map.h"
#endif // MAP_H
#include "menu.h"
#include "save.h"

int main(int argc, char* args[])
{
  int x = 0, y = 0;
  game* gam;
  player* plyr = new player("Kurt", 100);
  char** map;
  mapData* currentMap = new mapData;
//  cout << "1. New Game" << endl << "2. Load Game" << endl;
  bool quit = false;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  SDL_Surface* icon = SDL_LoadBMP("windowIcon.bmp");
  SDL_SetWindowIcon(window, icon);
  SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
  SDL_FillRect(screenSurface, NULL, 0);
  SDL_Event e;
  if(1) // needs arguments for when file etc.
  {
    gam = load("game.sav");
    currentMap->mapName = "maps/map0_1.txt"; //gam->curMap;
    plyr = gam->plyr;
    x = gam->x;
    y = gam->y;
  }
  else
  {
    cout << "No save file given." <<endl;
    return 0;
  }
  map = fileToMap(currentMap);
  gam = new game(x, y, currentMap->mapName, &*plyr);
  char i;
  srand(time(NULL));
	printRoute(x, y, map, mx, my, plyr, screenSurface);
  SDL_UpdateWindowSurface(window);
  bool timeKeeper = false;
  while(!quit)
  {
    if(!timeKeeper)
		{
		  printRoute(x, y, map, mx, my, plyr, screenSurface);
      SDL_UpdateWindowSurface(window);
			timeKeeper = true; // keeps from updating too frequently (need framerate keeper)
		}
		while(SDL_PollEvent(&e))
  	{
  		if(e.type == SDL_QUIT)
			{
				quit = true;
			}
			if(e.type == SDL_KEYDOWN)
			{
        timeKeeper = false;
        movement(e, map, gam, x, y);
		    printRoute(x, y, map, mx, my, plyr, screenSurface);
        SDL_UpdateWindowSurface(window);
    		if(map[x][y] == 'T')
	      {
	        cout << "You found one potion!" << endl << "Pick it up?" << endl << "Y/N" << endl;
  	      cin >> i;
	        if(i == 'y')
	        {
	          plyr->inv->potion++;
	        }
  	    } // treasure, needs an array (?) to see if found or not
	      if(map[x][y] == 'G')
	      {
 				  if(rand() % 7 == 0) // theoretical 1/7 chance
	  			{
      	    if(battle(plyr))
    	      {
      	      quit = true;
      	    }
    	    }
   	    } // random battle encounter
    	  if(map[x][y] == 'B')
  	    {
  				if(battle(plyr))
	  			{
  	        quit = true;
    	    }
  			} // automatic battle
	  		if(map[x][y] == 'A')
        {
          SDL_FillRect(screenSurface, NULL, 0);
          SDL_Surface* endGame = SDL_LoadBMP("endGameScreen - win.bmp");
				  SDL_BlitSurface(endGame, NULL, screenSurface, NULL);
          SDL_UpdateWindowSurface(window);
          while(1)
					{
            SDL_PollEvent(&e);
						if(e.type == SDL_QUIT)
						{
							break;
						}
					}
          quit = true;
          break;
        }
        if(0 <= (int)(map[x][y]) - 48 && (int)(map[x][y]) - 48 < 10)
        {
          int door = (int)(map[x][y]) - 48;
          string mapName;
          mapName = currentMap->adjList[door]->mapName;
          x = currentMap->adjList[door]->x;
          y = currentMap->adjList[door]->y;
          delete currentMap;
          mapData* currentMap = new mapData;
          currentMap->mapName = mapName;
          map = fileToMap(currentMap);
        }
	  	}
	  }
  }
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}

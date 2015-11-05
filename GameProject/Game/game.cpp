#include <SDL.h>
#include <iostream>
#include "key.h"

const int SCREEN_HEIGHT = 367;
const int SCREEN_WIDTH = 400;

using namespace std;

int main(int argc, char* args[])
{
  bool quit = false;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
//  SDL_FillRect(screenSurface, NULL, 0);
  SDL_Surface* img = SDL_LoadBMP("forest_overhead.bmp");
  if(img == NULL)
  	cout << "Failed to load image: " << SDL_GetError() << endl;
  SDL_BlitSurface(img, NULL, screenSurface, NULL);
  SDL_UpdateWindowSurface(window);
  SDL_Event e;
  while(!quit)
  {
    while(SDL_PollEvent(&e))
  	{
  		if(e.type == SDL_QUIT)
			{
				quit = true;
			}
			if(e.type == SDL_KEYDOWN)
			{
        movement(e);
			}
		}
  }
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}

#include <SDL.h>
#include <iostream>
#include "key.h"


const int SCREEN_HEIGHT = 540;
const int SCREEN_WIDTH = 720;

using namespace std;

void movement(SDL_Event e)
{
  if(e.type == SDL_KEYDOWN)
	{
		switch(e.key.keysym.sym)
		{
			case(SDLK_UP):
				cout << "Up" << endl;
				break;
			case(SDLK_DOWN):
				cout << "Down" << endl;
				break;
			case(SDLK_LEFT):
			  cout << "Left" << endl;
			  break;
		  case(SDLK_RIGHT):
	      cout << "Right" << endl;
	      break;
		}
	}
}

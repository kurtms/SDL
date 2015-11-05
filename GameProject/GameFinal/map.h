#include <iostream>
#include <fstream>
#include <cstdlib>

enum SDLK
{
	K_UP, K_DOWN, K_LEFT, K_RIGHT,
};

using namespace std;

class adjMap
{
public:
  int x, y;
  string mapName;
};

class mapData
{
public:
  adjMap* adjList[10];
  string mapName;
};

void printRoute(int x, int y, char** map, int mx, int my, player* plyr, SDL_Surface* screen, SDL_Event e, SDL_Renderer* render);

char** fileToMap(mapData* mapData);

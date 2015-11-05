#include <iostream>
#include <fstream>
#include <cstdlib>

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

void printRoute(int x, int y, char** map, int mx, int my, player* plyr, SDL_Surface* screen);

char** fileToMap(mapData* mapData);

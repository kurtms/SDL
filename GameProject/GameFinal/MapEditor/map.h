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

char** fileToMap(mapData* mapData);

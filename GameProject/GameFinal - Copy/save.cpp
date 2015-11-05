#ifndef PLAYER_H
  #define PLAYER_H
  #include "player.h"
#endif // PLAYER_H
#ifndef GAME_H
  #define GAME_H
  #include "game.h"
#endif // GAME_H
#include "save.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>

game* load(string fil)
{
  decrypt(fil.c_str());
  string mapNam, info;
  int x, y, ptn, hp;
  ifstream f ("decrypt.sav");
  // cout << "LOADING: " << fil << endl;
  getline(f, info, ' ');
  getline(f, info, ' ');
  mapNam = info;
  getline(f, info, ' ');
  getline(f, info, ' ');
  x = atoi(info.c_str());
  getline(f, info, ' ');
  getline(f, info, ' ');
  y = atoi(info.c_str());
  getline(f, info, ' ');
  getline(f, info, ' ');
  ptn = atoi(info.c_str());
  getline(f, info, ' ');
  getline(f, info);
  hp = atoi(info.c_str());
  encrypt("decrypt.sav");
  inventory* inv = new inventory(ptn);
  player* plyr = new player("Kurt", hp);
  plyr->inv = inv;
  game* gam = new game(x, y, mapNam, plyr);
  // cout << "File loaded." << endl;
  return gam;
}

void save(game* game)
{
  remove("game.sav");
  remove("decrypt.sav");
  ofstream out;
  out.open("decrypt.sav");
  out << "map: " << game->curMap
      << " x: " << game->x
      << " y: " << game->y
      << " ptn: " << game->plyr->inv->potion
      << " hp: " << game->plyr->hp;
  out.close();
  encrypt("decrypt.sav");
}

void encrypt(string fil)
{
  string line;
  char j;
  ifstream in (fil.c_str());
  ofstream out;
  out.open("game.sav");
  while(getline(in, line))
  {
    for(string::iterator i = line.begin(); i != line.end(); ++i)
    {
      j = (char)((int)*i + (int)'k');
      out << j;
    }
  }
  out.close();
  in.close();
  remove(fil.c_str());
}

void decrypt(string fil)
{
  string line;
  char j;
  ifstream in (fil.c_str());
  ofstream out;
  out.open("decrypt.sav");
  while(getline(in, line))
  {
    for(string::iterator i = line.begin(); i != line.end(); ++i)
    {
      j = (char)((int)*i - (int)('k'));
      out << j;
    }
  }
  out.close();
  in.close();
  remove(fil.c_str());
}

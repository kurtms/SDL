#include <SDL.h>

class number
{
public:
  int deg;
  int x, y;
  number(int locx, int locy){x = locx; y = locy; deg = 0;}
};

class game
{
public:
  SDL_Surface* window;
  SDL_Surface* tile_default;
  SDL_Surface* tile_2;
  SDL_Surface* tile_4;
  SDL_Surface* tile_8;
  SDL_Surface* tile_16;
  SDL_Surface* tile_32;
  SDL_Surface* tile_64;
  SDL_Surface* tile_128;
  SDL_Surface* tile_256;
  SDL_Surface* tile_512;
  SDL_Surface* tile_1024;
  SDL_Surface* tile_2048;
  SDL_Surface* game_over;
  number*** board;
};

SDL_Event bestMove(game* g);

bool gameLost(game* g);

void initialize(game* gm);

void printBoard(game* g);

void up_updateBoard(game* g);

void down_updateBoard(game* g);

void left_updateBoard(game* g);

void right_updateBoard(game* g);

void newPiece(game* g);

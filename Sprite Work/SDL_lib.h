#ifndef SDL_LIB_H
  #define SDL_LIB_H
#include <SDL.h>
#include <SDL_image.h>

static const char* name = "Sprite Practice";
static int SCREEN_HEIGHT = 320;
static int SCREEN_WIDTH = 384;

static bool quit = false;

static SDL_Window* window = NULL;
static SDL_Renderer* render = NULL;

static SDL_Surface* icon = IMG_Load("resources/icon.bmp");

static SDL_Texture* spriteSheet = NULL;
static SDL_Texture* routeSheet = NULL;
static SDL_Texture* background = NULL;

static SDL_Event e;

static void start()
{
  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_PNG);
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
  window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_SetWindowIcon(window, icon);
  SDL_FreeSurface(icon);
  SDL_SetRenderDrawColor(render, 0, 0, 0, 0xff);
}

static void close()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(render);
  SDL_DestroyTexture(spriteSheet);
  SDL_DestroyTexture(routeSheet);
  SDL_DestroyTexture(background);
  SDL_Quit();
  IMG_Quit();
}

static void load()
{
  background = SDL_CreateTextureFromSurface(render, IMG_Load("resources/background.png"));
  SDL_Surface* sSheet = IMG_Load("resources/spriteSheet.png");
  SDL_SetColorKey(sSheet, SDL_TRUE, SDL_MapRGB(sSheet->format, 0xff, 0xff, 0xff));
  spriteSheet = SDL_CreateTextureFromSurface(render, sSheet);
  routeSheet = SDL_CreateTextureFromSurface(render, IMG_Load("resources/routeSheet.png"));
}

#endif

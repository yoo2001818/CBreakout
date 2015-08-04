#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "CBreakoutConfig.h"
#include "CApp.h"

using namespace std;

int main() {
  SDL_Window * window = NULL;
  // init SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    cout << "Cannot initialize SDL: " << SDL_GetError() << endl;
    return false;
  }
  // init window
  if ((window = SDL_CreateWindow(
    APP_NAME,
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    APP_WIDTH, APP_HEIGHT, SDL_WINDOW_SHOWN)
  ) == NULL) {
    cout << "Window cannot be created: " << SDL_GetError() << endl;
    return false;
  }
  // init SDL_image
  int imgFlags = IMG_INIT_PNG;
  if(!(IMG_Init(imgFlags) & imgFlags)) {
    cout << "Cannot initialize SDL_image: " << SDL_GetError() << endl;
  }
  // init app
  CApp * app = new CApp(window);

  app->Init();
  app->Loop();
  app->Cleanup();

}

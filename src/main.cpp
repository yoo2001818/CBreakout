#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#define OGG_MUSIC
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include "CBreakoutConfig.h"
#include "CApp.h"

using namespace std;

int main(int argc, char *argv[]) {
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
  // init SDL_mixer
  int mixFlags = MIX_INIT_OGG;
  if(!(Mix_Init(mixFlags) & mixFlags)) {
    cout << "Cannot initialize SDL_mixer: " << Mix_GetError() << endl;
  }
  // init app
  try {
    CApp * app = new CApp(window);

    app->Init();
    app->Loop();
    app->Cleanup();
  } catch (char * e) {
    cout << e << SDL_GetError() << endl;
    return false;
  } catch (exception& e) {
    cout << e.what() << endl;
    return false;
  }
}

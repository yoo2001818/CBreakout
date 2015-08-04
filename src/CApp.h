#ifndef __CAPP_H__
#define __CAPP_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Utils.h"

class CApp {
public:
  SDL_Window * window;
  SDL_Renderer * renderer;
  bool isRunning;

  CApp(SDL_Window * window) throw();
  virtual ~CApp();

  void Init();
  void Loop();
  void Cleanup();

  // Should be removed
  SDL_Texture * testTexture;
  SDL_Rect rect;
};

#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#ifndef __CAPP_H__
#define __CAPP_H__

class CApp {
public:
  SDL_Window * window;
  SDL_Surface * screenSurface;
  bool isRunning;

  CApp(SDL_Window * window);
  virtual ~CApp();

  void Init();
  void Loop();
  void Cleanup();

  // Should be removed
  SDL_Surface * testSurface;
  SDL_Rect rect;
};

#endif

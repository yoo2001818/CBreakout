#ifndef __CAPP_H__
#define __CAPP_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Utils.h"
#include "CStage.h"

class CApp {
public:
  SDL_Window * window;
  SDL_Renderer * renderer;
  bool isRunning;

  CStage * stage;

  CApp(SDL_Window * window) throw();
  virtual ~CApp();

  void Init();
  void Loop();
  void Cleanup();

  static CApp * instance;
};

#endif

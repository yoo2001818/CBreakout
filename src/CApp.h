#ifndef __CAPP_H__
#define __CAPP_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "Utils.h"
#include "CStage.h"

extern Mix_Chunk * EFFECT_BOUNCE1;
extern Mix_Chunk * EFFECT_DROP;
extern Mix_Chunk * EFFECT_KILL[3];
extern Mix_Chunk * EFFECT_DAMAGE[3];
extern Mix_Chunk * EFFECT_SPLAT;
extern Mix_Chunk * EFFECT_REVIVE;
extern Mix_Chunk * EFFECT_ITEM;
extern Mix_Music * MUSIC;

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

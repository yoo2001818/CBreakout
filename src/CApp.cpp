#include "CApp.h"
#include "game/CTitleScene.h"
#include "game/CGameScene.h"
#include "CGraphics.h"

Mix_Chunk * EFFECT_BOUNCE1 = NULL;
Mix_Chunk * EFFECT_DROP = NULL;
Mix_Chunk * EFFECT_KILL[3];
Mix_Chunk * EFFECT_DAMAGE[3];
Mix_Chunk * EFFECT_SPLAT;
Mix_Chunk * EFFECT_REVIVE;
Mix_Music * MUSIC;

CApp * CApp::instance = NULL;

CApp::CApp(SDL_Window * window) throw() {
  CApp::instance = this;
  isRunning = true;
  this->window = window;
  renderer = SDL_CreateRenderer(window, -1, 0);
  if (renderer == NULL) {
    throw "Cannot create renderer";
  }
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024)==-1) {
    printf("Mix_OpenAudio: %s\n", Mix_GetError());
    exit(2);
  }
  stage = NULL;
}

CApp::~CApp() {
}

void CApp::Init() {
  // Sprite sheet. what?
  CGraphics::spriteSheet = new CTexture();
  CGraphics::spriteSheet->LoadFromFile(renderer, "res/sprite.png");
  CGraphics::spriteSheet->oneTimeUse = false;
  // Various audio stuff
  EFFECT_BOUNCE1 = Mix_LoadWAV("res/bounce1.ogg");
  EFFECT_DROP = Mix_LoadWAV("res/drop.ogg");
  EFFECT_DAMAGE[0] = Mix_LoadWAV("res/damage1.ogg");
  EFFECT_DAMAGE[1] = Mix_LoadWAV("res/damage2.ogg");
  EFFECT_DAMAGE[2] = Mix_LoadWAV("res/damage3.ogg");
  EFFECT_KILL[0] = Mix_LoadWAV("res/kill1.ogg");
  EFFECT_KILL[1] = Mix_LoadWAV("res/kill2.ogg");
  EFFECT_KILL[2] = Mix_LoadWAV("res/kill3.ogg");
  EFFECT_SPLAT = Mix_LoadWAV("res/splat.ogg");
  EFFECT_REVIVE = Mix_LoadWAV("res/revive.ogg");
  for(int i = 0; i < 3; ++i) {
    Mix_VolumeChunk(EFFECT_KILL[i], 64);
  }
  MUSIC = Mix_LoadMUS("res/bgm.ogg");
  // Load stuff we need to load, etc..
  stage = new CStage(this);
  stage->AddChild(new CTitleScene());
  //stage->AddChild(new CGameScene());
}

void CApp::Loop() {
  int time = SDL_GetTicks();
  while (isRunning) {
    // Event stage
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT) {
        // Just turn off the app
        isRunning = false;
      }
      stage->Event(&event);
    }
    // Update stage
    int currentTime = SDL_GetTicks();
    stage->Update(currentTime - time);
    // Render stage
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    stage->Render();
    SDL_RenderPresent(renderer);
    SDL_Delay(1000/60);
    time = currentTime;
  }
}

void CApp::Cleanup() {
  SDL_DestroyWindow(window);
  window = NULL;
  SDL_Quit();
}

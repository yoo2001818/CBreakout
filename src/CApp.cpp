#include "CApp.h"
#include "game/CTitleScene.h"
#include "game/CGameScene.h"

CApp * CApp::instance = NULL;

CApp::CApp(SDL_Window * window) throw() {
  CApp::instance = this;
  isRunning = true;
  this->window = window;
  renderer = SDL_CreateRenderer(window, -1, 0);
  if (renderer == NULL) {
    throw "Cannot create renderer";
  }
  stage = NULL;
}

CApp::~CApp() {
}

void CApp::Init() {
  // Load stuff we need to load, etc..
  stage = new CStage(this);
  stage->AddChild(new CTitleScene());
  stage->AddChild(new CGameScene());
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

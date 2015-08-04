#include "CApp.h"

CApp::CApp(SDL_Window * window) throw() {
  isRunning = true;
  this->window = window;
  renderer = SDL_CreateRenderer(window, -1, 0);
  if (renderer == NULL) {
    throw "Cannot create renderer";
  }
}

CApp::~CApp() {
}

void CApp::Init() {
  // Load stuff we need to load, etc..
  testTexture = LoadTexture(renderer, "res/test.png");
  rect.x = 0;
  rect.y = 0;
  rect.w = 32;
  rect.h = 32;
}

void CApp::Loop() {
  while (isRunning) {
    // Event stage
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT) {
        // Just turn off the app
        isRunning = false;
      } else if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
          case SDLK_UP:
            rect.y -= 5;
          break;
          case SDLK_LEFT:
            rect.x -= 5;
          break;
          case SDLK_RIGHT:
            rect.x += 5;
          break;
          case SDLK_DOWN:
            rect.y += 5;
          break;
        }
      }
    }
    // Update stage
    // Render stage
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, NULL);
    SDL_RenderCopy(renderer, testTexture, NULL, &rect);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000/60);
  }
}

void CApp::Cleanup() {
  SDL_DestroyWindow(window);
  window = NULL;
  SDL_Quit();
}

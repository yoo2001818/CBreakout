/*
 * CCharacter.cpp
 *
 *  Created on: 2015. 8. 5.
 *      Author: yoo2001818
 */

#include <SDL2/SDL.h>
#include <cmath>
#include "CCharacter.h"

CCharacter::CCharacter() {
  graphics = new CGraphics();
  texture = new CTexture();
  texture->LoadFromFile(CApp::instance->renderer, "res/test.png");
  graphics->texture = texture;
  AddChild(graphics);
}

CCharacter::~CCharacter() {
  if (texture != NULL) delete texture;
  delete graphics;
}

void CCharacter::OnAdd() {
}

void CCharacter::Event(SDL_Event * event) {
  CSprite::Event(event);
  if (event->type == SDL_MOUSEMOTION) {
    rect.x = event->motion.x;
    rect.y = event->motion.y;
  }
  if (event->type == SDL_MOUSEBUTTONDOWN) {
    graphics->rect.w = 1000;
  }
}

void CCharacter::Update(int delta) {
  CSprite::Update(delta);
  //graphics->rotation += delta * 3.14159 / 10;
  const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
  if (currentKeyStates[SDL_SCANCODE_W]) {
    rect.y -= delta * 300/1000;
  }
  if (currentKeyStates[SDL_SCANCODE_S]) {
    rect.y += delta * 300/1000;
  }
  if (currentKeyStates[SDL_SCANCODE_A]) {
    rect.x -= delta * 300/1000;
  }
  if (currentKeyStates[SDL_SCANCODE_D]) {
    rect.x += delta * 300/1000;
  }
}

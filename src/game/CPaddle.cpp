/*
 * CPaddle.cpp
 *
 *  Created on: 2015. 8. 6.
 *      Author: yoo2001818
 */

#include "CPaddle.h"
#include "../CBreakoutConfig.h"
#include <math.h>

CGraphics * createNewGraphics() {
  CGraphics * graphics = new CGraphics();
  graphics->texture = CGraphics::spriteSheet;
  return graphics;
}

CPaddle::CPaddle() {
  header = createNewGraphics();
  AddChild(header);
  header->src = new SDL_Rect {0, 0, 40, 30};
  body = createNewGraphics();
  AddChild(body);
  body->src = new SDL_Rect {0, 30, 40, 30};
  footer = createNewGraphics();
  AddChild(footer);
  footer->src = new SDL_Rect {0, 60, 40, 30};
  rect.x = 30;
  rect.w = 40;
  rect.h = 150;
  velX = 0.f;
  disXpos = 0.f;
}

CPaddle::~CPaddle() {
}

void CPaddle::Event(SDL_Event * event) {
  CSprite::Event(event);
  if (event->type == SDL_MOUSEMOTION) {
    //rect.x = event->motion.x;
    y = event->motion.y - rect.h / 2;
    if (y < 10) y = 10;
    if (y > APP_HEIGHT - 10 - rect.h)
      y = APP_HEIGHT - 10 - rect.h;
  }
}

void CPaddle::Update(int delta) {
  CSprite::Update(delta);
  body->y = 30;
  body->rect.h = rect.h - 60;
  footer->y = rect.h - 30;
  float rectX = rect.x;
  rectX += velX;
  disXpos = (30 - rectX) / 5.f + (disXpos) / 4.f;
  rectX += disXpos;
  velX += (-velX) / 10.f;
  x = rectX;
}

bool CPaddle::OnCollide(CBall * ball) {
  SDL_Point left = {ball->rect.x, ball->rect.y + ball->rect.h / 2};
  if (!HitTestPoint(left)) return true;
  Mix_PlayChannel(-1, EFFECT_BOUNCE1, 0);
  float degrees = atan2((rect.y + rect.h / 2) - (ball->rect.y + ball->rect.h / 2),
      -60);
  ball->velX = -cos(degrees) * ball->speed;
  ball->velY = -sin(degrees) * ball->speed;
  if (ball->velX < 50/1000.f) ball->velX = 50/1000.f;
  velX -= ball->velX * 30;
  ball->x = x + rect.w;
  return false;
}

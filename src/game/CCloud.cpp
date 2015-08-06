/*
 * CCloud.cpp
 *
 *  Created on: 2015. 8. 5.
 *      Author: yoo2001818
 */

#include "CCloud.h"
#include "CApp.h"
#include "../CBreakoutConfig.h"
#include <math.h>


SDL_Rect clouds[] = {
    {182, 102, 124, 84},
    {311, 102, 173, 113},
    {180, 191, 127, 85},
    {311, 217, 164, 121},
    {134, 282, 173, 113}
};

CCloud::CCloud() {
  graphics = new CGraphics();
  graphics->texture = CGraphics::spriteSheet;
  graphics->src = &clouds[rand()%4];
  AddChild(graphics);
  rect.w = graphics->src->w;
  rect.h = graphics->src->h;
}

CCloud::~CCloud() {
  delete graphics;
}

void CCloud::Update(int delta) {
  CVelocitySprite::Update(delta);
  if (rect.x < -rect.w) {
    isAlive = false;
  }
}

bool CCloud::OnCollide(CBall * ball) {
  float direction = rand() % 360 / 180.f * 3.141592f;
  ball->velX = cos(direction) * ball->speed;
  ball->velY = sin(direction) * ball->speed;
  parent->RemoveChild(this);
  //delete this;
  return false;
}

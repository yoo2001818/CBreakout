/*
 * CBreakEffect.cpp
 *
 *  Created on: 2015. 8. 6.
 *      Author: yoo2001818
 */

#include "CBreakEffect.h"

CBreakEffect::CBreakEffect(CTexture * texture, SDL_Rect * src) {
  this->texture = texture;
  this->src = src;
  step = 0;
  velX = 0;
  velY = 0;
}

CBreakEffect::~CBreakEffect() {
}

void CBreakEffect::Update(int delta) {
  CGraphics::Update(delta);
  velY += 0.01f;
  if (src->w < 30 && step % 2 == 1) {
    src->x += 1;
    src->y += 1;
    x += 1;
    y += 1;
    src->w -= 2;
    src->h -= 2;
    rect.w -= 2;
    rect.h -= 2;
    if (src->w < 0) isAlive = false;
  }
  if (src->w < 30) {
    step ++;
  } else {
    step += delta;
  }
  if (step > 12 * src->w && src->w > 30) {
    if (src->w > 30) {
      CBreakEffect::DoBreak(parent, this, velX, velY);
    }
    isAlive = false;
  }
  /*if (step > 3000) {
    isAlive = false;
  }*/
  x += velX * delta;
  y += velY * delta;
}

void CBreakEffect::DoBreak(CDisplayContainer * container, CGraphics * origin,
    float velX, float velY) {
  origin->texture->oneTimeUse = false;
  SDL_Point point = {0, 0};
  point = origin->LocalToGlobal(point);
  // Split to 4
  CBreakEffect * topLeft = new CBreakEffect(origin->texture, new SDL_Rect {
    origin->src->x, origin->src->y, origin->src->w / 2, origin->src->h / 2
  });
  topLeft->x = point.x;
  topLeft->y = point.y;
  topLeft->velX = -0.01f;
  topLeft->velY = -0.02f;
  topLeft->velX += velX;
  topLeft->velY += velY;
  container->AddChild(topLeft);
  CBreakEffect * topRight = new CBreakEffect(origin->texture, new SDL_Rect {
    origin->src->x + origin->src->w / 2, origin->src->y,
    origin->src->w / 2, origin->src->h / 2
  });
  topRight->x = point.x + origin->src->w / 2;
  topRight->y = point.y;
  topRight->velX = 0.01f;
  topRight->velY = -0.02f;
  topRight->velX += velX;
  topRight->velY += velY;
  container->AddChild(topRight);
  CBreakEffect * bottomLeft = new CBreakEffect(origin->texture, new SDL_Rect {
    origin->src->x, origin->src->y + origin->src->h / 2,
    origin->src->w / 2, origin->src->h / 2
  });
  bottomLeft->x = point.x;
  bottomLeft->y = point.y + origin->src->h / 2;
  bottomLeft->velX = -0.02f;
  bottomLeft->velY = 0.02f;
  bottomLeft->velX += velX;
  bottomLeft->velY += velY;
  container->AddChild(bottomLeft);
  CBreakEffect * bottomRight = new CBreakEffect(origin->texture, new SDL_Rect {
    origin->src->x + origin->src->w / 2, origin->src->y + origin->src->h / 2,
    origin->src->w / 2, origin->src->h / 2
  });
  bottomRight->x = point.x + origin->src->w / 2;
  bottomRight->y = point.y + origin->src->h / 2;
  bottomRight->velX = 0.02f;
  bottomRight->velY = 0.02f;
  bottomRight->velX += velX;
  bottomRight->velY += velY;
  container->AddChild(bottomRight);
}

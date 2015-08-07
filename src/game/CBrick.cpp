/*
 * CBrick.cpp
 *
 *  Created on: 2015. 8. 6.
 *      Author: yoo2001818
 */

#include "CBrick.h"
#include "../CGraphics.h"
#include "CBreakEffect.h"
#include "CGameScene.h"

int killCycle = 0;

CBrick::CBrick() {
  graphics = new CGraphics();
  graphics->texture = CGraphics::spriteSheet;
  graphics->src = new SDL_Rect {80, 0, 100, 100};
  AddChild(graphics);
  rect.w = graphics->src->w;
  rect.h = graphics->src->h;
}

CBrick::~CBrick() {
  delete graphics;
}

void CBrick::OnRemove() {
}

void CBrick::Update(int delta) {
  CVelocitySprite::Update(delta);
  if (rect.x < 70) {
    ((CGameScene *)(parent->parent))->hp -= 1;
    CBreakEffect::DoBreak(parent, graphics, velX + 0.2f, velY);
    parent->RemoveChild(this);
    Mix_PlayChannel(-1, EFFECT_DAMAGE[(killCycle++) % 3], 0);
  }
  /*if (rand() % 100 == 56) {
    Mix_PlayChannel(-1, EFFECT_KILL[rand()%3], 0);
  }*/
}

bool CBrick::OnCollide(CBall * ball) {
  CBreakEffect::DoBreak(parent, graphics, velX + ball->velX / 2, velY + ball->velY / 2);
  parent->RemoveChild(this);
  Mix_PlayChannel(-1, EFFECT_KILL[(killCycle++) % 3], 0);
  //delete this;
  return true;
}
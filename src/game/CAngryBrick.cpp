/*
 * CAngryBrick.cpp
 *
 *  Created on: 2015. 8. 6.
 *      Author: yoo2001818
 */

#include "CAngryBrick.h"
#include "CScoreScene.h"
#include "../CBreakoutConfig.h"

CAngryBrick::CAngryBrick() {
  graphics->src = new SDL_Rect {180, 0, 100, 100};
  spit = false;
}

CAngryBrick::~CAngryBrick() {
}

void CAngryBrick::Update(int delta) {
  CBrick::Update(delta);
  if (x < APP_WIDTH * 3 / 4 && !spit) {
    Mix_PlayChannel(-1, EFFECT_SPLAT, 0);
    CBall * ball = new CBall();
    ball->x = x - ball->rect.w;
    ball->y = y + rect.h / 2 - ball->rect.h / 2;
    if(ball->velX > 0) ball->velX *= -1;
    parent->AddChild(ball);
    spit = true;
    graphics->src = new SDL_Rect {80, 0, 100, 100};
  }
}

bool CAngryBrick::OnCollide(CBall * ball) {
  // Create new ball
  if (!spit) {
    CScoreScene::score += 100;
    Mix_PlayChannel(-1, EFFECT_SPLAT, 0);
    CBall * newball = new CBall();
    newball->x = x - newball->rect.w;
    newball->y = y + rect.h / 2 - newball->rect.h / 2;
    if(newball->velX > 0) newball->velX *= -1;
    parent->AddChild(newball);
  }
  return CBrick::OnCollide(ball);
}

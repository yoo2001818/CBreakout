/*
 * CHPDisp.cpp
 *
 *  Created on: 2015. 8. 7.
 *      Author: yoo2001818
 */

#include "CHPDisp.h"
#include "CGameScene.h"

CGraphics * createNewGraphics();

CHPDisp::CHPDisp() {
  header = createNewGraphics();
  AddChild(header);
  header->src = new SDL_Rect {0, 210, 10, 10};
  body = createNewGraphics();
  AddChild(body);
  body->src = new SDL_Rect {10, 210, 20, 10};
  footer = createNewGraphics();
  AddChild(footer);
  footer->src = new SDL_Rect {30, 210, 10, 10};
  rect.w = 150;
  rect.h = 10;
}

CHPDisp::~CHPDisp() {
}

void CHPDisp::Update(int delta) {
  CSprite::Update(delta);
  body->x = 10;
  body->rect.w = rect.w - 20;
  body->rect.h = 10;
  footer->x = rect.w - 10;
}

/*
 * CItem.cpp
 *
 *  Created on: 2015. 8. 7.
 *      Author: yoo2001818
 */

#include "CItem.h"
#include "../CBreakoutConfig.h"
#include "CGameScene.h"
#include "CBrick.h"
#include "CBreakEffect.h"

CItem::CItem() {
  type = 0;
  if (rand()%3 == 1) {
    type = 1+(rand()%2);
  }
  graphics = new CGraphics();
  graphics->texture = CGraphics::spriteSheet;
  switch (type) {
    case 0:
      graphics->src = new SDL_Rect {40, 40, 40, 40};
      break;
    case 1:
      graphics->src = new SDL_Rect {0, 130, 40, 40};
      break;
    case 2:
      graphics->src = new SDL_Rect {40, 130, 40, 40};
      break;
  }
  AddChild(graphics);
  velX = -200/1000.f;
  y = APP_HEIGHT / 2;
  x = 500;
  rect.w = 40;
  rect.h = 40;
}

CItem::~CItem() {
  delete graphics;
}

void CItem::OnPaddle(CPaddle * paddle) {
  switch (type) {
  case 0:
    ((CGameScene *)(parent->parent))->hp ++;
    break;
  case 1:
    paddle->rect.h += 10;
    break;
  case 2:
    // Go back!
    for (auto it = parent->children.begin(); it != parent->children.end(); it++) {
      if(*it == this) continue;
      CDisplayObject * other = *it;
      CBrick * obj = dynamic_cast<CBrick *>(other);
      if (obj == NULL) continue;
      CBreakEffect::DoBreak(parent, obj->graphics, obj->velX, obj->velY - 0.1f);
      obj->isAlive = false;
    }
    break;
  }
  // Meow!
  Mix_PlayChannel(-1, EFFECT_ITEM, 0);
  isAlive = false;
}

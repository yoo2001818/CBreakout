/*
 * CBall.cpp
 *
 *  Created on: 2015. 8. 6.
 *      Author: yoo2001818
 */

#include "CBall.h"
#include "../CBreakoutConfig.h"
#include "ICollidable.h"
#include "CGameScene.h"
#include "CPaddle.h"
#define PI 3.141592f
#include <math.h>

CBall::CBall() {
  graphics = new CGraphics();
  graphics->texture = CGraphics::spriteSheet;
  graphics->src = new SDL_Rect {40, 0, 40, 40};
  AddChild(graphics);
  speed = 400/1000.f;
  float direction = rand() % 360 / 180.f * PI;
  velX = cos(direction) * speed;
  velY = sin(direction) * speed;
  y = APP_HEIGHT / 2;
  x = 500;
  rect.w = 40;
  rect.h = 40;
  hanging = false;
}

CBall::~CBall() {
  delete graphics;
}

void CBall::OnAdd() {
  ((CGameScene *)(parent->parent))->ballCounter ++;
}

void CBall::OnRemove() {
  ((CGameScene *)(parent->parent))->ballCounter --;
}

void CBall::Update(int delta) {
  CVelocitySprite::Update(delta);
  if (hanging) {
    CPaddle * paddle = ((CGameScene *)(parent->parent))->paddle;
    x = 70;
    y = paddle->y + paddle->rect.h / 2 - rect.h / 2;
    velY = 0;
    velX = speed;
    return;
  }
  int hit = 0;
  if (velX > -0.05 && velX < 0.05) {
    velX = -0.1;
  }
  if (x < -rect.w) {
    Mix_PlayChannel(-1, EFFECT_DROP, 0);
    isAlive = false;
  }
  if (x > APP_WIDTH - rect.w) {
    x = APP_WIDTH - rect.w;
    velX = -velX;
    hit ++;
  }
  if (y < 0) {
    velY = -velY;
    y = 0;
    hit ++;
  }
  if (y > APP_HEIGHT - rect.h) {
    velY = -velY;
    y = APP_HEIGHT - rect.h;
    hit ++;
  }
  for (auto it = parent->children.begin(); it != parent->children.end(); it++) {
    if(*it == this) continue;
    CDisplayObject * other = *it;
    if (other->HitTestRect(rect)) {
      SDL_Rect target;
      SDL_IntersectRect(&rect, &(other->rect), &target);
      ICollidable * obj = dynamic_cast<ICollidable *>(other);
      if (obj == NULL) continue;
      if (obj->OnCollide(this)) {
        hit ++;
        if (target.w > target.h && target.y > other->rect.y + other->rect.h / 2) {
          velY = -velY;
          y = other->rect.y + other->rect.h;
        }
        if (target.w > target.h && target.y < other->rect.y + other->rect.h / 2) {
          velY = -velY;
          y = other->rect.y - rect.h;
        }
        if (target.w < target.h && target.x > other->rect.x + other->rect.w / 2) {
          velX = -velX;
          x = other->rect.x + other->rect.w;
        }
        if (target.w < target.h && target.x < other->rect.x + other->rect.w / 2) {
          velX = -velX;
          x = other->rect.x - rect.w;
        }
      }
    }
  }
  if (hit) {
    Mix_PlayChannel(-1, EFFECT_BOUNCE1, 0);
  }
}


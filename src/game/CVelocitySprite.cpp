/*
 * CVelocitySprite.cpp
 *
 *  Created on: 2015. 8. 5.
 *      Author: yoo2001818
 */

#include "CVelocitySprite.h"

CVelocitySprite::CVelocitySprite() {
  velX = 0;
  velY = 0;
}

CVelocitySprite::~CVelocitySprite() {
}

void CVelocitySprite::Update(int delta) {
  CSprite::Update(delta);
  rect.x += velX * delta;
  rect.y += velY * delta;
}

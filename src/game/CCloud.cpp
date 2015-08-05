/*
 * CCloud.cpp
 *
 *  Created on: 2015. 8. 5.
 *      Author: yoo2001818
 */

#include "CCloud.h"
#include "CApp.h"
#include "../CBreakoutConfig.h"

CTexture * CCloud::cachedTexture = NULL;

CCloud::CCloud() {
  if(cachedTexture == NULL) {
    cachedTexture = new CTexture();
    cachedTexture->LoadFromFile(CApp::instance->renderer, "res/cloud.png");
  }
  graphics = new CGraphics();
  graphics->texture = cachedTexture;
  AddChild(graphics);
  rect.x = APP_WIDTH;
  velX = -300/1000.f;
}

CCloud::~CCloud() {
  delete graphics;
}

void CCloud::Update(int delta) {
  CVelocitySprite::Update(delta);
  if(rect.x < -cachedTexture->GetWidth()) {
    rect.x = APP_WIDTH;
  }
}

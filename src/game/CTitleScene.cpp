/*
 * CTitleScene.cpp
 *
 *  Created on: 2015. 8. 5.
 *      Author: yoo2001818
 */

#include "CTitleScene.h"
#include "CBreakEffect.h"
#include "CGameScene.h"
#include "../CBreakoutConfig.h"

CTitleScene::CTitleScene() {
  background = new CGraphics();
  background->texture = new CTexture();
  background->texture->LoadFromFile(CApp::instance->renderer, "res/bg.png");
  background->src = new SDL_Rect {0, 0, 800, 600};
  AddChild(background);

  bgLayer = new CSprite();
  AddChild(bgLayer);

  /*for (int i = 0; i < 800; i += 40) {
    CCloud * cloud = new CCloud();
    cloud->x = i;
    cloud->y = rand() % (APP_HEIGHT - cloud->rect.h);
    //cloud->rect.y = 0;
    cloud->velX = (-40 - rand()%10) / 1000.f;
    bgLayer->AddChild(cloud);
  }*/

  //CCloudContainer * cloud = new CCloudContainer();
  //AddChild(cloud);

  foreground = new CGraphics();
  foreground->texture = new CTexture();
  foreground->texture->LoadFromFile(CApp::instance->renderer, "res/title.png");
  foreground->src = new SDL_Rect {0, 0, 800, 600};
  AddChild(foreground);

  timer = 0;
  cloudTimer = 1000;

  //CBreakEffect::DoBreak(this, background, 0, -0.1f);
  //CBreakEffect::DoBreak(this, foreground, 0, -0.1f);
  //foreground->isAlive = false;
}

CTitleScene::~CTitleScene() {
}

void CTitleScene::OnAdd() {
}

void CTitleScene::Event(SDL_Event * event) {
  CScene::Event(event);
  if (event->type == SDL_MOUSEBUTTONDOWN) {
    if (parent->children.size() == 1) {
      timer = 1;
    }
  }
}

void CTitleScene::Update(int delta) {
  CScene::Update(delta);
  if (timer == 1) {
    parent->AddChild(new CGameScene());
    isAlive = false;
    timer = 0;
  }
  cloudTimer -= delta;
  if (cloudTimer < 0) {
    cloudTimer = 1000;
    /*CCloud * cloud = new CCloud();
    cloud->x = APP_WIDTH;
    cloud->y = rand() % (APP_HEIGHT - cloud->rect.h);
    //cloud->rect.y = 0;
    cloud->velX = (-40 - rand()%10) / 1000.f;
    bgLayer->AddChild(cloud);*/
  }
}

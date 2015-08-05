/*
 * CTitleScene.cpp
 *
 *  Created on: 2015. 8. 5.
 *      Author: yoo2001818
 */

#include "CTitleScene.h"

CTitleScene::CTitleScene() {
  background = new CGraphics();
  background->texture = new CTexture();
  background->texture->LoadFromFile(CApp::instance->renderer, "res/bg.png");
  AddChild(background);

  CCloud * cloud = new CCloud();
  AddChild(cloud);

  foreground = new CGraphics();
  foreground->texture = new CTexture();
  foreground->texture->LoadFromFile(CApp::instance->renderer, "res/title.png");
  AddChild(foreground);
}

CTitleScene::~CTitleScene() {
}

void CTitleScene::OnAdd() {
}

void CTitleScene::Update(int delta) {
  CScene::Update(delta);
}

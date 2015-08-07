/*
 * CGameScene.cpp
 *
 *  Created on: 2015. 8. 5.
 *      Author: yoo2001818
 */

#include "CGameScene.h"
#include "CCloud.h"
#include "CBrick.h"
#include "CAngryBrick.h"
#include "CHardBrick.h"
#include "CHPDisp.h"
#include "CTitleScene.h"
#include "../CBreakoutConfig.h"

CGameScene::CGameScene() {

  bgLayer = new CSprite();
  AddChild(bgLayer);

  CGraphics * bg = new CGraphics();
  bg->texture = new CTexture();
  bg->texture->LoadFromFile(CApp::instance->renderer, "res/bg.png");
  bg->src = new SDL_Rect {0, 0, 800, 600};
  bgLayer->AddChild(bg);


  gameLayer = new CSprite();
  AddChild(gameLayer);

  ballCounter = 0;

  paddle = new CPaddle();
  gameLayer->AddChild(paddle);
  CBall * ball = new CBall();
  ball->x = 70;
  ball->y = paddle->y + paddle->rect.h / 2 - ball->rect.h / 2;
  if(ball->velX < 0) ball->velX *= -1;
  gameLayer->AddChild(ball);
  ball->hanging = true;
  timer = 100;
  cloudTimer = 1000;
  difficulty = 1;
  angryTimer = 10;

  hp = 20;
  maxhp = 20;

  for (int i = 0; i < 800; i += 40) {
    CCloud * cloud = new CCloud();
    cloud->x = i;
    cloud->y = rand() % (APP_HEIGHT - cloud->rect.h);
    //cloud->rect.y = 0;
    cloud->velX = (-20 - rand()%5) * difficulty / 1000.f;
    bgLayer->AddChild(cloud);
  }

  hpDisp = new CHPDisp();
  AddChild(hpDisp);

}

CGameScene::~CGameScene() {
}

void CGameScene::OnAdd() {
  Mix_PlayMusic(MUSIC, -1);

}

void CGameScene::OnRemove() {
  Mix_HaltMusic();
}

void CGameScene::Update(int delta) {
  CScene::Update(delta);
  //paddle->rect.h = 160 - ballCounter * 10;
  if (hp <= 0) {
    // Game over man!
    parent->AddChild(new CTitleScene());
    isAlive = false;
  }
  hpDisp->rect.w = 20 * hp;
  timer -= delta;
  cloudTimer -= delta;
  difficulty += delta / (80 * 1000.f);
  if (ballCounter == 0) {
    hp -= 1;
    Mix_PlayChannel(-1, EFFECT_REVIVE, 0);
    CBall * ball = new CBall();
    ball->x = 70;
    ball->y = paddle->y + paddle->rect.h / 2 - ball->rect.h / 2;
    if(ball->velX < 0) ball->velX *= -1;
    gameLayer->AddChild(ball);
    ball->hanging = true;
  }
  if (timer < 0) {
    int start = rand() % 6;
    int end = rand() % 6;
    if (start > end) {
      int swap = end;
      end = start;
      start = swap;
    }
    if (end - start > 1 + (difficulty - 1) * 2) {
      end = start + 1 + (difficulty - 1) * 2;
    }
    for (int i = start; i <= end; ++i) {
      CBrick * cloud;
      if (--angryTimer < 0) cloud = new CAngryBrick();
      else if (rand() % 4 == 1) cloud = new CHardBrick();
      else cloud = new CBrick();
      cloud->x = APP_WIDTH;
      cloud->y = i * 100;
      cloud->velX = -30 * difficulty / 1000.f;
      gameLayer->AddChild(cloud);
      if (angryTimer < 0) angryTimer = 10 * difficulty;
    }
    timer = (rand() % 3000) / difficulty + 100 * 1000 / (30 * difficulty) + 300;
  }
  if (cloudTimer < 0) {
    cloudTimer = 2000 / difficulty;
    CCloud * cloud = new CCloud();
    cloud->x = APP_WIDTH;
    cloud->y = rand() % (APP_HEIGHT - cloud->rect.h);
    //cloud->rect.y = 0;
    cloud->velX = (-20 - rand()%5) * difficulty / 1000.f;
    bgLayer->AddChild(cloud);
  }
}

void CGameScene::Event(SDL_Event * event) {
  CScene::Event(event);
  if (event->type == SDL_MOUSEBUTTONDOWN) {
    for (auto it = gameLayer->children.begin(); it != gameLayer->children.end(); it++) {
      if(*it == this) continue;
      CDisplayObject * other = *it;
      CBall * obj = dynamic_cast<CBall *>(other);
      if (obj == NULL) continue;
      obj->hanging = false;
    }
  }
}

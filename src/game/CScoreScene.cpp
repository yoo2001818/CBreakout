/*
 * CScoreScene.cpp
 *
 *  Created on: 2015. 8. 7.
 *      Author: yoo2001818
 */

#include "CScoreScene.h"
#include "../CBreakoutConfig.h"

int CScoreScene::score = 0;
int CScoreScene::highScore = 0;

CScoreScene::CScoreScene() {
  scoreDisp = new CScoreDisp();
  scoreDisp->x = APP_WIDTH - scoreDisp->rect.w;
  scoreDisp->y = APP_HEIGHT - scoreDisp->rect.h;
  AddChild(scoreDisp);
  highScoreDisp = new CScoreDisp();
  highScoreDisp->x = APP_WIDTH - highScoreDisp->rect.w;
  highScoreDisp->y = APP_HEIGHT - highScoreDisp->rect.h -
      scoreDisp->rect.h;
  AddChild(highScoreDisp);
}

CScoreScene::~CScoreScene() {
}

void CScoreScene::Update(int delta) {
  CScene::Update(delta);
  if (score > highScore) highScore = score;
  scoreDisp->value = score;
  highScoreDisp->value = highScore;
}

/*
 * CGameScene.cpp
 *
 *  Created on: 2015. 8. 5.
 *      Author: yoo2001818
 */

#include "CGameScene.h"

CGameScene::CGameScene() {
  character = new CCharacter();
  AddChild(character);
}

CGameScene::~CGameScene() {
}

void CGameScene::OnAdd() {
}

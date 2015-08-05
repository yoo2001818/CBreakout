/*
 * CGameScene.h
 *
 *  Created on: 2015. 8. 5.
 *      Author: yoo2001818
 */

#ifndef SRC_GAME_CGAMESCENE_H_
#define SRC_GAME_CGAMESCENE_H_

#include "../CScene.h"
#include "CCharacter.h"

class CGameScene: public CScene {
public:
  CGameScene();
  virtual ~CGameScene();

  virtual void OnAdd();

  CCharacter * character;
};

#endif /* SRC_GAME_CGAMESCENE_H_ */

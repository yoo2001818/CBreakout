/*
 * CGameScene.h
 *
 *  Created on: 2015. 8. 5.
 *      Author: yoo2001818
 */

#ifndef SRC_GAME_CGAMESCENE_H_
#define SRC_GAME_CGAMESCENE_H_

#include "../CScene.h"
#include "CPaddle.h"
#include "CBall.h"
#include "CHPDisp.h"

class CGameScene: public CScene {
public:
  CGameScene();
  virtual ~CGameScene();

  float difficulty;
  int timer;
  int cloudTimer;
  int angryTimer;
  int ballCounter;
  int hp;
  int maxhp;

  virtual void OnAdd();
  virtual void OnRemove();
  virtual void Update(int delta);
  virtual void Event(SDL_Event * event);

  CSprite * bgLayer;
  CSprite * gameLayer;
  CPaddle * paddle;
  CHPDisp * hpDisp;
};

#endif /* SRC_GAME_CGAMESCENE_H_ */

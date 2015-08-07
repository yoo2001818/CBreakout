/*
 * CScoreScene.h
 *
 *  Created on: 2015. 8. 7.
 *      Author: yoo2001818
 */

#ifndef SRC_GAME_CSCORESCENE_H_
#define SRC_GAME_CSCORESCENE_H_

#include "../CScene.h"
#include "CScoreDisp.h"

class CScoreScene: public CScene {
public:
  CScoreScene();
  virtual ~CScoreScene();

  CScoreDisp * scoreDisp;
  CScoreDisp * highScoreDisp;

  virtual void Update(int delta);

  static int score;
  static int highScore;
};

#endif /* SRC_GAME_CSCORESCENE_H_ */

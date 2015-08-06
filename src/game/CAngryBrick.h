/*
 * CAngryBrick.h
 *
 *  Created on: 2015. 8. 6.
 *      Author: yoo2001818
 */

#ifndef SRC_GAME_CANGRYBRICK_H_
#define SRC_GAME_CANGRYBRICK_H_

#include "CBrick.h"

class CAngryBrick: public CBrick {
public:
  CAngryBrick();
  virtual ~CAngryBrick();

  bool spit;

  virtual void Update(int delta);
  virtual bool OnCollide(CBall * ball);
};

#endif /* SRC_GAME_CANGRYBRICK_H_ */

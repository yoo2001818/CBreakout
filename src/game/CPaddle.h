/*
 * CPaddle.h
 *
 *  Created on: 2015. 8. 6.
 *      Author: yoo2001818
 */

#ifndef SRC_GAME_CPADDLE_H_
#define SRC_GAME_CPADDLE_H_

#include "ICollidable.h"
#include "../CSprite.h"
#include "../CGraphics.h"

class CPaddle: public CSprite, public ICollidable {
public:
  CPaddle();
  virtual ~CPaddle();

  CGraphics * header;
  CGraphics * body;
  CGraphics * footer;

  float velX;
  float disXpos;

  virtual void Event(SDL_Event * event);
  virtual void Update(int delta);
  virtual bool OnCollide(CBall * ball);
};

#endif /* SRC_GAME_CPADDLE_H_ */

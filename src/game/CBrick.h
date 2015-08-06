/*
 * CBrick.h
 *
 *  Created on: 2015. 8. 6.
 *      Author: yoo2001818
 */

#ifndef SRC_GAME_CBRICK_H_
#define SRC_GAME_CBRICK_H_

#include "CVelocitySprite.h"
#include "ICollidable.h"

class CBrick: public CVelocitySprite, public ICollidable {
public:
  CBrick();
  virtual ~CBrick();

  CGraphics * graphics;

  virtual void OnRemove();
  virtual void Update(int delta);
  virtual bool OnCollide(CBall * ball);
};

#endif /* SRC_GAME_CBRICK_H_ */

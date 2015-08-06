/*
 * CBall.h
 *
 *  Created on: 2015. 8. 6.
 *      Author: yoo2001818
 */

#ifndef SRC_GAME_CBALL_H_
#define SRC_GAME_CBALL_H_

#include "CVelocitySprite.h"
#include "../CGraphics.h"

class CBall: public CVelocitySprite {
public:
  CBall();
  virtual ~CBall();

  virtual void OnAdd();
  virtual void OnRemove();
  virtual void Update(int delta);

  bool hanging;

  CGraphics * graphics;
  float speed;
};

#endif /* SRC_GAME_CBALL_H_ */

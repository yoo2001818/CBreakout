/*
 * CItem.h
 *
 *  Created on: 2015. 8. 7.
 *      Author: yoo2001818
 */

#ifndef SRC_GAME_CITEM_H_
#define SRC_GAME_CITEM_H_

#include "CVelocitySprite.h"
#include "../CGraphics.h"
#include "CPaddle.h"

class CItem: public CVelocitySprite {
public:
  CItem();
  virtual ~CItem();

  virtual void OnPaddle(CPaddle * paddle);

  CGraphics * graphics;
  int type;
};

#endif /* SRC_GAME_CITEM_H_ */

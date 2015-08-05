/*
 * CCloud.h
 *
 *  Created on: 2015. 8. 5.
 *      Author: yoo2001818
 */

#ifndef SRC_GAME_CCLOUD_H_
#define SRC_GAME_CCLOUD_H_

#include "CVelocitySprite.h"
#include "../CTexture.h"
#include "../CGraphics.h"

class CCloud: public CVelocitySprite {
public:
  CCloud();
  virtual ~CCloud();

  CGraphics * graphics;

  void Update(int delta);

  static CTexture * cachedTexture;
};

#endif /* SRC_GAME_CCLOUD_H_ */

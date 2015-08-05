/*
 * CVelocitySprite.h
 *
 *  Created on: 2015. 8. 5.
 *      Author: yoo2001818
 */

#ifndef SRC_GAME_CVELOCITYSPRITE_H_
#define SRC_GAME_CVELOCITYSPRITE_H_

#include "../CSprite.h"

class CVelocitySprite: public CSprite {
public:
  CVelocitySprite();
  virtual ~CVelocitySprite();

  virtual void Update(int delta);

  float velX;
  float velY;
};

#endif /* SRC_GAME_CVELOCITYSPRITE_H_ */

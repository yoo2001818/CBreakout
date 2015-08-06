/*
 * ICollidable.h
 *
 *  Created on: 2015. 8. 6.
 *      Author: yoo2001818
 */

#ifndef SRC_GAME_ICOLLIDABLE_H_
#define SRC_GAME_ICOLLIDABLE_H_

#include "CBall.h"

class ICollidable {
public:
  virtual ~ICollidable() {};
  virtual bool OnCollide(CBall * ball) {
    return true;
  };
};

#endif /* SRC_GAME_ICOLLIDABLE_H_ */

/*
 * CHardBrick.h
 *
 *  Created on: 2015. 8. 7.
 *      Author: yoo2001818
 */

#ifndef SRC_GAME_CHARDBRICK_H_
#define SRC_GAME_CHARDBRICK_H_

#include "CBrick.h"

class CHardBrick: public CBrick {
public:
  CHardBrick();
  virtual ~CHardBrick();

  int hp;

  virtual bool OnCollide(CBall * ball);
};

#endif /* SRC_GAME_CHARDBRICK_H_ */

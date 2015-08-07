/*
 * CHPDisp.h
 *
 *  Created on: 2015. 8. 7.
 *      Author: yoo2001818
 */

#ifndef SRC_GAME_CHPDISP_H_
#define SRC_GAME_CHPDISP_H_

#include "../CSprite.h"
#include "../CGraphics.h"

class CHPDisp: public CSprite {
public:
  CHPDisp(bool gray);
  virtual ~CHPDisp();

  CGraphics * header;
  CGraphics * body;
  CGraphics * footer;

  virtual void Update(int delta);
};

#endif /* SRC_GAME_CHPDISP_H_ */

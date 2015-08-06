/*
 * CBreakEffect.h
 *
 *  Created on: 2015. 8. 6.
 *      Author: yoo2001818
 */

#ifndef SRC_GAME_CBREAKEFFECT_H_
#define SRC_GAME_CBREAKEFFECT_H_

#include "../CGraphics.h"

class CBreakEffect: public CGraphics {
public:
  CBreakEffect(CTexture * texture, SDL_Rect * src);
  virtual ~CBreakEffect();

  int step;
  float velX;
  float velY;

  void Update(int delta);

  static void DoBreak(CDisplayContainer * container, CGraphics * origin,
      float velX, float velY);
};

#endif /* SRC_GAME_CBREAKEFFECT_H_ */

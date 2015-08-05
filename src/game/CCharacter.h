/*
 * CCharacter.h
 *
 *  Created on: 2015. 8. 5.
 *      Author: yoo2001818
 */

#ifndef SRC_GAME_CCHARACTER_H_
#define SRC_GAME_CCHARACTER_H_

#include "../CSprite.h"
#include "../CTexture.h"
#include "../CGraphics.h"

class CCharacter: public CSprite {
public:
  CCharacter();
  virtual ~CCharacter();

  CGraphics * graphics;
  CTexture * texture;

  virtual void OnAdd();
  virtual void Event(SDL_Event * event);
  virtual void Update(int delta);
};

#endif /* SRC_GAME_CCHARACTER_H_ */

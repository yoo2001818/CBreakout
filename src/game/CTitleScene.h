/*
 * CTitleScene.h
 *
 *  Created on: 2015. 8. 5.
 *      Author: yoo2001818
 */

#ifndef SRC_GAME_CTITLESCENE_H_
#define SRC_GAME_CTITLESCENE_H_

#include "../CScene.h"
#include "../CGraphics.h"
#include "../CTexture.h"
#include "CCloudContainer.h"

class CTitleScene: public CScene {
public:
  CTitleScene();
  virtual ~CTitleScene();

  virtual void OnAdd();
  virtual void Event(SDL_Event * event);
  virtual void Update(int delta);

  CGraphics * background;
  CGraphics * foreground;

  int timer;
};

#endif /* SRC_GAME_CTITLESCENE_H_ */

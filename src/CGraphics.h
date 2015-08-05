/*
 * CGraphics.h
 *
 *  Created on: 2015. 8. 5.
 *      Author: yoo2001818
 */

#ifndef SRC_CGRAPHICS_H_
#define SRC_CGRAPHICS_H_

#include "CDisplayObject.h"
#include "CTexture.h"
#include "CApp.h"

class CGraphics: public CDisplayObject {
public:
  CGraphics();
  virtual ~CGraphics();

  CTexture * texture;

  double rotation;
  SDL_Point center;
  SDL_RendererFlip flip;

  virtual void Render();
};

#endif /* SRC_CGRAPHICS_H_ */

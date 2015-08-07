/*
 * CGraphics.cpp
 *
 *  Created on: 2015. 8. 5.
 *      Author: yoo2001818
 */

#include "CGraphics.h"

CTexture * CGraphics::spriteSheet = NULL;

CGraphics::CGraphics() {
  texture = NULL;
  rotation = 0;
  flip = SDL_FLIP_NONE;
  src = NULL;
  alpha = 255;
}

CGraphics::~CGraphics() {
  if (texture != NULL && texture->oneTimeUse) delete texture;
}

void CGraphics::Render() {
  CDisplayObject::Render();
  if (texture != NULL) {
    if (rect.w == 0) {
      if (src != NULL && src->w != 0) {
        rect.w = src->w;
        rect.h = src->h;
      } else {
        rect.w = texture->GetWidth();
        rect.h = texture->GetHeight();
      }
    }
    SDL_Point point = LocalToGlobal(SDL_Point{0, 0});
    //SDL_Point point = {rect.x, rect.y};
    //texture->RenderEx(point.x, point.y, src,
    //   rotation, &center, flip, rect.w, rect.h, alpha);
    //texture->Render(point.x, point.y);
    texture->Render(point.x, point.y, src, rect.w, rect.h, alpha);
  }
}

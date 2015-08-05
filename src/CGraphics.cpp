/*
 * CGraphics.cpp
 *
 *  Created on: 2015. 8. 5.
 *      Author: yoo2001818
 */

#include "CGraphics.h"

CGraphics::CGraphics() {
  texture = NULL;
  rotation = 0;
  flip = SDL_FLIP_NONE;
}

CGraphics::~CGraphics() {
}

void CGraphics::Render() {
  if (texture != NULL) {
    SDL_Point point = LocalToGlobal(SDL_Point{0, 0});
    //SDL_Point point = {rect.x, rect.y};
    texture->RenderEx(point.x, point.y,
        rotation, &center, flip);
    //texture->Render(point.x, point.y);
  }
}

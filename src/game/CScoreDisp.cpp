/*
 * CScoreDisp.cpp
 *
 *  Created on: 2015. 8. 7.
 *      Author: yoo2001818
 */

#include "CScoreDisp.h"

int CScoreDisp::digits = 10;

CScoreDisp::CScoreDisp() {
  texture = CGraphics::spriteSheet;
  src = new SDL_Rect {
    280, 0, 20, 30
  };
  rect.w = digits * src->w;
  rect.h = src->h;
  value = 0;
}

CScoreDisp::~CScoreDisp() {
}

void CScoreDisp::Render() {
  if (texture != NULL) {
    SDL_Point point = LocalToGlobal(SDL_Point{0, 0});
    int valueCpy = value;
    for (int i = 0; i < digits; ++i) {
      SDL_Rect srcCpy = {
          src->x + src->w * (valueCpy%10),
          src->y, src->w, src->h
      };
      texture->Render(point.x + src->w * (digits - i - 1),
          point.y, &srcCpy, src->w, src->h, alpha);
      valueCpy /= 10;
    }
  }
}

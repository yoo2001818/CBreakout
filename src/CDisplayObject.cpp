/*
 * CDisplayObject.cpp
 *
 *  Created on: 2015. 8. 4.
 *      Author: yoo2001818
 */

#include "CDisplayObject.h"
#include "CDisplayContainer.h"

CDisplayObject::CDisplayObject() {
  rect.x = 0;
  rect.y = 0;
  rect.w = 0;
  rect.h = 0;
  parent = NULL;
  stage = NULL;
  isAlive = true;
  x = 0;
  y = 0;
}

CDisplayObject::~CDisplayObject() {
}

SDL_Point CDisplayObject::LocalToGlobal(SDL_Point point) {
  SDL_Point newPoint = point;
  if (parent != NULL) newPoint = parent->LocalToGlobal(point);
  newPoint.x += this->rect.x;
  newPoint.y += this->rect.y;
  return newPoint;
}

SDL_Point CDisplayObject::GlobalToLocal(SDL_Point point) {
  SDL_Point newPoint = point;
  if (parent != NULL) newPoint = parent->LocalToGlobal(point);
  newPoint.x -= this->rect.x;
  newPoint.y -= this->rect.y;
  return newPoint;
}

bool CDisplayObject::HitTestRect(SDL_Rect rect) {
  return SDL_HasIntersection(&(this->rect), &rect);
}

bool CDisplayObject::HitTestPoint(SDL_Point point) {
  // What.
  SDL_Rect rect = this->rect;
  if (rect.x > point.x) return false;
  if (rect.x + rect.w < point.x) return false;
  if (rect.y > point.y) return false;
  if (rect.y + rect.h < point.y) return false;
  return true;
}

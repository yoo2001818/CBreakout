/*
 * CHardBrick.cpp
 *
 *  Created on: 2015. 8. 7.
 *      Author: yoo2001818
 */

#include "CHardBrick.h"

CHardBrick::CHardBrick() {
  hp = 1;
  graphics->src = new SDL_Rect {80, 100, 100, 100};
}

CHardBrick::~CHardBrick() {
}

bool CHardBrick::OnCollide(CBall * ball) {
  if (hp > 0) {
    hp --;
    if (hp == 0) {
      graphics->src = new SDL_Rect {80, 0, 100, 100};
    }
    return true;
  } else {
    return CBrick::OnCollide(ball);
  }
}

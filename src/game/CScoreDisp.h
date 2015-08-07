/*
 * CScoreDisp.h
 *
 *  Created on: 2015. 8. 7.
 *      Author: yoo2001818
 */

#ifndef SRC_GAME_CSCOREDISP_H_
#define SRC_GAME_CSCOREDISP_H_

#include "../CGraphics.h"

class CScoreDisp: public CGraphics {
public:
  CScoreDisp();
  virtual ~CScoreDisp();

  virtual void Render();

  int value;

  static int digits;
};

#endif /* SRC_GAME_CSCOREDISP_H_ */

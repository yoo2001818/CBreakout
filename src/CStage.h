/*
 * CStage.h
 *
 *  Created on: 2015. 8. 5.
 *      Author: yoo2001818
 */

#ifndef SRC_CSTAGE_H_
#define SRC_CSTAGE_H_

#include "CDisplayContainer.h"

class CApp;

class CStage: public CDisplayContainer {
public:
  CStage(CApp * app);
  virtual ~CStage();

  CApp * app;

};

#endif /* SRC_CSTAGE_H_ */

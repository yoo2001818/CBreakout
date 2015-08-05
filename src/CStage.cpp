/*
 * CStage.cpp
 *
 *  Created on: 2015. 8. 5.
 *      Author: yoo2001818
 */

#include "CStage.h"

CStage::CStage(CApp * app) {
  this->app = app;
  this->stage = this;
}

CStage::~CStage() {
}


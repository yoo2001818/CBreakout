/*
 * CCloudContainer.cpp
 *
 *  Created on: 2015. 8. 6.
 *      Author: yoo2001818
 */

#include "CCloudContainer.h"
#include "../CBreakoutConfig.h"

CCloudContainer::CCloudContainer() {
  for(int depth = 2; depth >= 0; --depth) {
    for(int x = 0; x < APP_WIDTH; x += 200) {
      CCloud * cloud = new CCloud();
      AddChild(cloud);
    }
  }
}

CCloudContainer::~CCloudContainer() {
}


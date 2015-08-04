/*
 * CDisplayContainer.h
 *
 *  Created on: 2015. 8. 4.
 *      Author: yoo2001818
 */

#ifndef SRC_CDISPLAYCONTAINER_H_
#define SRC_CDISPLAYCONTAINER_H_

#include <list>
#include "CDisplayObject.h"

using namespace std;

class CDisplayContainer: public CDisplayObject {
public:
  CDisplayContainer();
  virtual ~CDisplayContainer();

  list<CDisplayObject *> children;

  void AddChild(CDisplayObject * object);
  void AddChildAt(CDisplayObject * object, int index);
  void RemoveChild(CDisplayObject * object);
  void RemoveChildAt(int index);
  void RemoveChildren(int begin = 0, int end = 0x7fffffff);
  bool Contains(CDisplayObject * object);

  virtual void Event(SDL_Event * event);
  virtual void Update(int delta);
  virtual void Render();
};

#endif /* SRC_CDISPLAYCONTAINER_H_ */

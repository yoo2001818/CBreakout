/*
 * CDisplayContainer.cpp
 *
 *  Created on: 2015. 8. 4.
 *      Author: yoo2001818
 */

#include "CDisplayContainer.h"
#include "CDisplayObject.h"
#include <iostream>
using namespace std;

CDisplayContainer::CDisplayContainer() {
}

CDisplayContainer::~CDisplayContainer() {
  // Remove all children, free them
}

void CDisplayContainer::AddChild(CDisplayObject * object) {
  children.push_back(object);
  object->parent = this;
  object->stage = stage;
  object->OnAdd();
}

void CDisplayContainer::AddChildFront(CDisplayObject * object) {
  children.push_front(object);
  object->parent = this;
  object->stage = stage;
  object->OnAdd();
}

void CDisplayContainer::AddChildAt(CDisplayObject * object, int index) {
  // Not implemented
}

void CDisplayContainer::RemoveChild(CDisplayObject * object) {
  object->isAlive = false;
}

void CDisplayContainer::RemoveChildAt(int index) {
  // Not implemented
}

void CDisplayContainer::RemoveChildren(int begin, int end) {
  // Not implemented
}

bool CDisplayContainer::Contains(CDisplayObject * object) {
  for(auto it = children.begin(); it != children.end(); ++it) {
    if(*it == object) return true;
  }
  return false;
}

void CDisplayContainer::Event(SDL_Event * event) {
  for(auto it = children.begin(); it != children.end(); ++it) {
    (*it)->Event(event);
  }
}

void CDisplayContainer::Update(int delta) {
  CDisplayObject::Update(delta);
  for(auto it = children.begin(); it != children.end();) {
    CDisplayObject * object = *it;
    if (!object->isAlive) {
      object->OnRemove();
      it = children.erase(it);
      object->parent = NULL;
      object->stage = NULL;
      delete object;
      continue;
    }
    (*it)->Update(delta);
    it++;
  }
}

void CDisplayContainer::Render() {
  CDisplayObject::Render();
  for(auto it = children.begin(); it != children.end(); ++it) {
    (*it)->Render();
  }
}

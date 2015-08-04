/*
 * CDisplayContainer.cpp
 *
 *  Created on: 2015. 8. 4.
 *      Author: yoo2001818
 */

#include "CDisplayContainer.h"

CDisplayContainer::CDisplayContainer() {
}

CDisplayContainer::~CDisplayContainer() {
  // Remove all children, free them
}

void CDisplayContainer::AddChild(CDisplayObject * object) {
  children.push_back(object);
  object->parent = this;
}

void CDisplayContainer::AddChildAt(CDisplayObject * object, int index) {
  // Not implemented
}

void CDisplayContainer::RemoveChild(CDisplayObject * object) {
  children.remove(object);
  object->parent = NULL;
}

void CDisplayContainer::RemoveChildAt(int index) {
  // Not implemented
}

void CDisplayContainer::RemoveChildren(int begin, int end) {
  // Not implemented
}

bool CDisplayContainer::Contains(CDisplayObject * object) {
  /*for(auto it = children.begin(); it != children.end(); ++it) {
    if(*it == object) return true;
  }*/
  return false;
}

void CDisplayContainer::Event(SDL_Event * event) {
  /*for(auto it = children.begin(); it != children.end(); ++it) {
    (*it)->Event(event);
  }*/
}

void CDisplayContainer::Update(int delta) {
  /*for(auto it = children.begin(); it != children.end(); ++it) {
    (*it)->Update(delta);
  }*/
}

void CDisplayContainer::Render() {
  /*for(auto it = children.begin(); it != children.end(); ++it) {
    (*it)->Render();
  }*/
}

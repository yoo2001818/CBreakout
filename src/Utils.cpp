/*
 * Utils.cpp
 *
 *  Created on: 2015. 8. 4.
 *      Author: yoo2001818
 */

#include "Utils.h"

SDL_Texture * LoadTexture(SDL_Renderer * renderer, std::string path) throw() {
  SDL_Texture * newTexture = NULL;
  SDL_Surface * loadedSurface = IMG_Load(path.c_str());
  if (loadedSurface == NULL) {
    std::ostringstream stringStream;
    stringStream << "Unable to load image ";
    stringStream << path;
    stringStream << " ";
    throw stringStream.str().c_str();
  }
  newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
  SDL_FreeSurface(loadedSurface);
  if (newTexture == NULL) {
    // ...
  }
  return newTexture;
}

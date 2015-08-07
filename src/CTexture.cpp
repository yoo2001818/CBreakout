/*
 * CTexture.cpp
 *
 *  Created on: 2015. 8. 4.
 *      Author: yoo2001818
 */

#include "CTexture.h"

using namespace std;

CTexture::CTexture() {
  width = 0;
  height = 0;
  texture = NULL;
  renderer = NULL;
  oneTimeUse = true;
}

CTexture::~CTexture() {
  if (texture != NULL) Free();
}

bool CTexture::LoadFromFile(SDL_Renderer * renderer, string path) {
  this->renderer = renderer;
  if (texture != NULL) Free();
  SDL_Texture * newTexture = NULL;
  SDL_Surface * loadedSurface = IMG_Load(path.c_str());
  if (loadedSurface == NULL) {
    cout << "Unable to load image " << path << ": " << SDL_GetError() << endl;
    return false;
  }
  newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
  width = loadedSurface->w;
  height = loadedSurface->h;
  SDL_FreeSurface(loadedSurface);
  if (newTexture == NULL) {
    cout << "Unable to load texture " << path << ": " << SDL_GetError() << endl;
    return false;
  }
  SDL_SetTextureBlendMode(newTexture, SDL_BLENDMODE_BLEND);
  texture = newTexture;
  return true;
}

void CTexture::Free() {
  SDL_DestroyTexture(texture);
}

void CTexture::Render(int x, int y, SDL_Rect * srcRect, int width, int height, int alpha) {
  SDL_Rect rect = {x, y, width, height};
  //std::cout << x << ", " << y << ", " << width << ", " << height <<
  //    ", " << srcRect->x << ", " << srcRect->y <<std::endl;
  SDL_SetTextureAlphaMod(texture, alpha);
  if (SDL_RenderCopy(renderer, texture, srcRect, &rect)) {
    cout << width << ", " << height << endl;
    cout << "Failed to draw texture: " << SDL_GetError() << endl;
  }
}

void CTexture::RenderEx(int x, int y, SDL_Rect * srcRect, double angle,
    SDL_Point * center, SDL_RendererFlip flip, int width, int height, int alpha) {
  //std::cout << x << ", " << y << std::endl;
  SDL_Rect rect = {x, y, width, height};
  SDL_SetTextureAlphaMod(texture, alpha);
  SDL_RenderCopyEx(renderer, texture, srcRect, &rect, angle, center, flip);
}

int CTexture::GetWidth() {
  return width;
}

int CTexture::GetHeight() {
  return height;
}

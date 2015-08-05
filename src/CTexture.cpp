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

void CTexture::Render(int x, int y) {
  cout << x << ", " << y << endl;
  SDL_Rect rect = {x, y, width, height};
  SDL_Rect origin = {0, 0, width, height};
  if (SDL_RenderCopy(renderer, texture, &origin, &rect)) {
    cout << width << ", " << height << endl;
    cout << "Failed to draw texture: " << SDL_GetError() << endl;
  }
  //SDL_RenderPresent(renderer);
}

void CTexture::RenderEx(int x, int y, double angle,
    SDL_Point * center, SDL_RendererFlip flip) {
  SDL_Rect rect = {x, y, width, height};
  SDL_RenderCopyEx(renderer, texture, NULL, &rect, angle, center, flip);
  //SDL_RenderPresent(renderer);
}

int CTexture::GetWidth() {
  return width;
}

int CTexture::GetHeight() {
  return height;
}

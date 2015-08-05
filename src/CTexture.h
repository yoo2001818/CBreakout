/*
 * CTexture.h
 *
 *  Created on: 2015. 8. 4.
 *      Author: yoo2001818
 */

#ifndef SRC_CTEXTURE_H_
#define SRC_CTEXTURE_H_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class CTexture {
public:
  CTexture();
  virtual ~CTexture();

  bool LoadFromFile(SDL_Renderer * renderer, std::string path);

  void Free();
  void Render(int x, int y);
  void RenderEx(int x, int y, double angle,
    SDL_Point * center, SDL_RendererFlip flip);

  int GetWidth();
  int GetHeight();

private:
  SDL_Renderer * renderer;
  SDL_Texture * texture;
  int width;
  int height;
};

#endif /* SRC_CTEXTURE_H_ */

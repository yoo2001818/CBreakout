/*
 * CTexture.h
 *
 *  Created on: 2015. 8. 4.
 *      Author: yoo2001818
 */

#ifndef SRC_CTEXTURE_H_
#define SRC_CTEXTURE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class CTexture {
public:
  CTexture();
  virtual ~CTexture();

  bool LoadFromFile(std::string path);

  void Free();
  void Render(SDL_Renderer * renderer, int x, int y);

  int GetWidth();
  int GetHeight();

private:
  SDL_Texture * texture;
  int width;
  int height;
};

#endif /* SRC_CTEXTURE_H_ */

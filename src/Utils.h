/*
 * Utils.h
 *
 *  Created on: 2015. 8. 4.
 *      Author: yoo2001818
 */

#ifndef SRC_UTILS_H_
#define SRC_UTILS_H_

#include <iostream>
#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture * LoadTexture(SDL_Renderer * renderer, std::string path) throw();

#endif /* SRC_UTILS_H_ */

#ifndef __C_BREAKOUT_CONFIG_H__
  #define __C_BREAKOUT_CONFIG_H__
  #define APP_WIDTH 800
  #define APP_HEIGHT 600
  #define APP_NAME "Breakout"
  #if DIRECTX
    // Why why why why why why why why
    #include <d3dx9.h>
  #else
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
  #endif
#endif

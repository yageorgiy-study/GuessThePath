#ifndef GUESSTHEPATH_SCREEN_H
#define GUESSTHEPATH_SCREEN_H

#include <SDL_render.h>
#include "../assets/AssetsManager.h"

class Game;

class Screen {
public:
    virtual void render(int start_x, int start_y, int window_width, int window_height, SDL_Renderer* renderer, AssetsManager * assetsManager) = 0;
};


#endif //GUESSTHEPATH_SCREEN_H

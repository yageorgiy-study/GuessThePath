#ifndef GUESSTHEPATH_WELCOMESCREEN_H
#define GUESSTHEPATH_WELCOMESCREEN_H

#include "Screen.h"
#include "../assets/AssetsManager.h"

class WelcomeScreen : public Screen {
public:
    void render(int start_x, int start_y, int window_width, int window_height, SDL_Renderer* renderer, AssetsManager * assetsManager) override;
};


#endif //GUESSTHEPATH_WELCOMESCREEN_H

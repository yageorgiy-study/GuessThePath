//
// Created by Gosha on 13.06.2022.
//

#ifndef GUESSTHEPATH_MENUSCREEN_H
#define GUESSTHEPATH_MENUSCREEN_H


#include "Screen.h"

class MenuScreen : public Screen {
public:
    void render(int start_x, int start_y, int window_width, int window_height, SDL_Renderer *renderer,
                AssetsManager *assetsManager) override;
};


#endif //GUESSTHEPATH_MENUSCREEN_H

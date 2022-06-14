//
// Created by Gosha on 14.06.2022.
//

#ifndef GUESSTHEPATH_SWITCHPLAYERSCREEN_H
#define GUESSTHEPATH_SWITCHPLAYERSCREEN_H


#include "Screen.h"

class SwitchPlayerScreen : public Screen {
public:
    SwitchPlayerScreen(Game *game);

    void renderBackground(int start_x, int start_y) override;

    void leftMouseClicked(SDL_MouseButtonEvent &b) override;
};


#endif //GUESSTHEPATH_SWITCHPLAYERSCREEN_H

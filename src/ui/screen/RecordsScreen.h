//
// Created by Gosha on 14.06.2022.
//

#ifndef GUESSTHEPATH_RECORDSSCREEN_H
#define GUESSTHEPATH_RECORDSSCREEN_H


#include "Screen.h"

class RecordsScreen : public Screen {
public:
    RecordsScreen(Game *game);

    void renderBackground(int start_x, int start_y) override;

    void leftMouseClicked(SDL_MouseButtonEvent &b) override;
};


#endif //GUESSTHEPATH_RECORDSSCREEN_H

//
// Created by Gosha on 15.06.2022.
//

#ifndef GUESSTHEPATH_BOMB_H
#define GUESSTHEPATH_BOMB_H


#include "Cell.h"

class Bomb : public Cell {
protected:
    short type = 1;
public:
    static const short VALUE = 1;

    Bomb(Game *game);
    void render(int x, int y, bool forceShown) override;
};


#endif //GUESSTHEPATH_BOMB_H

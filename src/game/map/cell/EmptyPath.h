//
// Created by Gosha on 15.06.2022.
//

#ifndef GUESSTHEPATH_EMPTYPATH_H
#define GUESSTHEPATH_EMPTYPATH_H


#include "Cell.h"

class EmptyPath : public Cell {
protected:
    short type = 0;

public:
    static const short VALUE = 0;

    EmptyPath(Game *game);
    void render(int x, int y) override;
};


#endif //GUESSTHEPATH_EMPTYPATH_H

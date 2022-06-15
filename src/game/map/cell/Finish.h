#ifndef GUESSTHEPATH_FINISH_H
#define GUESSTHEPATH_FINISH_H


#include "Cell.h"

class Finish : public Cell {
protected:
    short type = 2;

public:
    static const short VALUE = 2;

    Finish(Game *game);
    void render(int x, int y) override;
};


#endif //GUESSTHEPATH_FINISH_H

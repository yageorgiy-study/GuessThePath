#ifndef GUESSTHEPATH_SCREEN_H
#define GUESSTHEPATH_SCREEN_H

class Game;

class Screen {
protected:
    Game* game = nullptr;

public:
    Screen(Game *game);

    virtual void render(int start_x, int start_y) = 0;
};


#endif //GUESSTHEPATH_SCREEN_H

#ifndef GUESSTHEPATH_SCREEN_H
#define GUESSTHEPATH_SCREEN_H

#include <SDL_render.h>
#include <vector>
#include "../../assets/AssetsManager.h"
#include "../Renderable.h"

class Game;

class Screen {
protected:
    Game * game;
    std::vector<Renderable *> elements;

public:
    Screen(Game *game);

    virtual ~Screen();

    void renderElements(int start_x, int start_y);
    virtual void renderBackground(int start_x, int start_y) = 0;
    void render(int start_x, int start_y);
    void add(Renderable* r);
};


#endif //GUESSTHEPATH_SCREEN_H
#ifndef GUESSTHEPATH_GAMESCREEN_H
#define GUESSTHEPATH_GAMESCREEN_H


#include "Screen.h"
#include "../../game/map/Map.h"

class GameScreen : public Screen {
public:
    GameScreen(Game *game);

    Map * map;
    int timeStarted = -1;

    void renderBackground(int start_x, int start_y) override;
    void leftMouseClicked(SDL_MouseButtonEvent &b) override;
    void keyUp(SDL_KeyboardEvent &e) override;
    void keyDown(SDL_KeyboardEvent &e) override;
};


#endif //GUESSTHEPATH_GAMESCREEN_H

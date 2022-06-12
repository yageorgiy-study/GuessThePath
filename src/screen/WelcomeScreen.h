#ifndef GUESSTHEPATH_WELCOMESCREEN_H
#define GUESSTHEPATH_WELCOMESCREEN_H

#include "Screen.h"

class WelcomeScreen : public Screen {
public:
    WelcomeScreen(Game *game);

private:
    void render(int start_x, int start_y) override;
};


#endif //GUESSTHEPATH_WELCOMESCREEN_H

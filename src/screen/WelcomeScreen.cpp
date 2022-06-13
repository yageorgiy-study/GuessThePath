#include <iostream>
#include <SDL_rect.h>
#include "WelcomeScreen.h"

void WelcomeScreen::render(int start_x, int start_y, int window_width, int window_height, SDL_Renderer *renderer, AssetsManager * assetsManager) {

    auto startup = assetsManager->assets[Asset::Textures::STARTUP];

    auto pos = startup->getRect();
    pos->x = window_width / 2 - pos->w / 2;
    pos->y = window_height / 2 - pos->h / 2;

    startup->render(pos);
}

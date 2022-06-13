#include <iostream>
#include <SDL_rect.h>
#include <SDL_timer.h>
#include "WelcomeScreen.h"

#include "../../Game.h"
#include "MenuScreen.h"

void WelcomeScreen::renderBackground(int start_x, int start_y) {
    auto assetsManager = game->assetManager;
    auto window_width = game->window_width;
    auto window_height = game->window_height;

    auto startupTexture = assetsManager->assets[Asset::Textures::STARTUP];

    auto pos = startupTexture->getRect();
    pos->x = window_width / 2 - pos->w / 2;
    pos->y = window_height / 2 - pos->h / 2;

    startupTexture->render(pos);

    if(SDL_GetTicks() > this->waitMs){
        this->game->switchScreen(new MenuScreen(this->game));
    }
}

WelcomeScreen::WelcomeScreen(Game *game) : Screen(game) {}

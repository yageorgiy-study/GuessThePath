#include <iostream>
#include <SDL_rect.h>
#include "WelcomeScreen.h"

void WelcomeScreen::render(int start_x, int start_y, int window_width, int window_height, SDL_Renderer *renderer, AssetsManager * assetsManager) {
    /*
    int offset = 10;
    int size = 3;
    int screenport_x = 7;
    int screenport_y = 10;

    SDL_Rect squareRect;

    squareRect.w = window_width - 2 * offset;
    squareRect.h = size;
    squareRect.x = offset;
    squareRect.y = window_height / 2 - size / 2;

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderFillRect(renderer, &squareRect);

    // левая линия
    squareRect.w = size;
    squareRect.h = window_height - 2 * offset;
    squareRect.x = window_width / 2 - size / 2;
    squareRect.y = offset;

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderFillRect(renderer, &squareRect);
    */

    auto startup = assetsManager->assets[Asset::Textures::STARTUP];

    auto pos = startup->getRect();
    pos->x = window_width / 2 - pos->w / 2;
    pos->y = window_height / 2 - pos->h / 2;

//    std::cout << "w: " << pos->w << " h:" << pos->h << std::endl;

    startup->render(pos);
}

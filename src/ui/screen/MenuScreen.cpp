#include "MenuScreen.h"
#include "../../Game.h"
#include "../Text.h"
#include "../text/TitleText.h"
#include "../Button.h"

void MenuScreen::renderBackground(int start_x, int start_y) {
//    auto assetsManager = game->assetManager;
    auto window_width = game->window_width;
    auto window_height = game->window_height;
    auto renderer = game->renderer;

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

    // Title text

    auto* titleText = this->elements[0];

    std::string tmp = "" + std::to_string(game->mouse_x) + " " + std::to_string(game->mouse_y);
    ((TitleText *)titleText)->setText(tmp);

    titleText->x = game->window_width / 2 - titleText->w / 2;
    titleText->y = 100;

    for(int i = 1; i < this->elements.size(); i++){
        auto* btn = this->elements[i];
        btn->w = 300;
        btn->h = game->window_height / 12;
        btn->x = game->window_width / 2 - btn->w / 2;
        btn->y = 250 + (i-1) * (btn->h + 10);
    }

}

MenuScreen::MenuScreen(Game *game) : Screen(game) {
    this->add(new TitleText(game->renderer, "Главное меню"));

    this->add(new Button(game->renderer, "Играть"));
    this->add(new Button(game->renderer, "Смена игрока"));
    this->add(new Button(game->renderer, "Рекорды"));
    this->add(new Button(game->renderer, "Справка"));
    this->add(new Button(game->renderer, "Выход"));
}

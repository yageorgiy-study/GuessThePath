//
// Created by Gosha on 14.06.2022.
//

#include "GameScreen.h"
#include "../Defaults.h"
#include "../text/InfoText.h"
#include "../button/BackButton.h"
#include "MenuScreen.h"

GameScreen::GameScreen(Game *game) : Screen(game) {
    this->map = new Map(game, 0, 0);
    this->map->generateMap();
    this->add(this->map);

    // Информационное сообщение
    this->add(new InfoText(game, "Lorem ipsum"));

    // Время
    this->add(new InfoText(game, ""));

    this->add(new BackButton(game, new MenuScreen(game)));
}

void GameScreen::renderBackground(int start_x, int start_y) {

    if(timeStarted <= -1)
        timeStarted = SDL_GetTicks();

    int window_width = this->game->window_width;
    int window_height = this->game->window_height;

    int mapOffset = 100;
    int size = std::min(window_width, window_height);

    this->map->w = size - mapOffset;
    this->map->h = size - mapOffset;
    this->map->x = window_width / 2  - this->map->w / 2;
    this->map->y = window_height / 2 - this->map->h / 2;

    auto statusText = (InfoText *)this->elements[1];
    statusText->x = 130;
    statusText->y = 15;

    auto timeText = (InfoText *)this->elements[2];
    timeText->x = 15;
    timeText->y = window_height - timeText->h - 15;
    timeText->setText("Потраченное время: " + std::to_string((SDL_GetTicks() - timeStarted) / 1000) + " сек");

    auto backButton = this->elements[3];
    backButton->x = 10;
    backButton->y = 10;
    backButton->w = 300 / 3;
    backButton->h = 100 / 3;
    /*
    SDL_Rect squareRect;
    squareRect.w = this->map->w;
    squareRect.h = this->map->h;
    squareRect.x = this->map->x;
    squareRect.y = this->map->y;

    auto buttonColor = Defaults::BUTTON_COLOR();

    SDL_SetRenderDrawColor(this->game->renderer, buttonColor.r, buttonColor.g, buttonColor.b, buttonColor.a);
    SDL_RenderFillRect(this->game->renderer, &squareRect);
    */
//    this->map->x = 0;
//    this->map->y = 0;
}

void GameScreen::leftMouseClicked(SDL_MouseButtonEvent &b) {

}

void GameScreen::keyUp(SDL_KeyboardEvent &e) {

}

void GameScreen::keyDown(SDL_KeyboardEvent &e) {

}

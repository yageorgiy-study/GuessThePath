//
// Created by Gosha on 14.06.2022.
//

#include "GameScreen.h"
#include "../Defaults.h"
#include "../text/InfoText.h"
#include "../button/BackButton.h"
#include "MenuScreen.h"
#include "../../Utils.h"

GameScreen::GameScreen(Game *game) : Screen(game) {
    this->map = new Map(game, 0, 0);
    this->map->generateMap();
//    this->add(this->map);

    // Информационное сообщение
    this->add(new InfoText(game, "Перемещение по полю: W - вверх, A - влево, S - вниз, D - вправо. Флаг - финиш, человек - игрок (вы)."));

    // Время
    this->add(new InfoText(game, ""));

    this->add(new BackButton(game, new MenuScreen(game)));
}

void GameScreen::renderBackground(int start_x, int start_y) {
    if(timeStarted <= -1)
        timeStarted = SDL_GetTicks();

    int timeElapsed = getTimeElapsed();

    int window_width = this->game->window_width;
    int window_height = this->game->window_height;

    int mapOffset = 100;
    int size = std::min(window_width, window_height);

    this->map->w = size - mapOffset;
    this->map->h = size - mapOffset;
    this->map->x = window_width / 2  - this->map->w / 2;
    this->map->y = window_height / 2 - this->map->h / 2;
    this->map->showAll = timeElapsed < 0 || this->map->win;
    this->map->callRender(start_x, start_y);

    auto statusText = (InfoText *)this->elements[0];
    statusText->x = 130;
    statusText->y = 15;


    // Time text
    auto timeText = (InfoText *)this->elements[1];
    timeText->x = 15;
    timeText->y = window_height - timeText->h - 15;
    if (map->win) {
        timeText->setText("Вы выйграли эту игру!");
    } else if(timeElapsed <= 0) {
        timeText->x = timeText->x + Utils::generateRandomInt(-beReadyShakeRadius, beReadyShakeRadius);
        timeText->y = timeText->y + Utils::generateRandomInt(-beReadyShakeRadius, beReadyShakeRadius);
        timeText->setText(
        "Запомните положение мин за " + std::to_string(-timeElapsed / 1000) + " сек!"
        );
    }
    else if(!map->dead) {
        timeText->setText("Дойдите до финиша. Прошло: " + std::to_string(timeElapsed / 1000) + " сек");
    }
    else if(map->dead) {
        timeText->setText("Вы подорвались на мине. Игра окончена.");
    }


    auto backButton = this->elements[2];
    backButton->x = 10;
    backButton->y = 10;
    backButton->w = 300 / 3;
    backButton->h = 100 / 3;
}

void GameScreen::leftMouseClicked(SDL_MouseButtonEvent &b) {

}

void GameScreen::keyUp(SDL_KeyboardEvent &e) {

}

void GameScreen::keyDown(SDL_KeyboardEvent &e) {
    if(getTimeElapsed() >= 0)
        this->map->keyDown(e);
}

int GameScreen::getTimeElapsed() {
    return ((int)(SDL_GetTicks() - timeStarted) - this->msForRemember);
}

GameScreen::~GameScreen() {
    delete this->map;
}

void GameScreen::win() {
    game->records->addValue(new Record(game->records->username, this->getTimeElapsed()));
}

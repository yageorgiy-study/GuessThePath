#include "SwitchPlayerScreen.h"
#include "../TextField.h"
#include "../text/InfoText.h"

SwitchPlayerScreen::SwitchPlayerScreen(Game *game) : Screen(game) {
    this->add(new InfoText(game, "Введите имя пользователя:"));
    this->add(new TextField(game));
}

void SwitchPlayerScreen::renderBackground(int start_x, int start_y) {

}

void SwitchPlayerScreen::leftMouseClicked(SDL_MouseButtonEvent &b) {

}

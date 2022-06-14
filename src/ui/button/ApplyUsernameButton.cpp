//
// Created by Gosha on 15.06.2022.
//

#include "ApplyUsernameButton.h"
#include "../TextField.h"
#include "../../Game.h"
#include "../screen/MenuScreen.h"

ApplyUsernameButton::ApplyUsernameButton(Game *game, TextField * field) : Button(game, "Изменить имя пользователя") {
    this->textField = field;
}

void ApplyUsernameButton::pressed() {
    if(this->textField->getValue().compare(""))
        this->game->username = this->textField->getValue();

    this->game->switchScreen(new MenuScreen(game));
}

//
// Created by Gosha on 14.06.2022.
//

#ifndef GUESSTHEPATH_EXITBUTTON_H
#define GUESSTHEPATH_EXITBUTTON_H


#include "../Button.h"

class ExitButton : public Button {
public:
    ExitButton(Game *game);

    void pressed() override;
};


#endif //GUESSTHEPATH_EXITBUTTON_H

//
// Created by Gosha on 13.06.2022.
//

#ifndef GUESSTHEPATH_BUTTON_H
#define GUESSTHEPATH_BUTTON_H


#include <string>
#include "Renderable.h"
#include "Text.h"

class Button : public Renderable {
    Text * text = nullptr;
public:

    Button(SDL_Renderer *renderer, std::string textString);
    virtual ~Button();

    void updateText(std::string textString);

    Text *getText() const;
    void setText(std::string text);
    void render(int start_x, int start_y) override;
    void mousePress(SDL_MouseButtonEvent& b) override;

};


#endif //GUESSTHEPATH_BUTTON_H

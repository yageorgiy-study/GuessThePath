//
// Created by Gosha on 13.06.2022.
//

#include "Button.h"
#include "Defaults.h"
#include <SDL_ttf.h>
#include <iostream>

Button::Button(SDL_Renderer *renderer, std::string textString) : Renderable(renderer) {
    this->updateText(std::move(textString));
}

Text *Button::getText() const {
    return text;
}

void Button::setText(std::string text) {
    this->updateText(std::move(text));
}

Button::~Button() {
    delete text;
}

void Button::updateText(std::string textString){
    this->text = new Text(renderer, std::move(textString), TTF_OpenFont(Defaults::DEFAULT_FONT().c_str(), Defaults::BUTTON_FONT_SIZE), Defaults::BUTTON_TEXT_COLOR());
}

void Button::render(int start_x, int start_y) {

//    std::cout << "yoooo";

    SDL_Rect squareRect;
    squareRect.w = this->w;
    squareRect.h = this->h;
    squareRect.x = start_x + this->x;
    squareRect.y = start_y + this->y;

    auto buttonColor = Defaults::BUTTON_COLOR();
    SDL_SetRenderDrawColor(this->renderer, buttonColor.r, buttonColor.g, buttonColor.b, buttonColor.a);
    SDL_RenderFillRect(this->renderer, &squareRect);

    this->text->x = squareRect.x + this->w / 2 - this->text->w / 2;
    this->text->y = squareRect.y + this->h / 2 - this->text->h / 2;
    this->text->render(start_x, start_y);
}

void Button::mousePress(SDL_MouseButtonEvent &b) {

}
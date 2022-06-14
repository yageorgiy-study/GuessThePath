#include <iostream>
#include "Screen.h"

Screen::Screen(Game *game) : game(game) {}

void Screen::add(Renderable * r) {
    this->elements.push_back(r);
}

void Screen::renderElements(int start_x, int start_y) {
    for (auto element : this->elements) {
        element->callRender(start_x, start_y);
    }
}

void Screen::render(int start_x, int start_y) {
    this->renderBackground(start_x, start_y);
    this->renderElements(start_x, start_y);
}

Screen::~Screen() {
    for(auto element : this->elements){
        delete element;
    }
}

void Screen::callLeftMouseClicked(SDL_MouseButtonEvent &b) {
    this->leftMouseClicked(b);

    for(auto element : this->elements){
        element->callLeftMouseClicked(b);
    }
}

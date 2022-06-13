#include <iostream>
#include "Renderable.h"

Renderable::Renderable(SDL_Renderer *renderer) : renderer(renderer) {}

void Renderable::callMousePress(SDL_MouseButtonEvent &b) {
    mousePress(b);
}

void Renderable::callRender(int start_x, int start_y) {
    render(start_x, start_y);
}

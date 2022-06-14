#include "TextField.h"
#include "../Game.h"
#include "Defaults.h"

TextField::TextField(Game *game) : Renderable(game) {
    this->text = new Text(game, "", TTF_OpenFont(Defaults::DEFAULT_FONT().c_str(), Defaults::TEXT_FIELD_FONT_SIZE), Defaults::TEXTFIELD_FONT_COLOR());
}

void TextField::render(int start_x, int start_y) {
    if(this->game == nullptr || this->game->renderer == nullptr) return;

    SDL_Rect squareRect;
    squareRect.w = this->w;
    squareRect.h = this->h;
    squareRect.x = start_x + this->x;
    squareRect.y = start_y + this->y;

    auto textFieldColor = Defaults::TEXTFIELD_COLOR();

    SDL_SetRenderDrawColor(this->game->renderer, textFieldColor.r, textFieldColor.g, textFieldColor.b, textFieldColor.a);
    SDL_RenderFillRect(this->game->renderer, &squareRect);

    this->text->x = squareRect.x + this->w / 2 - this->text->w / 2;
    this->text->y = squareRect.y + this->h / 2 - this->text->h / 2;
    this->text->render(start_x, start_y);
}

void TextField::leftMouseClicked(SDL_MouseButtonEvent &b) {
    this->active = isHovered();
}

bool TextField::isActive() const {
    return active;
}

bool TextField::isHovered() {
    int actual_x = game->mouse_x - game->window_x;
    int actual_y = game->mouse_y - game->window_y;
    return (actual_x >= this->x && actual_x <= this->x + this->w &&
            actual_y >= this->y && actual_y <= this->y + this->h);
}

TextField::~TextField() {
    delete this->text;
}


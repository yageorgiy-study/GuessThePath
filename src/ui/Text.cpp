#include "Text.h"

#include <utility>
#include <iostream>

Text::Text(SDL_Renderer *renderer, std::string text, TTF_Font *font, SDL_Color text_color) :
Renderable(renderer), text(std::move(text)), font(font), text_color(text_color) {
    this->updateSurface();
}

void Text::mousePress(SDL_MouseButtonEvent &b) {

}

void Text::render(int start_x, int start_y) {
    if(this->renderer == nullptr || this->texture == nullptr) return;

    SDL_Rect Message_rect;
    Message_rect.x = start_x + this->x;
    Message_rect.y = start_y + this->y;
    Message_rect.w = this->w;
    Message_rect.h = this->h;

    SDL_RenderCopy(this->renderer, this->texture, NULL, &Message_rect);
}

void Text::updateSurface() {
    if(this->font == nullptr) return;

//    this->surface = TTF_RenderText_Solid(this->font, this->text.c_str(), this->text_color);
//    this->surface = TTF_RenderUNICODE_Blended(this->font, reinterpret_cast<const Uint16 *>(this->text.c_str()), this->text_color);
//    this->surface = TTF_RenderUNICODE_Blended(this->font, reinterpret_cast<const Uint16 *>(L"English текст"), this->text_color);
    this->surface = TTF_RenderUTF8_Blended(this->font, this->text.c_str(), this->text_color);
    this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);

    SDL_QueryTexture(this->texture, NULL, NULL, &this->w, &this->h);
}

const std::string &Text::getText() const {
    return text;
}


const SDL_Color &Text::getTextColor() const {
    return text_color;
}


TTF_Font *Text::getFont() const {
    return font;
}


Text::~Text() {
    if(this->surface != nullptr)
        SDL_FreeSurface(this->surface);
    if(this->texture != nullptr)
        SDL_DestroyTexture(this->texture);
    if(this->font != nullptr)
        TTF_CloseFont(this->font);
}

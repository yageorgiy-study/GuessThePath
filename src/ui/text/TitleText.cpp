#include "TitleText.h"
#include "../Defaults.h"

TitleText::TitleText(SDL_Renderer *renderer, const std::string &text) :
Text(renderer, text, TTF_OpenFont(Defaults::DEFAULT_FONT().c_str(), Defaults::TITLE_FONT_SIZE), Defaults::DEFAULT_COLOR()) {}

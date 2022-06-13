#include "InfoText.h"
#include "../Defaults.h"

InfoText::InfoText(SDL_Renderer *renderer, const std::string &text) :
Text(renderer, text, TTF_OpenFont(Defaults::DEFAULT_FONT().c_str(), Defaults::MEDIUM_FONT_SIZE), Defaults::DEFAULT_COLOR()) {}

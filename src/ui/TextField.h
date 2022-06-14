#ifndef GUESSTHEPATH_TEXTFIELD_H
#define GUESSTHEPATH_TEXTFIELD_H


#include "Renderable.h"
#include "Text.h"

class TextField : public Renderable {
protected:
    bool active = false;
    Text * text = nullptr;
    std::string value = "";
public:
    TextField(Game *game);

    virtual ~TextField();

    int charsVisible = 10;

    void render(int start_x, int start_y) override;
    void leftMouseClicked(SDL_MouseButtonEvent &b) override;

    bool isActive() const;
    bool isHovered() ;
};


#endif //GUESSTHEPATH_TEXTFIELD_H

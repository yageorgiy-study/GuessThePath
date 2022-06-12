//
// Created by Gosha on 13.06.2022.
//

#ifndef GUESSTHEPATH_ASSET_H
#define GUESSTHEPATH_ASSET_H


#include <SDL_surface.h>
#include <SDL_render.h>

class Asset {
//    static const std::string STARTUP = "startup";

public:
    enum Textures {
        STARTUP
    };

    Asset(SDL_Surface *surface, SDL_Renderer* renderer);
    void render(SDL_Rect *Message_rect);
    virtual ~Asset();

    SDL_Rect *getRect() const;

private:
    SDL_Rect* rect;
    SDL_Renderer* renderer = nullptr;
    SDL_Surface* surface = nullptr;
    SDL_Texture* texture = nullptr;
};


#endif //GUESSTHEPATH_ASSET_H

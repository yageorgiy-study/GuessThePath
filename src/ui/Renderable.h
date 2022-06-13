#ifndef GUESSTHEPATH_RENDERABLE_H
#define GUESSTHEPATH_RENDERABLE_H


#include <SDL_render.h>

class Renderable {
public:
    Renderable(SDL_Renderer *renderer);
    int x,y,w,h;

    virtual void render() = 0;
private:

    SDL_Renderer * renderer = nullptr;
};


#endif //GUESSTHEPATH_RENDERABLE_H

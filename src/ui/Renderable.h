#ifndef GUESSTHEPATH_RENDERABLE_H
#define GUESSTHEPATH_RENDERABLE_H


#include <SDL_render.h>
#include <SDL_events.h>

class Renderable {
public:
    Renderable(SDL_Renderer *renderer);
    int x,y,w,h = 0;

    void callRender(int start_x, int start_y);
    void callMousePress(SDL_MouseButtonEvent& b);

    virtual void render(int start_x, int start_y) = 0;
    virtual void mousePress(SDL_MouseButtonEvent& b) = 0;

protected:
    SDL_Renderer * renderer = nullptr;
};


#endif //GUESSTHEPATH_RENDERABLE_H

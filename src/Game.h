#ifndef GUESS_THE_PATH_GAME_H
#define GUESS_THE_PATH_GAME_H

#include <SDL_video.h>
#include <SDL_render.h>
#include <SDL_events.h>
#include "screen/Screen.h"
#include "assets/AssetsManager.h"

class Game {

public:
    Game();

protected:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Event* event;

    Screen* currentScreen = nullptr;

    AssetsManager * assetManager = nullptr;

    int window_height = 0;
    int window_width = 0;

    void render();
    void loadTextures();
    void unloadTextures();

    void pollEvents();


    void switchWelcomeScreen();

//    double step = 1.0f/64;
//    int from = -7;
//    int to = 0;

//    SDL_Surface *fire;
//    SDL_Surface *rocket;

//    SDL_Texture * fire_texture;
//    SDL_Texture * rocket_texture;

    bool forceQuit = false;

public:
    void init(int argc, char* argv[]);
    void switchScreen(Screen* newScreen);

    void startup();
};


#endif //GUESS_THE_PATH_GAME_H

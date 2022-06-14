#ifndef GUESS_THE_PATH_GAME_H
#define GUESS_THE_PATH_GAME_H

#include <SDL_video.h>
#include <SDL_render.h>
#include <SDL_events.h>
#include "ui/screen/Screen.h"
#include "assets/AssetsManager.h"

class Game {

public:
    Game();

protected:
    std::string title = "Guess The Path";

    SDL_Event* event;

    void render();
    void loadTextures();
    void unloadTextures();

    void pollEvents();
    void mouseClicked(SDL_MouseButtonEvent& b);

    //keys
//    bool keys[322];  // 322 is the number of SDLK_DOWN events

    void keyUp(SDL_KeyboardEvent& e);
    void keyDown(SDL_KeyboardEvent& e);

//    double step = 1.0f/64;
//    int from = -7;
//    int to = 0;

//    SDL_Surface *fire;
//    SDL_Surface *rocket;

//    SDL_Texture * fire_texture;
//    SDL_Texture * rocket_texture;

public:
    std::string username = "Player";

    SDL_Renderer* renderer = nullptr;
    SDL_Window* window = nullptr;
    AssetsManager * assetManager = nullptr;
    Screen* currentScreen = nullptr;
    int window_width, window_height, window_x, window_y = 0;

    int mouse_x, mouse_y = 0;

    bool forceQuit = false;

    void init(int argc, char* argv[]);
    void switchScreen(Screen* newScreen);

    void startup();
};


#endif //GUESS_THE_PATH_GAME_H

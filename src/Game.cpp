#include <iostream>
#include <algorithm>
#include <SDL.h>
#include <cmath>
#include <SDL_ttf.h>

#include "Game.h"
#include "ui/screen/WelcomeScreen.h"
#include "ui/screen/MenuScreen.h"

#include <chrono>
#include <thread>
#include <future>


#define PI 3.14159265
#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   800

void Game::init(int argc, char **argv) {
    // Неиспользуемые переменные (для устранения лишних уведомлений "warning")
    (void) argc;
    (void) argv;

    // Инициализация SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0 || TTF_Init() < 0)
    {
        std::cout << "SDL or TTF_Init() could not be initialized!" << std::endl
                  << "SDL_Error: " << SDL_GetError() << std::endl
                  << "TTF_Error: " << TTF_GetError() << std::endl;
        return;
    }

#if defined linux && SDL_VERSION_ATLEAST(2, 0, 8)
    // Инициализация для сервера окон X11 на ОС на базе Linux
    if(!SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0"))
    {
        std::cout << "SDL can not disable compositor bypass!" << std::endl;
        return;
    }
#endif

    // Создание окна
    this->window = SDL_CreateWindow(
            this->title.c_str(),
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );

    if(!this->window) {
        std::cout << "Window could not be created!" << std::endl
                  << "SDL_Error: " << SDL_GetError() << std::endl;
    } else {
        // Создание холста (прорисовщика)
        this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
        if(!this->renderer) {
            std::cout << "Renderer could not be created!" << std::endl
                      << "SDL_Error: " << SDL_GetError() << std::endl;
        } else {
            this->loadTextures();
            this->startup();

            // Фиксированное количество кадров в секунду
            int a, b, delta;

            // Цикл рендера
            while(!this->forceQuit) {
                // Get events
                this->pollEvents();

                // фиксация FPS
                a = SDL_GetTicks();
                delta = a - b;

                if (delta <= 1000 / 60.0) continue;
                b = a;

                // Размер окна
                SDL_GetWindowSize(this->window, &this->window_width, &this->window_height);

                this->render();

                // Обновить экран
                SDL_RenderPresent(this->renderer);
            }

            this->unloadTextures();



            // Удалить прорисовщик
            SDL_DestroyRenderer(this->renderer);
        }

        // Удалить окно
        SDL_DestroyWindow(this->window);
    }

    // Завершить работу программы
    SDL_Quit();
}

void Game::render() {
//    int ticks = SDL_GetTicks();
    // Declare rect of square
//    SDL_Rect squareRect;

    // Square dimensions: Half of the min(SCREEN_WIDTH, SCREEN_HEIGHT)
//    squareRect.w = std::min(this->window_width, this->window_height) / 2;
//    squareRect.h = std::min(this->window_width, this->window_height) / 2;

    // Square position: In the middle of the screen
//    squareRect.x = this->window_width / 2 - squareRect.w / 2;
//    squareRect.y = this->window_height / 2 - squareRect.h / 2;

    // Set renderer color red to draw the square
//    SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0x00, 0xFF);
    // Draw filled square
//    SDL_RenderFillRect(this->renderer, &squareRect);

    // Установить цвет очистки экрана
    SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // Очистить экран
    SDL_RenderClear(this->renderer);

    this->currentScreen->render(0, 0);

//    int offset = 10;
//    int size = 3;
//    int screenport_x = 7;
//    int screenport_y = 10;


//    SDL_SetRenderDrawColor(this->renderer, 0x00, 0x00, 0x00, 0x00);
//    SDL_RenderDrawLine(this->renderer, offset, this->window_height - offset, this->window_width - offset, this->window_height - offset);

/*
    // Declare rect of square
    SDL_Color text_color = {0, 0, 0};
    TTF_Font *font = TTF_OpenFont("font.ttf", 24);

    SDL_Surface* surfaceMessage =
            TTF_RenderText_Solid(font, (new std::string("x = "))->data(), text_color);

    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 10;  //controls the rect's x coordinate
    Message_rect.y = 10; // controls the rect's y coordinte
    Message_rect.w = 100; // controls the width of the rect
    Message_rect.h = 50; // controls the height of the rect

    SDL_RenderCopy(this->renderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
*/

//    SDL_Rect squareRect;

    // Graph
//    for(double i = this->from; i <= this->to; i += this->step){
//        double value = this->getFormula(i);

//        double size = (int)abs(this->from - this->to);

//        squareRect.w = 1;
//        squareRect.h = -(value / screenport_y) * this->window_height;
//        squareRect.x = (this->window_width / 2) + (i / screenport_y) * (this->window_width / 2 - offset);
//        squareRect.y = this->window_height / 2;

//        std::cout << squareRect.w << " " << squareRect.h << " " << squareRect.x << " " << squareRect.y << std::endl;

//        SDL_SetRenderDrawColor(this->renderer, 0xFF, 0x00, 0x00, 0x00);
//        SDL_RenderFillRect(this->renderer, &squareRect);

//    }

/*
    // нижняя линия
    squareRect.w = this->window_width - 2 * offset;
    squareRect.h = size;
    squareRect.x = offset;
    squareRect.y = this->window_height / 2 - size / 2;

    SDL_SetRenderDrawColor(this->renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderFillRect(this->renderer, &squareRect);

    // левая линия
    squareRect.w = size;
    squareRect.h = this->window_height - 2 * offset;
    squareRect.x = this->window_width / 2 - size / 2;
    squareRect.y = offset;

    SDL_SetRenderDrawColor(this->renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderFillRect(this->renderer, &squareRect);
*/

    /* Рокета */
//    int rocket_w, rocket_h, rocket_x, rocket_y = 0;
//    int rocket_ms = 4000;
//    if(this->rocket && this->rocket_texture){
//        rocket_w = this->rocket->w;
//        rocket_h = this->rocket->h;
//        rocket_x = this->window_width - offset - rocket_w;
//
//        rocket_y = (int)round((double)(ticks % rocket_ms) / rocket_ms * (this->window_height + rocket_h)); // +rocket_h = зазор сверху ещё
//        rocket_y = this->window_height - rocket_y;
//
//        SDL_Rect dstrect = {rocket_x, rocket_y, rocket_w, rocket_h};
//        SDL_RenderCopy(this->renderer, this->rocket_texture, NULL, &dstrect);
//    }

    // Параметры огня
//    int fire_w, fire_h = 0;
//    int fire_ms = 1000;
//    int tail = 50;
//    int fire_count = 3;
    // Прорисовка огня
//    if(this->fire && this->fire_texture){
//        fire_w = this->fire->w;
//        fire_h = this->fire->h;
//
//        int start_x = rocket_x + rocket_w / 2 - fire_w / 2;
//        int start_y = rocket_y + rocket_h - 30 - fire_h / 2;
//
//        start_y += (int)round((double)(ticks % fire_ms) / fire_ms * (tail));
//
//        double max_degree = 30;
//        double _step = (double)(max_degree * 2) / fire_count;
//        for(int i = 0; i < fire_count; i++){
//            int degree = (int)((double)(ticks % fire_ms) / fire_ms * max_degree);
//
//            start_x *= (cos(degree * PI / 180));
//
//            SDL_Rect dstrect = {start_x, start_y, 16, 16};
//            SDL_RenderCopy(this->renderer, this->fire_texture, NULL, &dstrect);
//            max_degree -= _step;
//        }
//    }
}

Game::Game() {
    this->event = new SDL_Event;
}

void Game::loadTextures() {
    this->assetManager = new AssetsManager(this->renderer);

    // Основные текстуры
    this->assetManager->addAssetFromBMP(Asset::Textures::STARTUP, "res/images/startup.bmp");
}

void Game::unloadTextures() {
    delete this->assetManager;
}

void Game::pollEvents() {
    // вытаскиваем события
    SDL_PollEvent(this->event); // или SDL_WaitEvent
    // Если событие выхода
    if(this->event->type == SDL_QUIT)
    {
        this->forceQuit = true;
        return;
    }

}

void Game::startup() {
    auto welcomeScreen = new WelcomeScreen(this);
    this->switchScreen((Screen *)welcomeScreen);
//    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
//    std::thread t(&Game::switchWelcomeScreen, this);
//    t.join();
}

void Game::switchScreen(Screen *newScreen) {
    delete this->currentScreen;
    this->currentScreen = newScreen;
}



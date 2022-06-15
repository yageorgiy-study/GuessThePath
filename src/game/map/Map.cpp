#include <random>
#include <iostream>
#include <ctime>
#include "Map.h"
#include "cell/Bomb.h"
#include "cell/EmptyPath.h"
#include "cell/Finish.h"

Map::Map(Game * game, int player_x, int player_y) : Renderable(game) {
    this->player_x = player_x;
    this->player_y = player_y;
    this->game = game;

    this->cells = (new Cell**[this->height]);
    for(int i = 0; i < this->height; i++)
    {
        this->cells[i] = new Cell*[this->width];
        for(int j = 0; j < this->width; j++)
        {
            this->cells[i][j] = nullptr;
        }
    }
}

Map::~Map() {
    for(int i = 0; i < this->height; i++)
        delete this->cells[i];
    delete []this->cells;
}

void Map::generateMap() {
    for(int i = 0; i < this->height; i++)
        for(int j = 0; j < this->width; j++)
        {
            if(this->cells[i][j])
                delete this->cells[i][j];

            this->cells[i][j] = new EmptyPath(this->game);
//            this->cells[i][j]->setVisited(true);
        }

    // generate bombs
    for(int i = 0; i < 10; i++)
    {
        auto h = generateRandomInt(0, this->height - 1);
        auto w = generateRandomInt(0, this->width - 1);
        std::cout << "asddas: " << w << " " << h << std::endl;

        this->cells[h][w] = new Bomb(this->game);
//        this->cells[h][w]->setVisited(true);
    }

    // player cell
    this->cells[this->player_y][this->player_x]->setVisited(true);

    // finish cell
    this->cells[this->height - 1][this->width - 1] = new Finish(this->game);
    this->cells[this->height - 1][this->width - 1]->setVisited(true);
}

// Returns a random integer within the range [min, max]
int Map::generateRandomInt(const int min, const int max) {
    static bool is_seeded = false;
    static std::mt19937 generator;

    // Seed once
    if (!is_seeded) {
        std::random_device rd;
        generator.seed(rd());
        is_seeded = true;
    }

    // Use mersenne twister engine to pick a random number
    // within the given range
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

void Map::render(int start_x, int start_y) {
    for(int i = 0; i < this->height; i++)
        for(int j = 0; j < this->width; j++)
        {
            auto cell = this->cells[i][j];
            if(cell == nullptr) continue;

            cell->w = (int)round((double)this->w / this->width);
            cell->h = (int)round((double)this->h / this->height);
            cell->render(start_x + this->x + cell->w * (i), start_y + this->y + cell->h * (j));
        }
}

void Map::leftMouseClicked(SDL_MouseButtonEvent &b) {

}

void Map::keyUp(SDL_KeyboardEvent &e) {

}

void Map::keyDown(SDL_KeyboardEvent &e) {

}

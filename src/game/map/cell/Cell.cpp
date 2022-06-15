#include "Cell.h"

void Cell::callRender(int x, int y) {
    this->render(x, y);
}

Cell::Cell(Game *game) {
    this->game = game;
}

bool Cell::isVisited() const {
    return visited;
}

void Cell::setVisited(bool visited) {
    Cell::visited = visited;
}

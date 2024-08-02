#include "../../include/board/cell.hpp"

Cell::Cell() : obstacle(nullptr) {}

Cell::~Cell() {
    delete obstacle;
}

void Cell::setObstacle(Obstacle* obs) {
    delete obstacle; // Supprime l'ancien obstacle s'il existe
    obstacle = obs;
}

void Cell::update() {
    if (obstacle) {
        obstacle->move(); // Mettre à jour l'obstacle
    }
}

void Cell::draw() {
    if (obstacle) {
        obstacle->draw(); // Dessiner l'obstacle
    }
}

Obstacle* Cell::getObstacle() const {
    return obstacle;
}

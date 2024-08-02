#include "../../include/obstacles/obstacle.hpp"

// Implémentations génériques des méthodes d'Obstacle si nécessaire.
Obstacle::Obstacle(Point pos, int spd, int w, int h)
    : position(pos), speed(spd), width(w), height(h) {}

bool Obstacle::checkCollision(Frog* frog) {
    Point frogPos = frog->getPosition();
    return (frogPos.x < position.x + width && frogPos.x > position.x - width &&
            frogPos.y < position.y + height && frogPos.y > position.y - height);
}

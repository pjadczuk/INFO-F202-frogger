#include "../include/frog.hpp"

Frog::Frog(Point startPos, int initLives)
    : position(startPos), lives(initLives), direction(Direction::Up), speed(5) {}

void Frog::move(Direction dir) {
    direction = dir;
    switch (dir) {
    case Direction::Up:    position.y -= speed; break;
    case Direction::Down:  position.y += speed; break;
    case Direction::Left:  position.x -= speed; break;
    case Direction::Right: position.x += speed; break;
    }
}

void Frog::loseLife() { if (lives > 0) --lives; }

void Frog::resetPosition(Point startPos) { position = startPos; }

void Frog::draw() {
    fl_color(FL_GREEN);
    fl_rectf(position.x - 10, position.y - 10, 20, 20);
}

int Frog::getLives() const { return lives; }

Point Frog::getPosition() const { return position; }

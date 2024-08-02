#include "../../include/obstacles/turtle.hpp"
#include <FL/fl_draw.H>

Turtle::Turtle(Point pos, int spd)
    : Obstacle(pos, spd, 30, 20)
{}

void Turtle::move() {
    position.x += speed;
    // Si la tortue sort de l'écran, la repositionner
    if (position.x > 500) {
        position.x = 0;
    }
}

void Turtle::draw() {
    fl_color(FL_DARK_CYAN);
    fl_rectf(position.x - width / 2, position.y - height / 2, width, height);
}

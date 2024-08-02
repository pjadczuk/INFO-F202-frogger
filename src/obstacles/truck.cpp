#include "../../include/obstacles/truck.hpp"
#include <FL/fl_draw.H>

Truck::Truck(Point pos, int spd)
    : Obstacle(pos, spd, 80, 20) // largeur = 80, hauteur = 20
{}

void Truck::move() {
    position.x += speed;
    // Si le camion sort de l'écran, le repositionner
    if (position.x > 500) {
        position.x = 0;
    }
}

void Truck::draw() {
    fl_color(FL_BLUE);
    fl_rectf(position.x - width / 2, position.y - height / 2, width, height);
}

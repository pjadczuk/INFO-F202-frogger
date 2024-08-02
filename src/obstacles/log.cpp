#include "../../include/obstacles/log.hpp"
#include <FL/fl_draw.H>

Log::Log(Point pos, int spd)
    : Obstacle(pos, spd, 100, 20) // largeur = 100, hauteur = 20
{}

void Log::move() {
    position.x += speed;
    // Si la bûche sort de l'écran, la repositionner
    if (position.x > 500) {
        position.x = 0;
    }
}

void Log::draw() {
    fl_color(FL_BLACK);
    fl_rectf(position.x - width / 2, position.y - height / 2, width, height);
}

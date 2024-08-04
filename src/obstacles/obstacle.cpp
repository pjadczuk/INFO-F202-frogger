#include "../../include/obstacles/obstacle.hpp"


Obstacle::Obstacle(Point pos, int w, int h, Fl_Color col, bool mnt, int spd)
    : position(pos), width(w), height(h), color(col), mountable(mnt), speed(spd) {}

bool Obstacle::contains(Point p) const {
    return (p.x >= position.x && p.x <= position.x + width &&
            p.y >= position.y && p.y <= position.y + height);
}

void Obstacle::move() {
    position.x += speed;
    if (position.x > 910 && speed > 0) position.x = -width; // Repositionner si hors de l'écran
    else if(position.x < -width && speed < 0) position.x =910 + width;
    //else position.x = +width;
}

#include "../../include/obstacles/car.hpp"

Car::Car(Point pos, int w, int h, int spd)
    : Obstacle(pos, w, h, FL_RED, false, spd) {}

void Car::draw() const {
    fl_color(color);
    fl_draw_box(FL_FLAT_BOX, position.x, position.y, width, height, color);
}

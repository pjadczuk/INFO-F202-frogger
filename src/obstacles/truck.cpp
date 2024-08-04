#include "../../include/obstacles/truck.hpp"

Truck::Truck(Point pos, int w, int h, int spd)
    : Obstacle(pos, w, h, FL_DARK_RED, false, spd) {}

void Truck::draw() const {
    fl_color(color);
    fl_draw_box(FL_FLAT_BOX, position.x, position.y, width, height, color);
}

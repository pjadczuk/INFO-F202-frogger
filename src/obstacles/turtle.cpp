#include "../../include/obstacles/turtle.hpp"

Turtle::Turtle(Point pos, int w, int h, int spd)
    : Obstacle(pos, w, h, FL_YELLOW, true, spd) {}

void Turtle::draw() const {
    fl_color(color);
    fl_draw_box(FL_FLAT_BOX, position.x, position.y, width, height, color);
}

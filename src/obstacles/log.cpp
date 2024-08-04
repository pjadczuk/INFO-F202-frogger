#include "../../include/obstacles/log.hpp"
#include <FL/fl_draw.H>

Log::Log(Point pos, int w, int h, int spd)
    : Obstacle(pos, w, h, FL_GRAY, true, spd) {}

void Log::draw() const {
    fl_color(color);
    fl_draw_box(FL_FLAT_BOX, position.x, position.y, width, height, color);
}
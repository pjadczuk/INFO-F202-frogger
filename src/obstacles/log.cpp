#include "../../include/obstacles/log.hpp"
#include <FL/fl_draw.H>

Log::Log(Point pos, int w, int h, int spd)
    : Obstacle(pos, w, h, fl_rgb_color(150, 75, 0), true, spd) {}

void Log::draw() const {
    fl_color(color);
    fl_draw_box(FL_FLAT_BOX, position.x, position.y, width, height, color);
}
#pragma once
#include "obstacle.hpp"

class Turtle : public Obstacle {
public:
    Turtle(Point pos, int w, int h, int spd);
    void draw() const override;
    void setFillColor(Fl_Color newFillColor);
    void setWalkable();
};

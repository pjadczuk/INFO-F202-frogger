#pragma once

#include "obstacle.hpp"

class Turtle : public Obstacle {
public:
    Turtle(Point pos, int spd);
    void move() override;
    void draw() override;
};

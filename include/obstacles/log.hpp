#pragma once

#include "obstacle.hpp"

class Log : public Obstacle {
public:
    Log(Point pos, int spd);
    void move() override;
    void draw() override;
};

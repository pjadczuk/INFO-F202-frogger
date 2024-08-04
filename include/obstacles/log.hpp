#pragma once

#include "obstacle.hpp"

class Log : public Obstacle {
public:
    Log(Point pos, int w, int h, int spd);
    void draw() const override;
};

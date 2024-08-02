#pragma once

#include "obstacle.hpp"

class Truck : public Obstacle {
public:
    Truck(Point pos, int spd);
    void move() override;
    void draw() override;
};

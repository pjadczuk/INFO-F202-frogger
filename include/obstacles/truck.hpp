#pragma once
#include "obstacle.hpp"

class Truck : public Obstacle {
public:
    Truck(Point pos, int w, int h, int spd);
    void draw() const override;
};

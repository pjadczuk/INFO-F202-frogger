#pragma once
#include "obstacle.hpp"

class Car : public Obstacle {
public:
    Car(Point pos, int w, int h, int spd);
    void draw() const override;
};

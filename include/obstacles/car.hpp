#ifndef CAR_HPP
#define CAR_HPP

#include "obstacle.hpp"

class Car : public Obstacle {
public:
    Car(Point pos, int spd);
    void move() override;
    void draw() override;
};

#endif // CAR_HPP

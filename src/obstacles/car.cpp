#include "../../include/obstacles/car.hpp"

Car::Car(Point pos, int spd) : Obstacle(pos, spd, 50, 20) {}

void Car::move() {
    position.x += speed;
    // Logic for resetting position when off-screen
}

void Car::draw() {
    fl_color(FL_RED);
    fl_rectf(position.x - width / 2, position.y - height / 2, width, height);
}

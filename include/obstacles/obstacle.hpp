#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "../point.hpp"
#include "../frog.hpp"


class Obstacle {
protected:
    Point position;
    int speed;
    int width, height;

public:
    Obstacle(Point pos, int spd, int w, int h);
    virtual void move() = 0;
    virtual void draw() = 0;
    virtual bool checkCollision(Frog* frog);
    virtual ~Obstacle() = default;
};

#endif // OBSTACLE_HPP


#pragma once
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "../point.hpp"

class Obstacle {
protected:
    Point position;
    int width;
    int height;
    Fl_Color color;
    bool mountable;
    int speed;

public:
    Obstacle(Point pos, int w, int h, Fl_Color col, bool mountable, int speed);
    virtual ~Obstacle() = default;

    virtual void draw() const = 0; 
    virtual void move(); 
    bool isMountable() const { return mountable; }
    bool contains(Point p) const;
    Point getPosition() const { return position; }
    virtual int getSpeed();
};


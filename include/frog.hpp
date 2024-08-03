#ifndef FROG_HPP
#define FROG_HPP

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "point.hpp"

enum class Direction { Up, Down, Left, Right };

class Frog {
private:
    Point position;
    int lives;
    Direction direction;
    int speed;

public:
    Frog(Point startPos = Point(250, 450), int initLives = 3)
        : position(startPos), lives(initLives){}
    void move(Direction dir);
    void loseLife();
    void resetPosition(Point startPos);
    void draw();
    int getLives() const;
    Point getPosition() const;
};

#endif // FROG_HPP

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

    virtual void draw() const = 0; // Méthode pure virtuelle pour le dessin
    virtual void move();       // Méthode pure virtuelle pour le mouvement
    bool isMountable() const { return mountable; }
    bool contains(Point p) const;
    Point getPosition() const { return position; }
};

class MovingObstacle : public Obstacle {
protected:
    int speed;

public:
    MovingObstacle(Point pos, int w, int h, Fl_Color col, int spd, bool mnt);
    void move() override; // Implémentation de la méthode de déplacement
};

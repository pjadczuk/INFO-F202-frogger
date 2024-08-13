#pragma once
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "point.hpp"

class Shape {
protected:
    Point center;
    int width;
    int height;
    Fl_Color bodyColor;
    int direction; // 0 = Haut, 1 = Droite, 2 = Bas, 3 = Gauche

public:
    Shape(Point initCenter, int w, int h, Fl_Color bodyCol);
    virtual void draw() const;
    virtual Point getCenter() const { return center; }
    virtual int getDirection() const { return direction; }
    virtual int getHeight();
    virtual int getWidth();
    virtual void setDirection(int dir);
    virtual ~Shape() = default; // Ajout d'un destructeur virtuel par défaut
};

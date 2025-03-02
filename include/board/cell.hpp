#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include "../point.hpp"

class Cell {
private:
    int w,h;
    Point center;
    Fl_Color fillColor;
    bool walkable;


public:
    Cell(int w, int h,Point center, Fl_Color fillColor, bool Walkable);
    void draw();
    void setWalkable(bool walkable);
    void setFillColor(Fl_Color fillColor);
    const bool isWalkable() const;
    bool contains(Point center) const;
    Point getCenter() const;
};

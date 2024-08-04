#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include "../point.hpp"

class Cell {
private:
    int w,h;
    Fl_Color fillColor;
    bool walkable;
    Point center;

public:
    Cell(Point center, int w, int h, Fl_Color fillColor, bool Walkable);
    void draw(); // Marquer la méthode comme const
    void setWalkable(bool walkable);
    void setFillColor(Fl_Color fillColor);
    const bool isWalkable() const;
    bool contains(Point center) const;
    Point getCenter() const;
};

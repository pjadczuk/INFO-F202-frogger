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
};

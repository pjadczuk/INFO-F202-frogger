#include "../../include/board/cell.hpp"
#include <iostream>


// Constructeur de la classe Cell
Cell::Cell(Point center, int w, int h, Fl_Color fillColor, bool walkable)
    : center(center), w(w), h(h), fillColor(fillColor), walkable(walkable) {}

// Méthode pour dessiner la cellule
void Cell::draw() {
    fl_draw_box(FL_FLAT_BOX, center.x - w / 2, center.y - h / 2, w, h, fillColor);
}


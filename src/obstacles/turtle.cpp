#include "../../include/obstacles/turtle.hpp"
#include <FL/Enumerations.H>

Turtle::Turtle(Point pos, int w, int h, int spd)
    : Obstacle(pos, w, h, FL_YELLOW, true, spd) {}

void Turtle::draw() const {
    fl_color(color);
    fl_draw_box(FL_FLAT_BOX, position.x, position.y, width, height, color);
}

void Turtle::setFillColor(Fl_Color newFillColor) {
    color = newFillColor;
}

void Turtle::setWalkable() {
    if (mountable){
        // Si montable on change de couleur et on passe en Non montable
        setFillColor(FL_BLUE);
        mountable = !mountable;
    }
    else{
        // Sinon on fait l'inverse
        setFillColor(FL_YELLOW);
        mountable = !mountable;
    }
}

#include "../../include/board/cell.hpp"
#include <FL/Enumerations.H>


Cell::Cell(int w, int h, Point center, Fl_Color fillColor, bool walkable)
    : w(w), h(h), center(center), fillColor(fillColor), walkable(walkable) {}

void Cell::draw() {
    fl_draw_box(FL_FLAT_BOX, center.x - w / 2, center.y - h / 2, w, h, fillColor);
}

Point Cell::getCenter() const {
    return center;
}

void Cell::setFillColor(Fl_Color newFillColor){
    fillColor = newFillColor;
}

/*Pour pouvoir créer les nénuphares du board*/
void Cell::setWalkable(bool walkable){
    this->walkable = walkable;
    if (!walkable) {
        //Quand la grenouille monte sur le nénuphar ce dernier devient non walkable et passe en vert
        setFillColor(FL_GREEN); 
    } else {
        setFillColor(FL_LIGHT1); // On dessine en gris les cases sur lesquels il faut finir
    }
}

const bool Cell::isWalkable() const{
    return walkable;
}

bool Cell::contains(Point p) const {
    return (p.x >= center.x - w/2 && p.x <= center.x + w/2 &&
            p.y >= center.y - h/2 && p.y <= center.y + h/2);
}
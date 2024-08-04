#include "../../include/board/cell.hpp"
#include <FL/Enumerations.H>


// Constructeur de la classe Cell
Cell::Cell(Point center, int w, int h, Fl_Color fillColor, bool walkable)
    : center(center), w(w), h(h), fillColor(fillColor), walkable(walkable) {}

// Méthode pour dessiner la cellule
void Cell::draw() {
    fl_draw_box(FL_FLAT_BOX, center.x - w / 2, center.y - h / 2, w, h, fillColor);
}

Point Cell::getCenter() const {
    return center;
}

void Cell::setFillColor(Fl_Color newFillColor){
    fillColor = newFillColor;
}

void Cell::setWalkable(bool walkable){
    this->walkable = walkable;
    // Vous pouvez également changer la couleur pour indiquer visuellement si la cellule est marchable ou non
    if (!walkable) {
        setFillColor(FL_GREEN); // Exemple de changement de couleur
    } else {
        setFillColor(FL_LIGHT1); // Exemple de couleur par défaut pour les cellules marchables
    }
}

const bool Cell::isWalkable() const{
    return walkable;
}

bool Cell::contains(Point p) const {
    return (p.x >= center.x && p.x <= center.x + w &&
            p.y >= center.y && p.y <= center.y + h);
}
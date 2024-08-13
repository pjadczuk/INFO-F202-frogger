#include "../include/frog.hpp"
#include <iostream>

Frog::Frog(Point initCenter, int w, int h, Fl_Color bodyCol)
    : Shape(initCenter, w, h, bodyCol), onObstacle(false), obstacleMountable(false), posH(1) {
    setInitCenter(initCenter);
}

void Frog::resetToInitialCenter() {
    center = initialCenter;
    posH = 1;
    setDirection(0);
}

// Recupere la position de la grenouille à sa construction
void Frog::setInitCenter(Point initCenter) {
    initialCenter = initCenter;
}

 // 0 = Haut, 1 = Droite, 2 = Bas, 3 = Gauche
void Frog::setDirection(int dir) {
    if (dir < 0 || dir > 3) {
        std::cerr << "Error: Invalid direction value: " << dir << std::endl;
        return;
    }
    direction = dir;
}

void Frog::move(int dx, int dy) {
    center.x += dx;
    center.y += dy;
}

int Frog::getPosHeight() {
    return posH;
}
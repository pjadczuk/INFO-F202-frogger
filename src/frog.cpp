#include "../include/frog.hpp"
#include <iostream>

Frog::Frog(Point initCenter, int w, int h, Fl_Color bodyCol)
    : Shape(initCenter, w, h, bodyCol), onObstacle(false), obstacleMountable(false), posH(1) {
    setInitCenter(initCenter);
}

int Frog::getPosHeight() {
    return posH;
}

void Frog::setInitCenter(Point initCenter) {
    initialCenter = initCenter;
}

void Frog::resetToInitialCenter() {
    center = initialCenter;
    posH = 1;
    setDirection(0);
}

void Frog::move(int dx, int dy) {
    center.x += dx;
    center.y += dy;
}

void Frog::setDirection(int dir) {
    if (dir < 0 || dir > 3) {
        std::cerr << "Error: Invalid direction value: " << dir << std::endl;
        return;
    }
    direction = dir;
}

#pragma once

#include "../include/frog.hpp"
#include <FL/Enumerations.H>
#include <array>
#include <iostream>

Frog::Frog(Point initCenter, int w, int h, Fl_Color bodyCol)
    : center(initCenter), width(w), height(h), bodyColor(bodyCol), direction(0), onObstacle(false), obstacleMountable(false), posH(posH = 1) {
        setInitCenter(initCenter);
    }

void Frog::draw() const {
    // Dessiner le corps de la grenouille (rectangle)
    std::array<Point, 5> bodyPoints{
        Point{center.x - width / 2 , center.y - height / 2 },
        Point{center.x - width / 2 , center.y + height / 2 },
        Point{center.x + width / 2 , center.y + height / 2 },
        Point{center.x + width / 2 , center.y - height / 2 },
        Point{center.x - width / 2 , center.y - height / 2 }
    };
    fl_color(bodyColor);
    fl_begin_polygon();
    for (const auto& point : bodyPoints) {
        fl_vertex(point.x, point.y);
    }
    fl_end_polygon();

    // Dessiner la tête (triangle) pour indiquer la direction
    std::array<Point, 3> headPoints;
    switch (direction) {
        case 0: // Haut
            headPoints = {
                Point{center.x, center.y - height / 2},
                Point{center.x - width /2 , center.y - height / 2 + 10},
                Point{center.x + width /2, center.y - height / 2 + 10}
            };
            break;
        case 1: // Droite
            headPoints = {
                Point{center.x + width / 2, center.y},
                Point{center.x + width / 2-10, center.y - height / 2},
                Point{center.x + width / 2-10, center.y + height / 2}
            };
            break;
        case 2: // Bas
            headPoints = {
                Point{center.x, center.y + height / 2 },
                Point{center.x - width / 2, center.y + height / 2 -10},
                Point{center.x + width / 2, center.y + height / 2 -10}
            };
            break;
        case 3: // Gauche
            headPoints = {
                Point{center.x - width / 2, center.y},
                Point{center.x - width / 2 + 10, center.y - height / 2},
                Point{center.x - width / 2 + 10, center.y + height / 2}
            };
            break;
        default:
            return;
    }

    fl_color(FL_BLACK);
    fl_begin_polygon();
    for (const auto& point : headPoints) {
        fl_vertex(point.x, point.y);
    }
    fl_end_polygon();
}

int Frog::getHeight() {
    return height;
}

int Frog::getWidth() {
    return width;
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



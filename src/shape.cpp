#include "../include/shape.hpp"
#include <array>
#include <iostream>

Shape::Shape(Point initCenter, int w, int h, Fl_Color bodyCol)
    : center(initCenter), width(w), height(h), bodyColor(bodyCol), direction(0) {}

void Shape::draw() const {
    // Dessiner le corps de la forme (rectangle)
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

int Shape::getHeight() {
    return height;
}

int Shape::getWidth() {
    return width;
}

void Shape::setDirection(int dir) {
    if (dir < 0 || dir > 3) {
        std::cerr << "Error: Invalid direction value: " << dir << std::endl;
        return;
    }
    direction = dir;
}

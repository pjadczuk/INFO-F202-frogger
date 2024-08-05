#include "../../include/board/line.hpp"
#include <iostream>


Line::Line(LineType type, int numerLine, Fl_Color cellColor, int cellWidth, int cellHeight,  int numCells)
    : walkable(type != WATER && type != FINISH), type(type), cellHeight(cellHeight), cellWidth(cellWidth), numerLine(numerLine) {
    // Créer les cellules de la ligne
    for (int i = 0; i < numCells; ++i) {
        Point center = {cellWidth * i + cellWidth / 2, cellHeight * (14-numerLine) - cellHeight / 2}; // Positionnement des cellules
        cells.emplace_back(center, cellWidth, cellHeight, cellColor, walkable);
    }
}

Line::~Line() {
    // Libérer les obstacles
    for (auto& obstacle : obstacles) {
        delete obstacle;
        std::cout << "obstacle and Line destructor called" << std::endl;
    }
    obstacles.clear();
}

bool Line::isWalkable() const {
    return walkable;
}

Line::LineType Line::getType() const {
    return type;
}

int Line::getWidth() {
    return cellWidth;
}

int Line::getHeight() {
    return cellHeight;
}

int Line::getNumerLine() {
    return numerLine;
}

void Line::addObstacle(Obstacle* obstacle) {
    if (type != SIDEWALK) { // On ne peut ajouter des obstacles que sur les routes et rivières
        obstacles.push_back(obstacle);
    }
}

void Line::switchWalkableCell(int cellIndex) {
    if (cellIndex >= 0 && cellIndex < cells.size()) {
        cells[cellIndex].setWalkable(true);
    }
}

void Line::drawBackground() {
    // Dessiner les cellules de la ligne (statique)
    for (auto& cell : cells) {
        cell.draw();
    }
}

void Line::drawObstacles() const {
    // Dessiner les obstacles (dynamique)
    for (const auto& obstacle : obstacles) {
        obstacle->draw();
    }
}

std::vector<Cell>& Line::getCells() {
    return cells;
}

const std::vector<Obstacle*>& Line::getObstacles() const {
    return obstacles;
}
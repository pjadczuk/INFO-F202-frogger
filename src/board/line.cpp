#include "../../include/board/line.hpp"
#include <cstddef>



Line::Line(LineType type, int numerLine, Fl_Color cellColor, int cellWidth, int cellHeight,  int numCells)
    : walkable(type != WATER && type != FINISH), type(type), cellHeight(cellHeight), cellWidth(cellWidth), numerLine(numerLine) {
    // Créer les cellules de la ligne
    for (int i = 0; i < numCells; ++i) {
        Point center = {cellWidth * i + cellWidth / 2, cellHeight * (14-numerLine) - cellHeight / 2}; // Positionnement des cellules
        cells.emplace_back(cellWidth, cellHeight, center, cellColor, walkable);
    }
}

Line::~Line() {
    // Free les obstacles
    for (auto& obstacle : obstacles) {
        delete obstacle;
        //std::cout << "obstacle and Line destructor called" << std::endl;
    }
    obstacles.clear();
}

bool Line::isWalkable() const {
    return walkable;
}

void Line::addObstacle(Obstacle* obstacle) {
    if (type != SIDEWALK) { // On peut ajouter des obstacles que sur les routes et rivières
        obstacles.push_back(obstacle);
    }
}

void Line::switchWalkableCell(size_t cellIndex) {
    if (cellIndex >= 0 && cellIndex < cells.size()) {
        cells[cellIndex].setWalkable(true);
    }
}

void Line::drawBackground() {
    // Dessiner les cellules de la ligne, le fond du jeu
    for (auto& cell : cells) {
        cell.draw();
    }
}

void Line::drawObstacles() const {
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
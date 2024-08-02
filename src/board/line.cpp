#include "../../include/board/line.hpp"

Line::Line(bool walkable, int numCells) : walkable(walkable) {
    for (int i = 0; i < numCells; ++i) {
        cells.emplace_back(); // Ajouter des cellules à la ligne
    }
}

bool Line::isWalkable() const {
    return walkable;
}

void Line::update() {
    for (auto& cell : cells) {
        cell.update(); // Mettre à jour chaque cellule
    }
}

void Line::draw() const{
    for (const auto& cell : cells) {
        cell.draw(); // Dessiner chaque cellule
    }
}

void Line::addObstacle(int cellIndex, Obstacle* obstacle) {
    if (cellIndex >= 0 && cellIndex < cells.size()) {
        cells[cellIndex].setObstacle(obstacle);
    }
}

const std::vector<Cell>& Line::getCells() const {
    return cells;
}

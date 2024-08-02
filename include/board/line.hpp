#pragma once
#include <vector>
#include "cell.hpp"

class Line {
private:
    bool walkable; // Peut-on marcher sur cette ligne ?
    std::vector<Cell> cells; // Les cellules de cette ligne

public:
    Line(bool walkable, int numCells);
    bool isWalkable() const;
    void update();
    void draw() const;
    void addObstacle(int cellIndex, Obstacle* obstacle);
    const std::vector<Cell>& getCells() const;
};

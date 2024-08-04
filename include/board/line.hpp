#pragma once
#include <vector>
#include "cell.hpp"
#include "../obstacles/obstacle.hpp"


class Line {
public:
    enum LineType {
        ROAD,
        WATER,
        SIDEWALK
    };

private:
    std::vector<Cell> cells;      // Contient les cellules de la ligne
    std::vector<Obstacle*> obstacles; // Contient les obstacles sur la ligne
    bool walkable;                // Indique si la ligne est marchable
    LineType type;                // Type de la ligne
    int cellHeight;
    int cellWidth;

public:
    Line(LineType type, int numerLine, Fl_Color cellColor, int cellWidth, int cellHeight , int numCells = 14);
    ~Line();

    bool isWalkable() const;
    LineType getType() const;
    void addObstacle(Obstacle* obstacle);
    void drawBackground(); // Dessiner le fond (statique)
    void drawObstacles() const;  // Dessiner les obstacles (dynamique)
    const std::vector<Cell>& getCells() const;
    const std::vector<Obstacle*>& getObstacles() const;
    int getWidth();
    int getHeight();
};

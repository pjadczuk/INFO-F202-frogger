#pragma once
#include "../obstacles/obstacle.hpp"

class Cell {
private:
    Obstacle* obstacle; // Obstacle dans la cellule, s'il y en a un

public:
    Cell();
    ~Cell();
    void setObstacle(Obstacle* obs);
    void update();
    void draw();
    Obstacle* getObstacle() const;
};

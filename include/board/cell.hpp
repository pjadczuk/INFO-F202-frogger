#pragma once
#include "../obstacles/obstacle.hpp"
#include "../obstacles/car.hpp"
#include "../obstacles/truck.hpp"

class Cell {
private:
    Obstacle* obstacle; // Obstacle dans la cellule, s'il y en a un

public:
    Cell();
    ~Cell();
    void setObstacle(Obstacle* obs);
    void update();
    void draw() const; // Marquer la méthode comme const
    Obstacle* getObstacle() const;
};

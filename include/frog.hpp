#pragma once
#include "shape.hpp"
#include "obstacles/obstacle.hpp"

class Obstacle; // Déclaration avancée de la classe Obstacle

class Frog : public Shape {
private:
    Point initialCenter;
    bool onObstacle; // Indique si la grenouille est sur un obstacle
    bool obstacleMountable; // Indique si l'obstacle est montable
    int posH;

public:
    Frog(Point initCenter, int w, int h, Fl_Color bodyCol);
    void move(int dx, int dy = 0);
    void setDirection(int dir) override;
    Point getCenter() const override { return center; }
    int getDirection() const override { return direction; }
   
    bool isOnObstacle() const { return onObstacle; }
    bool isObstacleMountable() const { return obstacleMountable; }
   
    void setInitCenter(Point initCenter);
    void resetToInitialCenter();


    int getPosHeight();
    void incrementPosHeight() { posH++; }
    void decrementPosHeight() { posH--; }
};

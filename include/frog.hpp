#pragma once
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "point.hpp"
#include "obstacles/obstacle.hpp"

class Obstacle; // Déclaration avancée de la classe Obstacle

class Frog {
private:
    Point center;
    Point initialCenter;
    int width;
    int height;
    Fl_Color bodyColor;
    int direction; // 0 = Haut, 1 = Droite, 2 = Bas, 3 = Gauche
    bool onObstacle; // Indique si la grenouille est sur un obstacle
    bool obstacleMountable; // Indique si l'obstacle est montable
    int posH;

public:
    Frog(Point initCenter, int w, int h, Fl_Color bodyCol);
    void draw() const;
    void move(int dx, int dy = 0);
    void setDirection(int dir);
    //void checkCollision(Obstacle* obstacle, bool isWalkable); // Vérifier la collision avec un obstacle
    Point getCenter() const { return center; }
    int getDirection() const { return direction; }
    bool isOnObstacle() const { return onObstacle; }
    bool isObstacleMountable() const { return obstacleMountable; }
    int getHeight();
    int getWidth();
    void setInitCenter(Point initCenter);
    void resetToInitialCenter();
    int getPosHeight();
    void incrementPosHeight(){posH++;}
    void decrementPosHeight(){posH--;}
};

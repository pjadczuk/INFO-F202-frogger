#pragma once
#include <vector>
#include "line.hpp"
#include "../obstacles/car.hpp"
#include "../obstacles/truck.hpp"
#include "../obstacles/log.hpp"
#include "../obstacles/turtle.hpp"
#include "../frog.hpp"

class Board {
private:
    std::vector<Line> lines; // Les lignes du plateau
    Frog frog;
    int score;
    int windowWidth;
    int windowHeight;
    void initialize();
    void addObstaclesToLines();
public:
    Board(int windowWidth, int windowHeight);
    void update();
    void drawBackground();
    void drawObstacles();
    void drawFrog();
    void draw();
    void reset();
    int getScore() const;
    const std::vector<Line>& getLines() const; // Ajout de la méthode getLines
    Frog& getFrog();  // Méthode pour obtenir une référence à la grenouille
    void moveFrogUp();
    void moveFrogDown();
    void moveFrogLeft();
    void moveFrogRight();
    void toggleTurtleWalkable();
    void checkFrogOnLine(Line& line);
    bool isFrogOnFinishCell();
    void setupFinishLinePairs();
};


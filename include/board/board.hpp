#pragma once
#include <vector>
#include "line.hpp"
#include "../obstacles/car.hpp"

class Board {
private:
    std::vector<Line> lines; // Les lignes du plateau
    int score;
    int windowWidth;
    int windowHeight;
    void initialize();
    void addObstaclesToLines();
public:
    Board(int windowWidth, int windowHeight);
    void update();
    void draw();
    void drawObstacles();
    void reset();
    int getScore() const;
    const std::vector<Line>& getLines() const; // Ajout de la méthode getLines
};


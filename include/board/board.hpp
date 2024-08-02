#pragma once
#include <vector>
#include "line.hpp"
#include "../frog.hpp"

class Board {
private:
    std::vector<Line> lines; // Les lignes du plateau
    Frog frog;
    int score;
    int level;
    int lives;

public:
    Board();
    void loadLevel(int newLevel);
    void update();
    void draw();
    void reset();
    Frog& getFrog();
    int getScore() const;
    int getLevel() const;
    int getLives() const;
};

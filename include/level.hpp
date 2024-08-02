#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "../include/obstacles/obstacle.hpp"
#include <vector>

class Level {
private:
    int number;
    std::vector<Obstacle*> obstacles;
    std::vector<Point> targetLilyPads;

public:
    Level(int lvlNumber);
    void loadLevel();
    void addObstacle(Obstacle* obs);
    void draw();
    void update();
    std::vector<Point> getTargetLilyPads() const;
    ~Level();
};

#endif // LEVEL_HPP

#pragma once
#include <vector>
#include <memory>
#include "line.hpp"
#include "../obstacles/car.hpp"
#include "../obstacles/truck.hpp"
#include "../obstacles/log.hpp"
#include "../obstacles/turtle.hpp"
#include "../frog.hpp"
#include "../gameState.hpp"
#include "../texte.hpp"

class Board {
private:
    std::vector<Line> lines; // Les lignes du plateau
    Frog frog;
    int windowWidth;
    int windowHeight;
    void initialize();
    void addObstaclesToLines();
    GameState gameState;
    Text scoreText;
    Text livesText;
    Text timeText;
public:
    Board(int windowWidth, int windowHeight);
    ~Board();
    
    void update();
    void reseting();


    void moveFrogUp();
    void moveFrogDown();
    void moveFrogLeft();
    void moveFrogRight();

    void toggleTurtleWalkable();
    void checkFrogOnLine(Line& line);
    bool isFrogOnFinishCell();
    bool isInsideTheWindow(Point frogCenter);
    void setupFinishLinePairs();
    
    void drawHUD();
    void drawBackground();
    void drawObstacles();
    void drawFrog();

    int getGameLives();
    int getGameScore();
    Frog& getFrog();
    const std::vector<Line>& getLines() const;
};


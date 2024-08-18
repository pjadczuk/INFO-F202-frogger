#pragma once
#include <vector>
#include "line.hpp"
#include "../frog.hpp"
#include "../gameState.hpp"


class Board {
private:
    int windowWidth;
    int windowHeight;
    std::vector<Line> lines; // Les lignes du plateau
    Frog frog;
    GameState gameState;
    void initialize();
    void addObstaclesToLines();

public:
    Board(int windowWidth, int windowHeight);
    ~Board();
    
    void update();
    void reseting();
    void resetHightScore();
    void save();


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


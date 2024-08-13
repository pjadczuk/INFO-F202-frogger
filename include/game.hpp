// game.hpp
#pragma once

#include <memory>
#include "board/board.hpp"


class Game {
private:
    bool gameRunning;
    bool gameWon;
    int windowWidth;
    int windowHeight;
    std::unique_ptr<Board> board;

public:
    Game(int windowWidth, int windowHeight);
    ~Game();
    void start();
    void update();
    void draw();
    void checkGameState();
    bool isGameRunning() const;
    bool isGameWon() const;
    void reset();
    Board* getBoard();

    void startNewGame();
    void handleInput(int key);
};


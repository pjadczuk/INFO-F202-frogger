#pragma once
#include "board/board.hpp"

class InputHandler {
private:
    Board* board;

public:
    InputHandler(Board* b);
    void handleKeyPress(int key);  // Gérer la pression des touches
};

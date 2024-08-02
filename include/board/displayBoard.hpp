#pragma once
#include "board.hpp"

class DisplayBoard {
private:
    Board* board;

public:
    DisplayBoard(Board* b);
    void draw();
};

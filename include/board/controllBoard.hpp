#pragma once
#include "board.hpp"

class ControllBoard {
private:
    Board* board;

public:
    ControllBoard(Board* b);
    bool processEvent(int event);
};

#include <FL/Fl.H>
#include <iostream>
#include "../include/intputHandler.hpp"

// Constructeur
InputHandler::InputHandler(Board* b) : board(b) {}

void InputHandler::handleKeyPress(int key) {
    if (!board) {
        std::cerr << "Error: Board pointer is null." << std::endl;
        return;
    }
    switch (key) {
        case FL_Up:
        case 'z':
            board->moveFrogUp();
            break;
        case FL_Down:
        case 's':
            board->moveFrogDown();
            break;
        case FL_Left:
        case 'q':
            board->moveFrogLeft();
            break;
        case FL_Right:
        case 'd':
            board->moveFrogRight();
            break;
        default:
            break;
    }
}
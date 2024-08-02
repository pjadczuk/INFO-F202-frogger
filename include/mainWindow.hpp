#pragma once
#include <FL/Fl_Window.H>
#include "board.hpp"
#include "displayBoard.hpp"

class MainWindow : public Fl_Window {
private:
    Board board;
    DisplayBoard displayBoard;

public:
    MainWindow(int width, int height, const char* title);
    void draw() override;
};

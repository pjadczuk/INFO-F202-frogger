#pragma once
#include <FL/Fl_Window.H>
#include "board/board.hpp"
#include "intputHandler.hpp"
#include "frog.hpp"

class MainWindow : public Fl_Window {
private:
    Board board;
    InputHandler inputHandler;
public:
    MainWindow(int width, int height, const char* title);
    void drawStaticElements();   // Dessiner les éléments statiques
    void drawDynamicElements();  // Dessiner les éléments dynamiques
    void draw() override;
    int handle(int event) override;
    static void Timer_CB(void *userdata);
};
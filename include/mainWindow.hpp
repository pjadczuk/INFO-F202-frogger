#pragma once
#include <FL/Fl_Window.H>
#include "board/board.hpp"
#include "game.hpp"
#include "frog.hpp"

class MainWindow : public Fl_Window {
private:
    Game game;
    bool displayWelcomeScreen; 
    int width;
    int height;
    static void welcomeScreenCallback(void* userdata);
    void drawWelcomeScreen();
public:
    MainWindow(int width, int height, const char* title);
    void draw() override;
    int handle(int event) override;
    static void Timer_CB(void *userdata);
    static void toggleTurtles_CB(void* userdata);
};
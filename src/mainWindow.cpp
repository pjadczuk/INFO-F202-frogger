#include "../include/mainWindow.hpp"
#include <FL/Fl.H>

MainWindow::MainWindow(int width, int height, const char* title)
    : Fl_Window(width, height, title), board(), displayBoard(&board) {}

void MainWindow::draw() {
    Fl_Window::draw();  // Dessine la fenêtre de base
    displayBoard.draw();  // Dessine le contenu du jeu
}

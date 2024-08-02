#include "../include/displayBoard.hpp"
#include <FL/fl_draw.H>
#include <string>

DisplayBoard::DisplayBoard(Board* b) : board(b) {}

void DisplayBoard::draw() {
    // Dessiner la grenouille
    board->getFrog().draw();

    // Dessiner les obstacles
    for (const auto& obstacle : board->getObstacles()) {
        obstacle->draw();
    }

    // Dessiner d'autres éléments comme le score, les vies, etc.
    fl_color(FL_WHITE);
    fl_draw(("Score: " + std::to_string(board->getScore())).c_str(), 10, 10);
}
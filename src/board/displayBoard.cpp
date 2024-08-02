#include "../../include/board/displayBoard.hpp"
#include <FL/fl_draw.H>
#include <string>

DisplayBoard::DisplayBoard(Board* b) : board(b) {}

void DisplayBoard::draw() {
    // Dessiner la grenouille
    board->getFrog().draw();

    // Dessiner les obstacles via les lignes
    for (const auto& line : board->getLines()) {
        for (const auto& cell : line.getCells()) {
            if (cell.getObstacle() != nullptr) {
                cell.getObstacle()->draw();
            }
        }
    }

    // Dessiner d'autres éléments comme le score, les vies, etc.
    fl_color(FL_WHITE);
    fl_draw(("Score: " + std::to_string(board->getScore())).c_str(), 10, 10);
}
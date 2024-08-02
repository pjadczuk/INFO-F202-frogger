#include "../../include/board/board.hpp"

Board::Board() : score(0), level(1), lives(3), frog(Point(250, 450), 3) {
    loadLevel(1); // Charger le premier niveau
}

void Board::loadLevel(int newLevel) {
    level = newLevel;
    lines.clear(); // Effacer les anciennes lignes

    // Exemple de configuration des lignes pour un niveau
    lines.emplace_back(true, 10); // Ligne 1 (marchable)
    lines.emplace_back(false, 10); // Ligne 2 (non marchable)
    // Ajoutez d'autres lignes et configurez les obstacles

    // Exemple d'ajout d'obstacles
    lines[0].addObstacle(2, new Car(Point(0, 100), 2));
    lines[1].addObstacle(5, new Truck(Point(0, 200), 3));
}

void Board::update() {
    for (auto& line : lines) {
        line.update(); // Mettre à jour chaque ligne
    }
}

void Board::draw() {
    for (const auto& line : lines) {
        line.draw(); // Dessiner chaque ligne
    }
    frog.draw(); // Dessiner la grenouille
}

void Board::reset() {
    // Réinitialiser le plateau
    score = 0;
    lives = 3;
    loadLevel(1);
}

Frog& Board::getFrog() {
    return frog;
}

int Board::getScore() const {
    return score;
}

int Board::getLevel() const {
    return level;
}

int Board::getLives() const {
    return lives;
}

const std::vector<Line>& Board::getLines() const {
    return lines;
}

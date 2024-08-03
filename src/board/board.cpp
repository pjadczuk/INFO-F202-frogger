#include "../../include/board/board.hpp"

Board::Board(int windowWidth, int windowHeight)
    : windowWidth(windowWidth), windowHeight(windowHeight), score(0) {
    initialize();
}

void Board::initialize() {
    lines.clear(); // Effacer les anciennes lignes, s'il y en a

	int numLines = 14; 
	int numCellsInLines = 14;
    int cellWidth = windowWidth / numCellsInLines; 
    int cellHeight = windowHeight / numLines; 

    lines.emplace_back(Line::SIDEWALK, 1,FL_MAGENTA, cellWidth, cellHeight);

    // Lignes 1 à 5 : Routes
    for (int numerLine = 2; numerLine <= 6; numerLine++) {
        lines.emplace_back(Line::ROAD, numerLine, FL_BLACK, cellWidth, cellHeight);
    }
	// Ligne 6 : Trottoir
	lines.emplace_back(Line::SIDEWALK, 7,FL_MAGENTA, cellWidth, cellHeight);

    // Lignes 7 à 12 : Rivières
    for (int numerLine = 8; numerLine <= 12; numerLine++) {
        lines.emplace_back(Line::WATER, numerLine, FL_BLUE, cellWidth, cellHeight);
    }

    // Ligne 13 : Trottoir (Arrivée)
    lines.emplace_back(Line::SIDEWALK, 13, FL_MAGENTA, cellWidth, cellHeight);

    // Initialiser le score
    score = 0;
}


void Board::update() {
    // Mettre à jour les obstacles sur chaque ligne
    for (auto& line : lines) {
        // Mettre à jour les obstacles sur les lignes qui en contiennent
        if (line.getType() != Line::SIDEWALK) {
            for (auto* obstacle : line.getObstacles()) {
                obstacle->move(); // Déplacer les obstacles
            }
        }
    }

    // Mettre à jour d'autres éléments du jeu si nécessaire
    // (par exemple, vérifier les collisions, mettre à jour le score)
}

// Dessiner le plateau de jeu
void Board::draw() {
    // Dessiner les lignes (fond statique)
    for (auto& line : lines) {
        line.drawBackground();
    }
}
void Board::drawObstacles() {

}

// Réinitialiser l'état du jeu
void Board::reset() {
    // Réinitialiser les lignes et les obstacles
    initialize(); // Réinitialiser les lignes du plateau
    // Réinitialiser d'autres éléments du jeu si nécessaire
    // (par exemple, le score, la position de la grenouille)
}

// Obtenir le score actuel
int Board::getScore() const {
    return score;
}

// Obtenir les lignes actuelles
const std::vector<Line>& Board::getLines() const {
    return lines;
}
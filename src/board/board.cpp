#include "../../include/board/board.hpp"

Board::Board(int windowWidth, int windowHeight)
    : windowWidth(windowWidth), windowHeight(windowHeight), 
    frog(Point{windowWidth / 2,  13*windowHeight/14 - ((windowHeight/14)/2)},windowWidth/14 , windowHeight/14, FL_GREEN), 
    score(0) {
    initialize();
}

Frog& Board::getFrog() {
    return frog;
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

    addObstaclesToLines();
    // Initialiser le score
    score = 0;
}

void Board::addObstaclesToLines(){
    for (int i = 0; i < 3; i++) lines[1].addObstacle(new Car(Point{i * 200,lines[1].getHeight()* (11) }, lines[1].getWidth(), lines[1].getHeight(), -1));
    for (int i = 0; i < 3; i++) lines[2].addObstacle(new Car(Point{i * 200,lines[2].getHeight()* (10) }, lines[2].getWidth(), lines[1].getHeight(), 1));
    for (int i = 0; i < 3; i++) lines[3].addObstacle(new Car(Point{i * 200,lines[3].getHeight()* (9) }, lines[3].getWidth(), lines[1].getHeight(), -3));
    for (int i = 1; i < 4; i++) lines[4].addObstacle(new Car(Point{i * 200,lines[4].getHeight()* (8) }, lines[4].getWidth(), lines[1].getHeight(), 2));
    for (int i = 1; i <3; i++) lines[5].addObstacle(new Truck(Point{i * 300,lines[5].getHeight()* (7) }, lines[5].getWidth()*2, lines[1].getHeight(), -1));
   
}

// Méthodes de mouvement de la grenouille
void Board::moveFrogUp() {
    frog.setDirection(0);
    frog.move(0, -1 * windowHeight/14);
}

void Board::moveFrogDown() {
    frog.setDirection(2);
    frog.move(0, windowHeight/14);
}

void Board::moveFrogLeft() {
    frog.setDirection(3);
    frog.move(-1 * windowWidth/14, 0);
}

void Board::moveFrogRight() {
    frog.setDirection(1);
    frog.move(windowWidth/14, 0);
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
    frog.draw();
}
void Board::drawObstacles() {
    for (auto& line : lines) {
        line.drawObstacles();
    }
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

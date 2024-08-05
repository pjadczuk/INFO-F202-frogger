#include "../../include/board/board.hpp"
#include <FL/Enumerations.H>
#include <iostream>

Board::Board(int windowWidth, int windowHeight)
    : windowWidth(windowWidth), windowHeight(windowHeight), 
    frog(Point{windowWidth / 2,  13*windowHeight/14 - ((windowHeight/14)/2)},windowWidth/14 , windowHeight/14, FL_GREEN), 
    gameState(120,3),
    scoreText("Score: 0", Point{10, 20}, 16, FL_WHITE),
    livesText("Lives: 3", Point{10, 40}, 16, FL_WHITE),
    timeText("Time: 120", Point{10, 60}, 16, FL_WHITE) {
    initialize();
}

Frog& Board::getFrog() {
    return frog;
}

void Board::drawHUD() {
    // Dessiner le score
    fl_color(FL_WHITE);
    fl_draw(("Score: " + std::to_string(gameState.getScore())).c_str(), 10, windowWidth -10);

    // Dessiner le nombre de vies restantes
    fl_draw(("Lives: " + std::to_string(gameState.getLives())).c_str(), 10, windowWidth - 30);

    // Dessiner le temps restant
    fl_draw(("Time: " + std::to_string(gameState.getRemainingTime())).c_str(), 10, windowWidth - 50);
}

void Board::setupFinishLinePairs() {
    // Indices des paires de cellules walkables sur la ligne de FINISH
    std::vector<std::pair<int, int>> walkablePairs = {{0, 1}, {4, 5}, {8, 9}, {12, 13}};

    // Récupérer la ligne de FINISH
    Line& finishLine = lines.back();

    // Définir les cellules comme walkables par paires
    for (const auto& pair : walkablePairs) {
        int index1 = pair.first;
        int index2 = pair.second;

        finishLine.switchWalkableCell(index1);
        finishLine.switchWalkableCell(index2);
    }
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
    lines.emplace_back(Line::FINISH, 13, FL_MAGENTA, cellWidth, cellHeight);
    setupFinishLinePairs();
    
    addObstaclesToLines();
}

void Board::addObstaclesToLines(){
    for (int i = 0; i < 3; i++) lines[1].addObstacle(new Car(Point{i * 200,lines[1].getHeight()* (11) }, lines[1].getWidth(), lines[1].getHeight(), -1));
    for (int i = 0; i < 3; i++) lines[2].addObstacle(new Car(Point{i * 200,lines[2].getHeight()* (10) }, lines[2].getWidth(), lines[1].getHeight(), 1));
    for (int i = 0; i < 3; i++) lines[3].addObstacle(new Car(Point{i * 200,lines[3].getHeight()* (9) }, lines[3].getWidth(), lines[1].getHeight(), -3));
    for (int i = 1; i < 4; i++) lines[4].addObstacle(new Car(Point{i * 200,lines[4].getHeight()* (8) }, lines[4].getWidth(), lines[1].getHeight(), 2));
    for (int i = 1; i <3; i++) lines[5].addObstacle(new Truck(Point{i * 300,lines[5].getHeight()* (7) }, lines[5].getWidth()*2, lines[1].getHeight(), -1));
   
    for (int i = 0; i < 4; i++) lines[7].addObstacle(new Turtle(Point{i * 300,lines[1].getHeight()* (5) }, lines[7].getWidth()*3, lines[1].getHeight(), -1));
    for (int i = 0; i < 3; i++) lines[8].addObstacle(new Log(Point{i * 300,lines[8].getHeight()* (4) }, lines[8].getWidth()*2, lines[1].getHeight(), 2));
    for (int i = 0; i < 3; i++) lines[9].addObstacle(new Log(Point{i * 400,lines[9].getHeight()* (3) }, lines[9].getWidth()*4, lines[1].getHeight(), 3));
    for (int i = 1; i < 4; i++) lines[10].addObstacle(new Turtle(Point{i * 300,lines[10].getHeight()* (2) }, lines[10].getWidth()*3, lines[1].getHeight(), -2));
    for (int i = 1; i <5; i++) lines[11].addObstacle(new Log(Point{i * 300,lines[11].getHeight()* (1) }, lines[11].getWidth()*3, lines[1].getHeight(), 2));
}

void Board::toggleTurtleWalkable() {
    // Vérifier si la ligne 7 contient au moins une tortue
    if (!lines[7].getObstacles().empty()) {
        // La dernière tortue de la ligne 7
        auto* turtle = dynamic_cast<Turtle*>(lines[7].getObstacles().back());
        if (turtle) {
            turtle->setWalkable();
        }
    }
    gameState.decreaseTime(1);
    // Vérifier si la ligne 10 contient au moins une tortue
    if (!lines[10].getObstacles().empty()) {
        // La première tortue de la ligne 10
        auto* turtle = dynamic_cast<Turtle*>(lines[10].getObstacles().front());
        if (turtle) {
            turtle->setWalkable();
        }
    }
}


// Méthodes de mouvement de la grenouille
void Board::moveFrogUp() {
    frog.setDirection(0);
    frog.incrementPosHeight();
    frog.move(0, -1 * windowHeight/14);

}

void Board::moveFrogDown() {
    frog.setDirection(2);
    frog.decrementPosHeight();
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
    for (auto& line : lines) {
        if (isFrogOnFinishCell()) {
        // Code à exécuter lorsque le Frog atteint une cellule de la ligne FINISH
        // Par exemple, augmenter le score, passer au niveau suivant, etc.
        gameState.increaseScore(1);
        gameState.resetTime();
        frog.resetToInitialCenter();
        }
        else if (frog.getPosHeight() == line.getNumerLine()) {
            checkFrogOnLine(line);
        } else {
            // Déplacer les obstacles même si la grenouille n'est pas sur la ligne
            for (auto* obstacle : line.getObstacles()) {
                obstacle->move();
            }
        }
    }

    if (gameState.getRemainingTime() == 0) {
        gameState.loseLife();
        gameState.resetTime();
        frog.resetToInitialCenter();
    }

    if (!isInsideTheWindow(frog.getCenter())){
        gameState.loseLife();
        gameState.resetTime();
        frog.resetToInitialCenter();
    }
}

bool Board::isInsideTheWindow(Point frogCenter) {
    if (frogCenter.x >=0 && frogCenter.x <= windowWidth &&
    frogCenter.y >= 0 && frogCenter.y <= 13*windowHeight/14) return true;
    else return false;
}

void Board::checkFrogOnLine(Line& line) {
    bool frogOnValidObstacle = false;

    for (auto* obstacle : line.getObstacles()) {
        obstacle->move(); // Déplacer les obstacles

        if (obstacle->contains(frog.getCenter())) {
            if (line.isWalkable()) {
                gameState.loseLife();
                gameState.resetTime();
                frog.resetToInitialCenter();
                return; // Si c'est une ligne marchable et qu'il y a collision, réinitialiser la grenouille
            } else if (obstacle->isMountable()) {
                frog.move(obstacle->getSpeed());
                frogOnValidObstacle = true; // Grenouille sur un obstacle montable
            }
        }
    }
    // Si après avoir vérifié tous les obstacles, la grenouille n'est pas sur un obstacle montable
    if (!frogOnValidObstacle && !line.isWalkable() && !isFrogOnFinishCell()) {
        gameState.loseLife();
        gameState.resetTime();
        frog.resetToInitialCenter(); // Réinitialiser la grenouille si elle n'est pas sur un obstacle montable
    }
}

bool Board::isFrogOnFinishCell() {
    // Trouver la ligne FINISH
    for (auto& line : lines) {
        if (line.getType() == Line::FINISH) {
            // Vérifier si le Frog est sur une cellule walkable de cette ligne
            for (size_t i = 0; i < line.getCells().size(); ++i) {
                Cell& cell = line.getCells()[i];
                if (cell.isWalkable() && cell.contains(frog.getCenter())) {
                    // Marquer la cellule et sa paire comme non-walkable
                    cell.setWalkable(false);

                    // Déterminer l'index de la cellule paire
                    size_t pairIndex = (i % 2 == 0) ? i + 1 : i - 1;

                    // Vérifier que l'index de la paire est valide
                    if (pairIndex < line.getCells().size()) {
                        Cell& pairCell = line.getCells()[pairIndex];
                        pairCell.setWalkable(false);
                    }

                    return true; // Le Frog est sur une cellule walkable
                }
            }
        }
    }
    return false; // Le Frog n'est pas sur une cellule walkable
}

// Dessiner le plateau de jeu
void Board::drawBackground() {
    // Dessiner les lignes (fond statique)
    for (auto& line : lines) {
        line.drawBackground();
    }
    
}

void Board::drawObstacles() {
    for (auto& line : lines) {
        line.drawObstacles();
    }
}
void Board::drawFrog() {
    frog.draw();
}
void Board::draw() {
    //drawBackground();drawObstacles();drawFrog();
}
// Réinitialiser l'état du jeu
void Board::reset() {
    // Réinitialiser les lignes et les obstacles
    initialize(); // Réinitialiser les lignes du plateau
    // Réinitialiser d'autres éléments du jeu si nécessaire
    // (par exemple, le score, la position de la grenouille)
}



// Obtenir les lignes actuelles
const std::vector<Line>& Board::getLines() const {
    return lines;
}

int Board::getGameLives() {
    return gameState.getLives();
}

int Board::getGameScore() {
    return gameState.getScore();
}

Board::~Board() {
    std::cout << "Board destructor called" << std::endl;
    // Autres nettoyages si nécessaire
}
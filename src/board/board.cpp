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

Board::~Board() {
    std::cout << "Board destructor called" << std::endl;
}


/*------------------------------------CREATION DU PLATEAU------------------------------------*/

/*
Création du plateau avec les lignes du jeu, ligne par ligne
et dans l'ordre du jeu
*/
void Board::initialize() {
    lines.clear(); // Effacer les anciennes lignes, s'il y en a

	int numLines = 14; 
	int numCellsInLines = 14;
    int cellWidth = windowWidth / numCellsInLines; 
    int cellHeight = windowHeight / numLines; 

    // Ligne 1 : TROTTOIR (debut)
    lines.emplace_back(Line::SIDEWALK, 1,FL_MAGENTA, cellWidth, cellHeight);

    // Lignes 2 à 6 : ROUTES
    for (int numerLine = 2; numerLine <= 6; numerLine++) {
        lines.emplace_back(Line::ROAD, numerLine, FL_BLACK, cellWidth, cellHeight);
    }
	// Ligne 7 : TROTTOIR (milieu)
	lines.emplace_back(Line::SIDEWALK, 7,FL_MAGENTA, cellWidth, cellHeight);

    // Lignes 8 à 12 : RIVIERES
    for (int numerLine = 8; numerLine <= 12; numerLine++) {
        lines.emplace_back(Line::WATER, numerLine, FL_BLUE, cellWidth, cellHeight);
    }

    // Ligne 13 : TROTTOIR (fin)
    lines.emplace_back(Line::FINISH, 13, FL_MAGENTA, cellWidth, cellHeight);

    setupFinishLinePairs();
    
    addObstaclesToLines();
}

/*
Pour la dernière ligne, les cases d'arrivées sont une paire de deux cases 
pour avoir des nénuphares plus larges et faciles d'accès
*/
void Board::setupFinishLinePairs() {
    // Les numéros de cases binome qui forment un nénuphare
    std::vector<std::pair<int, int>> walkablePairs = {{0, 1}, {4, 5}, {8, 9}, {12, 13}};

    Line& finishLine = lines.back();

    // Définit les nénuphars comme Walkable
    for (const auto& pair : walkablePairs) {
        int index1 = pair.first;
        int index2 = pair.second;

        finishLine.switchWalkableCell(index1);
        finishLine.switchWalkableCell(index2);
    }
}

/*
Ajout des différents obstacles à la ligne correspondante
*/
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

/*
Apparition et disparition des tortues dans la rivière.
*/
void Board::toggleTurtleWalkable() {
    if (!lines[7].getObstacles().empty()) {
        // La dernière tortue de la ligne 7
        auto* turtle = dynamic_cast<Turtle*>(lines[7].getObstacles().back());
        if (turtle) {
            turtle->setWalkable();
        }
    }
    //Vu que cette méthode est appelée chaque seconde on en proffite pour decreaseTime;
    gameState.decreaseTime(1);
    if (!lines[10].getObstacles().empty()) {
        // La première tortue de la ligne 10
        auto* turtle = dynamic_cast<Turtle*>(lines[10].getObstacles().front());
        if (turtle) {
            turtle->setWalkable();
        }
    }
}

/*
Réinitialiser les lignes et les obstacles
*/
void Board::reseting() {
    gameState.reset(120,3);
    initialize();
    frog.resetToInitialCenter();
}

/*------------------------------------LOGIQUE DU JEU------------------------------------*/

/*
Mise à jour du plateau 60 fois par seconde en fonction des règles du jeu
*/
void Board::update() {
    for (auto& line : lines) {
        
        if (isFrogOnFinishCell()) {
            // Mise à jour si le frog Arrive sur la ligne d'arrivée
            gameState.increaseScore(1);
            gameState.resetTime();
            frog.resetToInitialCenter();
        }
        
        else if (frog.getPosHeight() == line.getNumerLine()) {
            // Vérifie la logique du jeu de la grenouille sur le plateau et ses interractiosn
            checkFrogOnLine(line);
        } 
        
        else {
            // Déplacer les obstacles même si la grenouille n'est pas sur la ligne
            for (auto* obstacle : line.getObstacles()) {
                obstacle->move();
            }
        }
    }

    // Si il ne reste plus de temps
    if (gameState.getRemainingTime() == 0) {
        gameState.loseLife();
        gameState.resetTime();
        frog.resetToInitialCenter();
    }

    // Si en dehors de la fenêtre
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

/*
Logique du jeu en fonction de la ligne sur laquelle on se situe
et l'interraction de la grenouille avec cette ligne
*/
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
            // Vérifie si le Frog est sur une cellule walkable de cette ligne
            for (size_t i = 0; i < line.getCells().size(); ++i) {
                Cell& cell = line.getCells()[i];
                if (cell.isWalkable() && cell.contains(frog.getCenter())) {
                    // Marquer la cellule et son binome comme non-walkable
                    cell.setWalkable(false);

                    size_t pairIndex = (i % 2 == 0) ? i + 1 : i - 1;

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


/*---------------------------------DEPLACEMENT DE LA GRENOUILLE---------------------------------*/

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

/*------------------------------------AFFICHAGE DU PLATEAU------------------------------------*/

void Board::drawBackground() {
    for (auto& line : lines) {
        line.drawBackground();
    }
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

void Board::drawObstacles() {
    for (auto& line : lines) {
        line.drawObstacles();
    }
}

void Board::drawFrog() {
    frog.draw();
}

/*------------------------------------GETTER------------------------------------*/
const std::vector<Line>& Board::getLines() const {
    return lines;
}

int Board::getGameLives() {
    return gameState.getLives();
}

int Board::getGameScore() {
    return gameState.getScore();
}

Frog& Board::getFrog() {
    return frog;
}

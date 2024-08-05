#pragma once
#include <vector>
#include <memory>
#include "line.hpp"
#include "../obstacles/car.hpp"
#include "../obstacles/truck.hpp"
#include "../obstacles/log.hpp"
#include "../obstacles/turtle.hpp"
#include "../frog.hpp"
#include "../gameState.hpp"
#include "../texte.hpp"

class Board {
private:
    std::vector<Line> lines; // Les lignes du plateau
    Frog frog;
    int windowWidth;
    int windowHeight;
    void initialize();
    void addObstaclesToLines();
    GameState gameState;
    Text scoreText;
    Text livesText;
    Text timeText;
public:
    Board(int windowWidth, int windowHeight);
    ~Board();
    void update();
    void drawBackground();
    void drawObstacles();
    void drawFrog();
    void draw();
    void reseting();
    const std::vector<Line>& getLines() const; // Ajout de la méthode getLines
    Frog& getFrog();  // Méthode pour obtenir une référence à la grenouille
    void moveFrogUp();
    void moveFrogDown();
    void moveFrogLeft();
    void moveFrogRight();
    void toggleTurtleWalkable();
    void checkFrogOnLine(Line& line);
    bool isFrogOnFinishCell();
    bool isInsideTheWindow(Point frogCenter);
    void setupFinishLinePairs();
    void drawHUD();
    void checkGameOver(); // Vérifie si le jeu est terminé
    void renderGameState(); // Affiche l'état du jeu (score, vies, etc.)
    int getGameLives();
    int getGameScore();
};


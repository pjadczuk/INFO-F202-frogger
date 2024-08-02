#pragma once

#include "frog.hpp"
#include "level.hpp"
#include <vector>

class AbstractView;
class AbstractController;

class Game {
private:
    Frog frog;
    std::vector<Level*> levels;
    int currentLevelIndex;
    int score;
    int highScore;
    AbstractView* view;
    AbstractController* controller;

public:
    Game();
    void start();
    void update();
    void end();
    void reset();
    void nextLevel();
    void loseLife();
    int getScore() const;
    int getHighScore() const;

    Frog& getFrog() { return frog; } // Retourne une référence à l'objet Frog
    Level& getCurrentLevel() { return *levels[currentLevelIndex]; } // Retourne une référence au niveau actuel
};

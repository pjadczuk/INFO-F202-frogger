#pragma once

#include "frog.hpp"

class AbstractView;
class AbstractController;

class Game {
private:
    Frog frog;
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
    void loseLife();
    int getScore() const;
    int getHighScore() const;

    Frog& getFrog() { return frog; } // Retourne une référence à l'objet Frog
};

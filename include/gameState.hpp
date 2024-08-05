#pragma once

class GameState {
private:
    int score;           // Score du joueur
    int remainingTime;   // Temps restant en secondes
    int lives;           // Nombre de vies restantes

public:
    GameState(int initialTime, int initialLives);
    void reset(int initialTime, int initialLives);

    int getScore() const;
    void increaseScore(int amount);
    void decreaseScore(int amount);

    int getRemainingTime() const;
    void decreaseTime(int amount);

    int getLives() const;
    void loseLife();
    void gainLife();
    void resetTime();
    // Autres méthodes si nécessaire
    bool isGameOver() const;
    bool isVictory() const;
    bool isDefeat() const;
};
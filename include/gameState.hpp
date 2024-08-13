#pragma once

class GameState {
private:
    int score;           
    int remainingTime;   
    int lives;          
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
    bool isGameOver() const;
    bool isVictory() const;
    bool isDefeat() const;
};
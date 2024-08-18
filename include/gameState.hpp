#pragma once


class GameState {
private:
    int score;
    int points;
    int highScore;      
    int remainingTime;   
    int lives;

    void loadHighScore(); 
    

public:
    GameState(int initialTime, int initialLives);
    
    void resetTime();
    void reset(int initialTime, int initialLives);
    void resetHighScore();
    void saveHighScore();

    void increaseScore(int amount);
    void increasePoints(int amount);
    void decreaseScore(int amount);
    void decreaseTime(int amount);
    void loseLife();
    void gainLife();

    int getRemainingTime() const;
    int getPoints() const;
    int getLives() const;
    int getScore() const;
    int getHighScore() const;

    bool isGameOver() const;
    bool isVictory() const;
    bool isDefeat() const;
};
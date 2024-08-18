#include "../include/gameState.hpp"
#include <fstream>

GameState::GameState(int initialTime, int initialLives)
    : score(0), points(0), remainingTime(initialTime), lives(initialLives) {
        loadHighScore();
    }


void GameState::reset(int initialTime, int initialLives) {
    score = 0;
    points = 0;
    remainingTime = initialTime;
    lives = initialLives;
    loadHighScore();
}

void GameState::resetTime() {
    remainingTime = 120;
}

void GameState::resetHighScore(){
    std::ofstream file("highscore.txt");
    highScore = 0;
    if (file.is_open()) {
        file << highScore;
        file.close();
    }
}

void GameState::loadHighScore() {
    std::ifstream file("highscore.txt");
    if (file.is_open()) {
        file >> highScore;
        file.close();
    } else {
        highScore = 0; 
    }
}

void GameState::saveHighScore() {
    std::ofstream file("highscore.txt");
    if (file.is_open()) {
        file << points;
        file.close();
    }
}


int GameState::getRemainingTime() const {
    return remainingTime;
}

int GameState::getLives() const {
    return lives;
}

void GameState::loseLife() {
    if (lives > 0) {
        lives--;
    }
}

int GameState::getHighScore() const {
    return highScore;
}

int GameState::getScore() const {
    return score;
}

int GameState::getPoints() const {
    return points;
}



void GameState::increaseScore(int amount = 1) {
    score += amount;
}

void GameState::increasePoints(int amount = 1) {
    points += amount;
}

void GameState::decreaseScore(int amount) {
    score -= amount;
}

void GameState::decreaseTime(int amount = 1) {
    if (remainingTime > amount) {
        remainingTime -= amount;
    } else {
        remainingTime = 0;
    }
}


void GameState::gainLife() {
    lives++;
}

bool GameState::isGameOver() const {
    return isVictory() || isDefeat();
}

bool GameState::isVictory() const {
    return score >= 4; 
}

bool GameState::isDefeat() const {
    return lives <= 0 ;
}

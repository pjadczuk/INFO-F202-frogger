#include "../include/gameState.hpp"
#include <iostream>

GameState::GameState(int initialTime, int initialLives)
    : score(0), remainingTime(initialTime), lives(initialLives) {}

void GameState::reset(int initialTime, int initialLives) {
    score = 0;
    remainingTime = initialTime;
    lives = initialLives;
    std::cout <<remainingTime<<" et" << lives<<std::endl;
}

int GameState::getScore() const {
    return score;
}

void GameState::resetTime() {
    remainingTime = 120;
}

void GameState::increaseScore(int amount = 1) {
    score += amount;
}

void GameState::decreaseScore(int amount) {
    score -= amount;
}

int GameState::getRemainingTime() const {
    return remainingTime;
}

void GameState::decreaseTime(int amount = 1) {
    if (remainingTime > amount) {
        remainingTime -= amount;
    } else {
        remainingTime = 0;
    }
}

int GameState::getLives() const {
    return lives;
}

void GameState::loseLife() {
    if (lives > 0) {
        lives--;
    }
}

void GameState::gainLife() {
    lives++;
}

bool GameState::isGameOver() const {
    return isVictory() || isDefeat();
}

bool GameState::isVictory() const {
    return score >= 4; // Condition de victoire
}

bool GameState::isDefeat() const {
    return lives <= 0 ; // Condition de défaite
}

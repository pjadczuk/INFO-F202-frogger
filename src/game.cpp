#include "../include/game.hpp"
#include <FL/fl_draw.H>
#include <iostream>

Game::Game(int windowWidth, int windowHeight)
    : gameRunning(true), gameWon(false), windowWidth(windowWidth), windowHeight(windowHeight), 
      board(std::make_unique<Board>(windowWidth, windowHeight)) {}
Game::~Game() {
    // std::unique_ptr se charge de supprimer l'objet Board
}

// Démarrer une nouvelle partie
void Game::startNewGame() {
    board = std::make_unique<Board>(windowWidth, windowHeight); // Crée un nouvel objet Board
}

void Game::start() {
    gameRunning = true;
    gameWon = false;
    board.reset();
}

void Game::update() {
    if (gameRunning) {
        board->update();
        checkGameState();
    }
}

void Game::draw() {
    if (gameRunning) {
        board->drawBackground();
        board->drawObstacles();
        board->drawFrog();
        board->drawHUD();
		update();
    } else {
        fl_color(FL_WHITE);
        if (gameWon) {
            //fl_draw("You Win!", windowWidth / 2, windowHeight / 2);
        } else {
            //fl_draw("Game Over", windowWidth / 2, windowHeight / 2);
        }
    }
}

void Game::checkGameState() {
    if (board->getGameScore() >= 4) {
        gameRunning = false;
        gameWon = true;
    } else if (board->getGameLives() <= 0) {
        gameRunning = false;
        gameWon = false;
    }
}

bool Game::isGameRunning() const {
    return gameRunning;
}

bool Game::isGameWon() const {
    return gameWon;
}

void Game::reset() {
    start();
}

Board* Game::getBoard() {
    return board.get();
}

void Game::handleInput(int key) {
    if (!board) {
        std::cerr << "Error: Board pointer is null." << std::endl;
        return;
    }
    
    switch (key) {
        case FL_Up:
        case 'z':
            board->moveFrogUp();
            break;
        case FL_Down:
        case 's':
            board->moveFrogDown();
            break;
        case FL_Left:
        case 'q':
            board->moveFrogLeft();
            break;
        case FL_Right:
        case 'd':
            board->moveFrogRight();
            break;
        default:
            break;
    }
}
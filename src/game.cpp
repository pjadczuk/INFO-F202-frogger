#include "../include/game.hpp"
#include <FL/fl_draw.H>
#include <iostream>

Game::Game(int windowWidth, int windowHeight)
    : gameRunning(true), gameWon(false), windowWidth(windowWidth), windowHeight(windowHeight), 
      board(std::make_unique<Board>(windowWidth, windowHeight)) {}


Game::~Game() {
    //std::cout<<"suppression de game\n";
}


void Game::startNewGame() {
    gameRunning = true;
    gameWon = false;
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
            board->save();
            fl_draw("You Win!", windowWidth / 2 - 50, windowHeight / 2);
			fl_draw("Type 'x' if you want to play again",windowWidth / 2 - 140,windowHeight / 2 + 30);
            fl_draw("Type 'r' if you want to reset the higest score",windowWidth / 2 - 185,windowHeight / 2 + 60);
        } else {
            board->save();
            fl_draw("Game Over", windowWidth / 2 - 50, windowHeight / 2);
			fl_draw("Type 'x' if you want to play again",windowWidth / 2 - 140,windowHeight / 2 + 30);
            fl_draw("Type 'r' if you want to reset the higest score",windowWidth / 2 - 185,windowHeight / 2 + 60);
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

void Game::handleInput(int key) {
    if (!board) {
        std::cerr << "Error: Board pointer is null." << std::endl;
        return;
    }
    
    switch (key) {
        case FL_Up:
        case 'z':
		case 'w':
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
		case 'a':
            board->moveFrogRight();
            break;
		case 'x':
			startNewGame();
			board->reseting();
			break;
        case 'r':
            board->resetHightScore();
            break;
        default:
            break;
    }
}

Board* Game::getBoard() {
    return board.get();
}

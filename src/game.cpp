#include "../include/game.hpp"
#include "../include/gameview.hpp"
#include "../include/gamecontroller.hpp"
#include <FL/Fl.H>

Game::Game()
    : frog(Point(0, 0), 3), currentLevelIndex(0), score(0), highScore(0) {
    levels.push_back(new Level(1));
    levels.push_back(new Level(2));
    levels.push_back(new Level(3));

    view = new GameView(this);
    controller = new GameController(this);
}

void Game::start() {
    levels[currentLevelIndex]->loadLevel();
    Fl::add_timeout(1.0 / 60.0, [](void* game) {
        static_cast<Game*>(game)->update();
        Fl::repeat_timeout(1.0 / 60.0, [](void* game) {
            static_cast<Game*>(game)->update();
        }, game);
    }, this);
}

void Game::update() {
    levels[currentLevelIndex]->update();
    view->render();
}

void Game::end() {
    Fl::remove_timeout([](void* game) { static_cast<Game*>(game)->update(); }, this);
}

void Game::reset() {
    currentLevelIndex = 0;
    score = 0;
    frog = Frog(Point(0, 0), 3);
    levels[currentLevelIndex]->loadLevel();
}

void Game::nextLevel() {
    if (currentLevelIndex < levels.size() - 1) {
        currentLevelIndex++;
        levels[currentLevelIndex]->loadLevel();
    } else {
        end();
    }
}

void Game::loseLife() {
    frog.loseLife();
    if (frog.getLives() <= 0) {
        end();
    } else {
        frog.resetPosition(Point(0, 0));
    }
}

int Game::getScore() const {
    return score;
}

int Game::getHighScore() const {
    return highScore;
}

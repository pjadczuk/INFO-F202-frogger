#include "../include/game.hpp"
#include "../include/gameview.hpp"
#include "../include/gamecontroller.hpp"
#include <FL/Fl.H>

Game::Game()
    : frog(Point(0, 0), 3), score(0), highScore(0) {
    view = new GameView(this);
    controller = new GameController(this);
}

void Game::start() {
    Fl::add_timeout(1.0 / 60.0, [](void* game) {
        static_cast<Game*>(game)->update();
        Fl::repeat_timeout(1.0 / 60.0, [](void* game) {
            static_cast<Game*>(game)->update();
        }, game);
    }, this);
}

void Game::update() {
    view->render();
}

void Game::end() {
    Fl::remove_timeout([](void* game) { static_cast<Game*>(game)->update(); }, this);
}

void Game::reset() {
    score = 0;
    frog = Frog(Point(0, 0), 3);
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

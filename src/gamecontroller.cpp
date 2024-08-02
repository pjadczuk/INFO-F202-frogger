#include "../include/gamecontroller.hpp"
#include "../include/game.hpp"
#include <FL/Fl.H>

GameController::GameController(Game* game) : game(game) {}

void GameController::handleInput(int keyCode) {
    switch (keyCode) {
    case FL_Up:
        game->getFrog().move(Direction::Up);
        break;
    case FL_Down:
        game->getFrog().move(Direction::Down);
        break;
    case FL_Left:
        game->getFrog().move(Direction::Left);
        break;
    case FL_Right:
        game->getFrog().move(Direction::Right);
        break;
    default:
        break;
    }
}

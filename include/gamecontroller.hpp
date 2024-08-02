#pragma once

#include "AbstractController.hpp"

class Game;

class GameController : public AbstractController {
private:
    Game* game;

public:
    GameController(Game* game);
    void handleInput(int keyCode) override;
};

#pragma once

#include "AbstractView.hpp"


class Game;

class GameView : public AbstractView {
private:
    Game* game;

public:
    GameView(Game* game);
    void render() override;
    void showVictoryMessage() override;
    void showFailureMessage() override;
};

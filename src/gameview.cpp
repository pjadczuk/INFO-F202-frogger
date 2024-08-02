#include "../include/gameview.hpp"
#include "../include/game.hpp"

GameView::GameView(Game* game) : game(game) {}

void GameView::render() {
    // Dessiner la grenouille et le niveau actuel
    game->getFrog().draw();
    game->getCurrentLevel().draw();
}

void GameView::showVictoryMessage() {
    // Implémenter l'affichage du message de victoire
}

void GameView::showFailureMessage() {
    // Implémenter l'affichage du message de défaite
}

#include "../include/mainWindow.hpp"
#include <FL/Fl.H>
#include <memory>

// Constructeur
MainWindow::MainWindow(int width, int height, const char* title)
    : Fl_Window(width, height, title), 
      board(width, height),
      inputHandler(&board){
    // Commencer la boucle de rafraîchissement des éléments dynamiques
    Fl::add_timeout(1.0 / 60, Timer_CB, this);  // 60 fps
}

// Dessiner les éléments statiques (appelé une seule fois)
void MainWindow::drawStaticElements() {
    board.draw();  // Dessiner le plateau statique (lignes)
}

// Dessiner les éléments dynamiques (appelé fréquemment)
void MainWindow::drawDynamicElements() {
    board.update();            // Mettre à jour l'état des éléments dynamiques
    board.drawObstacles();     // Dessiner les obstacles en mouvement
    // Ici, vous pourriez également dessiner d'autres éléments dynamiques comme la grenouille
}

// Gérer les événements (par exemple, la souris et le clavier)
int MainWindow::handle(int event) {
    switch (event) {
      case FL_MOVE:
        // Gérer le mouvement de la souris si nécessaire
        return 1;
      case FL_PUSH:
        // Gérer les clics de la souris si nécessaire
        return 1;
      case FL_KEYDOWN:
        // Gérer les pressions de touches si nécessaire
        inputHandler.handleKeyPress(Fl::event_key());
        return 1;
      default:
        return Fl_Window::handle(event);  // Appeler le gestionnaire d'événements par défaut
    }
}

// Callback pour le timer de rafraîchissement
void MainWindow::Timer_CB(void *userdata) {
    MainWindow *o = static_cast<MainWindow *>(userdata);
    o->redraw();  // Appeler le dessin des éléments dynamiques
    Fl::repeat_timeout(1.0 / 60, Timer_CB, userdata);  // Répéter toutes les 1/60 secondes
}

void MainWindow::draw() {
    Fl_Window::draw();
    drawStaticElements();  // Dessiner les éléments statiques
    drawDynamicElements(); // Dessiner les éléments dynamiques
}
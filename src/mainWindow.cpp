#include "../include/mainWindow.hpp"
#include <FL/Fl.H>
#include <memory>

// Constructeur
MainWindow::MainWindow(int width, int height, const char* title)
    : Fl_Window(width, height, title), 
      game(width, height)
{
    // Commencer la boucle de rafraîchissement des éléments dynamiques
    Fl::add_timeout(1.0 / 60, Timer_CB, this);  // 60 fps
    Fl::add_timeout(1.0, toggleTurtles_CB, this);  // Appeler toggleTurtles_CB toutes les secondes
    //Fl::add_timeout(1.0, drawHUD_CB, this); 
}

void MainWindow::draw() {
    Fl_Window::draw();
    game.draw();
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
        game.handleInput(Fl::event_key());
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

void MainWindow::toggleTurtles_CB(void* userdata) {
    MainWindow* o = static_cast<MainWindow*>(userdata);
    o->game.getBoard()->toggleTurtleWalkable();  // Changer l'état des tortues
    Fl::repeat_timeout(1.0, toggleTurtles_CB, userdata);  // Répéter toutes les secondes
}


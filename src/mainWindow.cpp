#include "../include/mainWindow.hpp"
#include <FL/Fl.H>
#include <sstream>  


// Constructeur
MainWindow::MainWindow(int width, int height, const char* title)
    : Fl_Window(width, height, title), 
    width(width),height(height),
    game(width, height),
    displayWelcomeScreen(true)
{
    Fl::add_timeout(1.0 / 60, Timer_CB, this);  // 60 fps
    Fl::add_timeout(1.0, toggleTurtles_CB, this);  // Appeler toggleTurtles_CB toutes les secondes
    //Fl::add_timeout(1.0, drawHUD_CB, this); 
    Fl::add_timeout(1.0, welcomeScreenCallback, this);
}

int MainWindow::handle(int event) {
    switch (event) {
      case FL_MOVE:
        // mouvement souris
        return 1;
      case FL_PUSH:
        // click souris
        return 1;
      case FL_KEYDOWN:
        // clavier
        game.handleInput(Fl::event_key());
        return 1;
      default:
        return Fl_Window::handle(event);
    }
}

// Callback pour le timer de rafraîchissement
void MainWindow::Timer_CB(void *userdata) {
    MainWindow *o = static_cast<MainWindow *>(userdata);
    o->redraw();  
    Fl::repeat_timeout(1.0 / 60, Timer_CB, userdata); 
}

void MainWindow::toggleTurtles_CB(void* userdata) {
    MainWindow* o = static_cast<MainWindow*>(userdata);
    o->game.getBoard()->toggleTurtleWalkable();  
    Fl::repeat_timeout(1.0, toggleTurtles_CB, userdata); 
}

void MainWindow::welcomeScreenCallback(void* userdata) {
    MainWindow* o = static_cast<MainWindow*>(userdata);
    o->displayWelcomeScreen = false; // Désactiver l'écran d'accueil
    o->redraw(); 
}

void MainWindow::draw() {
    Fl_Window::draw();
    if (displayWelcomeScreen) {
        drawWelcomeScreen();
    } else {
        game.draw(); // Afficher le jeu
    }
}

void MainWindow::drawWelcomeScreen(){
  std::string welcomeMessage = R"(
                      .-'''-.                                                 
                     '   _    \                                               
                   /   /` '.   \                       __.....__              
     _.._         .   |     \  '  .--./)   .--./)  .-''         '.            
   .' .._|.-,.--. |   '      |  '/.''\\   /.''\\  /     .-''"'-.  `. .-,.--.  
   | '    |  .-. |\    \     / /| |  | | | |  | |/     /________\   \|  .-. | 
 __| |__  | |  | | `.   ` ..' /  \`-' /   \`-' / |                  || |  | | 
|__   __| | |  | |    '-...-'`   /("'`    /("'`  \    .-------------'| |  | | 
   | |    | |  '-                \ '---.  \ '---. \    '-.____...---.| |  '-  
   | |    | |                     /'""'.\  /'""'.\ `.             .' | |      
   | |    | |                    ||     ||||     ||  `''-...... -'   | |      
   | |    |_|                    \'. __// \'. __//                   |_|      
   |_|                            `'---'   `'---'                             
)";

        fl_color(FL_BLACK);
    
        fl_rectf(0, 0, width, height);
        std::stringstream ss(welcomeMessage);
        std::string line;
        int y_offset = height / 2 - 100;
        int line_height = 20;

        fl_color(FL_GREEN);
        fl_font(FL_HELVETICA, 16); 
        //affiche ligne par ligne le gros message
        while (std::getline(ss, line)) {
            fl_draw(line.c_str(), width / 2 - 230, y_offset); // Dessine la ligne
            y_offset += line_height; // Passe à la ligne Next
        }
        fl_draw("Par Jadczuk Pawel", width / 2 +200, height / 2 + 450);
}
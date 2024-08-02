#include "../include/controllBoard.hpp"
#include <FL/Fl.H>

bool ControllBoard::processEvent(int event) {
    int key; // Déclaration en dehors du switch

    switch (event) {
        case FL_KEYDOWN:
            key = Fl::event_key(); // Initialisation à l'intérieur du bloc case
            if (key == FL_Up) {
                board->getFrog().move(Direction::Up);
            } else if (key == FL_Down) {
                board->getFrog().move(Direction::Down);
            } else if (key == FL_Left) {
                board->getFrog().move(Direction::Left);
            } else if (key == FL_Right) {
                board->getFrog().move(Direction::Right);
            }
            return true;
        default:
            return false; // Retourner false pour les événements non gérés
    }
}

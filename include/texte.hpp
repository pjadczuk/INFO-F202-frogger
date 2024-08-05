#pragma once

#include <FL/fl_draw.H>
#include <string>
#include "point.hpp" 

class Text {
private:
    std::string s;       // Contenu du texte
    Point center;        // Centre du texte
    int fontSize;        // Taille de la police
    Fl_Color color;      // Couleur du texte
	int windowWidth;     // Largeur de la fenêtre
    int windowHeight; 

public:
    // Constructeur
    Text(const std::string& s, Point center, int windowWidth, int windowHeight, int fontSize = 10, Fl_Color color = FL_BLACK);

    // Méthode pour dessiner le texte
    void draw() const;

    // Setters et getters
    std::string getString() const { return s; }
    void setString(const std::string &newString) { s = newString; }

    int getFontSize() const { return fontSize; }
    void setFontSize(int newFontSize) { fontSize = newFontSize; }

    Point getCenter() const { return center; }
    void setCenter(Point newCenter) { center = newCenter; }

    int getWindowWidth() const { return windowWidth; }
    void setWindowWidth(int newWindowWidth) { windowWidth = newWindowWidth; }

    int getWindowHeight() const { return windowHeight; }
    void setWindowHeight(int newWindowHeight) { windowHeight = newWindowHeight; }
};

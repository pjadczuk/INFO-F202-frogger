#include "../include/texte.hpp"



Text::Text(const std::string& s, Point center, int windowWidth, int windowHeight, int fontSize, Fl_Color color)
    : s{s}, center{center}, fontSize{fontSize}, color{color}, windowWidth{windowWidth}, windowHeight{windowHeight} {}

void Text::draw() const {
    fl_color(color);
    fl_font(FL_HELVETICA, fontSize);
    int width, height;
    fl_measure(s.c_str(), width, height, true);
    fl_draw(s.c_str(), center.x - width / 2, center.y - fl_descent() + height / 2);
}
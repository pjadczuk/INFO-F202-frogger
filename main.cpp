#include "include/mainWindow.hpp"
#include <FL/Fl.H>

int main(int argc, char *argv[]) {
  MainWindow window(910, 910, "Frogger Game");
  window.show(argc, argv);
  return Fl::run();
}

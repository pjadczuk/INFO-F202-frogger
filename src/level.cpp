#include "../include/level.hpp"
#include "../include/obstacles/car.hpp"
#include "../include/obstacles/truck.hpp"
#include "../include/obstacles/log.hpp"
#include "../include/obstacles/turtle.hpp"


Level::Level(int lvlNumber) : number(lvlNumber) {}

void Level::loadLevel() {
    // Exemples d'ajout d'obstacles en fonction du numéro de niveau
    if (number == 1) {
        // Ajouter des obstacles spécifiques pour le niveau 1
        addObstacle(new Car(Point(50, 100), 5));
        addObstacle(new Truck(Point(150, 200), 3));
        // Ajouter d'autres obstacles...
    } else if (number == 2) {
        // Ajouter des obstacles spécifiques pour le niveau 2
        addObstacle(new Log(Point(50, 300), 2));
        addObstacle(new Turtle(Point(150, 400), 4));
        // Ajouter d'autres obstacles...
    }
    // Définir les positions des nénuphars cibles
    targetLilyPads.push_back(Point(100, 50));
    targetLilyPads.push_back(Point(200, 50));
    targetLilyPads.push_back(Point(300, 50));
}

void Level::addObstacle(Obstacle* obs) {
    obstacles.push_back(obs);
}

void Level::draw() {
    // Dessiner tous les obstacles
    for (auto& obs : obstacles) {
        obs->draw();
    }
}

void Level::update() {
    // Mettre à jour tous les obstacles
    for (auto& obs : obstacles) {
        obs->move();
    }
}

std::vector<Point> Level::getTargetLilyPads() const {
    return targetLilyPads;
}

Level::~Level() {
    // Libérer la mémoire allouée pour les obstacles
    for (auto& obs : obstacles) {
        delete obs;
    }
    obstacles.clear();
}

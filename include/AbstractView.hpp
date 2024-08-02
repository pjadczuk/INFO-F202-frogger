#pragma once

class AbstractView {
public:
    virtual void render() = 0;
    virtual void showVictoryMessage() = 0;
    virtual void showFailureMessage() = 0;
    virtual ~AbstractView() = default; // Assurer un destructeur virtuel pour une destruction correcte des objets dérivés
};

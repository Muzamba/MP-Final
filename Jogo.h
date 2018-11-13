#pragma once
#include "Head.h"

class Jogo{
public:
    Jogo();
    void init();
    void load();
    void fim();

    void update();
    void handleEvents();
    void render();
    ~Jogo();

private:
    int tempo;
    bool on;

};

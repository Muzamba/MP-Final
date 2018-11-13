#pragma once
#include "Head.h"

class Objeto {
public:
    Objeto();
    char* imagem;
    void render();
    ~Objeto();
protected:
    int pos_X;
    int pos_Y;

};

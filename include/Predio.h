#pragma once
#include "Objeto.h"

class Predio : public Objeto {
public:
    Predio() : Objeto() {}
    void destroy();
    ~Predio();

protected:
    int vida;
    Menu menu();
};


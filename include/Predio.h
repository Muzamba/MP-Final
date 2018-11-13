#pragma once
#include "Head.h"

class Predio : Objeto {
public:
    Predio();
    void destroy();
    ~Predio();

private:
    int vida;
    Menu menu();
};


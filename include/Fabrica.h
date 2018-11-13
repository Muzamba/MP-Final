#pragma once
#include "Head.h"

class Fabrica : Predio {
public:
    Fabrica();
    void geraUnidade();
    ~Fabrica();
private:
    int tempoEspera;
    int nivel;
    int tipo;
};
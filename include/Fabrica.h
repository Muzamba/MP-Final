#pragma once
#include "Predio.h"

class Fabrica : public Predio {
public:
    Fabrica() : Predio() {}
    void geraUnidade();
    ~Fabrica();
protected:
    int tempoEspera;
    int nivel;
    int tipo;
};
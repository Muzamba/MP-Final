#pragma once
#include "Head.h"

class GeraRecursos : Predio {
public:
    GeraRecursos();
    void mudaTaxa();
    ~GeraRecursos();
private:
    int nivel;
    int taxa;
    int tipo;
};
#pragma once
#include "Predio.h"

class GeraRecursos : public Predio {
public:
    GeraRecursos() : Predio() {} 
    void mudaTaxa();
    ~GeraRecursos();
private:
    int nivel;
    int taxa;
    int tipo;
};
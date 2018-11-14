#pragma once
#include "Objeto.h"

class Unidade : public Objeto {
public:
    Unidade() : Objeto() {}
    void anda();
    void ataca();
    void mudaImagem();
    void destroy();
    ~Unidade();
protected:
    int vida;
    int velocidade;
    int dano;

};

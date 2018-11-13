#pragma once
#include "Head.h"

class Unidade : Objeto {
public:
    Unidade();
    void anda();
    void ataca();
    void mudaImagem();
    void destroy();
    ~Unidade();
private:
    int vida;
    int velocidade;
    int dano;

};

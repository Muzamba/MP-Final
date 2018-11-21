#pragma once
#include "Objeto.h"
#include "Head.h"
#include <SDL2/SDL.h>

class Botao_Iniciar : public Objeto {
public:
    Botao_Iniciar(int X, int Y) : Objeto(X, Y){}
    
    void handleEvent(SDL_Event* evento);

};

class Botao_Compra : public Objeto {
public:
    
    Botao_Compra(int X, int Y) : Objeto(X, Y){}

    void handleEvent(SDL_Event* evento);

    void mudaTipo(TIPO novoTipo);

protected:

    TIPO tipo = NADA;
};

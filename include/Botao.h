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

class Botao_Load : public Objeto {
public:
    Botao_Load(int X, int Y) : Objeto(X, Y){}
    void handleEvent(SDL_Event* evento);
};

class Botao_Pause : public Objeto {
public:
    Botao_Pause(int X, int Y) : Objeto(X, Y){}
    void handleEvent(SDL_Event* evento);
};
class Botao_Resume : public Objeto {
public:
    Botao_Resume(int X, int Y) : Objeto(X, Y){}
    void handleEvent(SDL_Event* evento);
};
class Botao_Sair : public Objeto {
public:
    Botao_Sair(int X, int Y) : Objeto(X, Y){}
    void handleEvent(SDL_Event* evento);
};
class Botao_Save : public Objeto {
public:
    Botao_Save(int X, int Y) : Objeto(X, Y){}
    void handleEvent(SDL_Event* evento);
};

void buttomEvents(SDL_Event* evento);
void retornaBotao(int* x,int* y);
void to_Cord(int* X, int* Y);
bool verifica_clique_fabrica(const int* X, const int* Y);
bool in_range_mapa(int x, int y); /* Testado */

#pragma once
#include "Objeto.h"
#include "Head.h"
#include <SDL2/SDL.h>

class Botao_Iniciar : public Objeto {
 public:
    Botao_Iniciar(int X, int Y, int W, int H) : Objeto(X, Y) {}
    ~Botao_Iniciar();
    OPERACOES handleEvent(SDL_Event* evento, SDL_Texture* texBase,
     SDL_Texture* texSele, SDL_Texture* texPres);
};

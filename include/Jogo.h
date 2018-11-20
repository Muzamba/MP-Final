#ifndef JOGO
#define JOGO
#include <SDL2/SDL.h>

#include "Fabrica.h"
#include "GeraRecursos.h"
#include "Unidade.h"
class Jogo {
 public:
    Jogo();
    void init(const char* titulo, int x_pos, int y_pos, int width, int height);
    void load();
    void fim();

    void update();
    void handleEvents();
    void renderizar();
    bool isOn();
    ~Jogo();

    Unidade ***matriz_unidade;
    GeraRecursos ***matriz_geraRecurso;
    Fabrica ***matriz_fabrica;

 protected:
    int tempo;
    bool on;
    SDL_Window *janela;
    SDL_Renderer *render;

};

#endif
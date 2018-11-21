// copyright 2018 Switch Dreams
#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "Head.h"
#include "Botao.h"
#include "Fabrica.h"
#include "GeraRecursos.h"
#include "Unidade.h"
class Jogo {
 public:
    Jogo();
    void init(const char* titulo, int x_pos, int y_pos, int width, int height);
    bool loadMidia();
    SDL_Texture* loadTexture(const char* nome);
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
    SDL_Color cTempo{0, 0, 0, 255};
    SDL_Texture* tTempo = NULL;
    std::string sTempo;
    TTF_Font* font;
    bool menu_inicial = false;
    Botao_Iniciar* bIniciar = NULL;
    Objeto* menuInicial = NULL;
    Objeto* mapa = NULL;
    int tempo = 0;
    bool on;
    SDL_Window* janela = NULL;
    SDL_Texture* texturas[TEXTURAS::TEX_TOTAL];
    SDL_Renderer* render = NULL;
};

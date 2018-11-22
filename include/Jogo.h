#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "Player.h"
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

    Unidade ***matriz_unidade = NULL;
    GeraRecursos ***matriz_geraRecurso = NULL;
    Fabrica ***matriz_fabrica = NULL;

    SDL_Texture* texturas[TEXTURAS::TEX_TOTAL];
    bool menu_inicial = false;

    Player* jogador = NULL;
    Player* cpu = NULL;
    //Player* jogador = NULL;
    bool comprando = false;
    //SDL_Texture *teste;

protected:


    Objeto* recurso;
    SDL_Color cRecurso{128, 128, 0};
    //SDL_Texture* tRecurso[1];
    std::string sTempo;
    //TTF_Font* font = NULL;
    Botao_Compra* compra= NULL;
    Botao_Iniciar* bIniciar = NULL;
    Objeto* menuInicial = NULL;
    Objeto* mapa = NULL;
    int tempo = 0;
    bool on;
    SDL_Window* janela = NULL;
    
    SDL_Renderer* render = NULL;

};

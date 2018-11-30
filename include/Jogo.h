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
    bool paused = false;
    SDL_Texture* aloo;
    //#ifdef TESTE
    //Player* jogador = NULL;
    //Player* cpu = NULL;
    //#endif
    //Player* jogador = NULL;
    bool comprando = false;
    SDL_Texture *teste;

protected:


    Objeto* recursoDinheiroJogador;
    Objeto* recursoCeluloseJogador;
    Objeto* recursoPedregulhoJogador;
    Objeto* recursoMetalJogador;
    Objeto* recursoDinheiroCpu;
    Objeto* recursoCeluloseCpu;
    Objeto* recursoPedregulhoCpu;
    Objeto* recursoMetalCpu;
    SDL_Color cRecurso{0, 0, 0}; //decidir cor
    SDL_Texture* tRecurso;
    TTF_Font* font = NULL;
    Botao_Compra* compra= NULL;
    Botao_Iniciar* bIniciar = NULL;
    Botao_Pause* pause = NULL;
    Botao_Resume* resume = NULL;
    Botao_Load* bLoad = NULL;
    Objeto* menuInicial = NULL;
    Objeto* mapa = NULL;
    int tempo = 0;
    bool on;
    SDL_Window* janela = NULL;

    SDL_Renderer* render = NULL;

};

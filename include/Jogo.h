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
    SDL_Texture* aloo;
    //#ifdef TESTE
    //Player* jogador = NULL;
    //Player* cpu = NULL;
    //#endif
    //Player* jogador = NULL;
    bool comprando = false;
    TIPO tipoCompra = NADA;
    int nivelCompra = 0;
    //SDL_Texture *teste;

    /* Movimentacao */
    void movimentacao();
protected:
    Objeto* recursoDinheiroJogador = NULL;
    Objeto* recursoCeluloseJogador= NULL;
    Objeto* recursoPedregulhoJogador= NULL;
    Objeto* recursoMetalJogador= NULL;
    Objeto* recursoDinheiroCpu= NULL;
    Objeto* recursoCeluloseCpu= NULL;
    Objeto* recursoPedregulhoCpu= NULL;
    Objeto* recursoMetalCpu= NULL;

    SDL_Color cRecurso{0, 0, 0}; //decidir cor
    SDL_Texture* tRecurso;
    TTF_Font* font = NULL;
    Botao_Compra* compra= NULL;
    Botao_Iniciar* bIniciar = NULL;
    Objeto* menuInicial = NULL;
    Objeto* mapa = NULL;
    int tempo = 0;
    bool on;
    SDL_Window* janela = NULL;

    SDL_Renderer* render = NULL;

};

void combate_unidade(Unidade** unidade1, Unidade** unidade2);
void ataca_geraRecurso(Unidade* unidade, GeraRecursos* geradora);
void ataca_fabrica(Unidade* unidade, Fabrica* fbrc);
void anda(Unidade** unidade, Unidade** destino);

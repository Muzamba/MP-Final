/**
 * @file Botao.h
 * @author Nome do time (a definir)
 * @brief Definiçao e implementaçao de todos os botoes presentes no jogo.
 * @version 0.99
 * @date 2018-12-02
 * 
 * @copyright Copyright (c) 2018 (nao sei o que colocar aqui)
 * 
 */
#pragma once
#include "Objeto.h"
#include "Head.h"
#include <SDL2/SDL.h>

/**
 * @class Botao_Iniciar Botao.h
 * @brief Classe do Botao iniciar que esta na tela inicial.
 */
class Botao_Iniciar : public Objeto {
public:
    /**
     * @brief Constroi um objeto Botao_Iniciar.
     * 
     * @param X - Posiçao X do Botao na tela.
     * @param Y - Posiçao Y do Botao na tela.
     */
    Botao_Iniciar(int X, int Y) : Objeto(X, Y){}
    
    /**
     * @brief Faz o jogo iniciar quando for clicado em cima do botao.
     * 
     * @param evento - Evento que esta sendo manipulado no momento.
     */
    void handleEvent(SDL_Event* evento);

};

/**
 * @class Botao_Load Botao.h
 * @brief Classe do botao de load que esta na tela inicial.
 */
class Botao_Load : public Objeto {
public:
    /**
     * @brief Constroi um objeto Botao_Load.
     * 
     * @param X - Posiçao da Coordenada X do Botao na tela.
     * @param Y - Posiçao da Coordenada Y do Botao na tela.
     */
    Botao_Load(int X, int Y) : Objeto(X, Y) {}

    /**
     * @brief Carrega o dados de um jogo salvo antes e depois inicia o jogo de onde
     * parou.
     * 
     * @param evento - Evento que esta sendo manipulado no momento.
     */
    void handleEvent(SDL_Event* evento);
};

/**
 * @class Botao_Pause Botao.h
 * @brief Classe do botao de pause que esta presente durante o jogo inteiro.
 */
class Botao_Pause : public Objeto {
public:
    /**
     * @brief Constroi um objeto Botao_Pause.
     * 
     * @param X - Posiçao da Coordenada X do Botao na tela.
     * @param Y - Posiçao da Coordenada Y do Botao na tela.
     */
    Botao_Pause(int X, int Y) : Objeto(X, Y) {}

    /**
     * @brief Paraliza o jogo.
     * 
     * @param evento - Evento que esta sendo manipulado no momento.
     */
    void handleEvent(SDL_Event* evento);
};

/**
 * @class Botao_Resume Botao.h
 * @brief Classe do botao que retoma o jogo que  esta parado pelo pause que 
 * esta presente durante o jogo inteiro.
 */
class Botao_Resume : public Objeto {
public:
    /**
     * @brief Constroi um objeto Botao_Resume.
     * 
     * @param X - Posiçao da Coordenada X do Botao na tela.
     * @param Y - Posiçao da Coordenada Y do Botao na tela.
     */
    Botao_Resume(int X, int Y) : Objeto(X, Y) {}

    /**
     * @brief Retoma o jogo paralizado.
     * 
     * @param evento - Evento que esta sendo manipulado no momento.
     */
    void handleEvent(SDL_Event* evento);
};
/**
 * @class Botao_Sair Botao.h
 * @brief Classe do botao sair que esta presente na tela inicial.
 */
class Botao_Sair : public Objeto {
public:
    /**
     * @brief Constroi um objeto Botao_Sair.
     * 
     * @param X - Posiçao da Coordenada X do Botao na tela.
     * @param Y - Posiçao da Coordenada Y do Botao na tela.
     */
    Botao_Sair(int X, int Y) : Objeto(X, Y) {}

    /**
     * @brief Fecha o jogo.
     * 
     * @param evento - Evento que esta sendo manipulado no momento.
     */
    void handleEvent(SDL_Event* evento);
};

/**
 * @class Botao_Save Botao.h
 * @brief Classe do botao que salva o estado do jogo em um arquivo para que
 * possa ser acessado pelo load futuramente e esta presente na tela durante
 * o jogo inteiro.
 * 
 */
class Botao_Save : public Objeto {
public:
    /**
     * @brief Constroi um objeto Botao_Save.
     * 
     * @param X - Posiçao da Coordenada X do Botao na tela.
     * @param Y - Posiçao da Coordenada Y do Botao na tela.
     */
    Botao_Save(int X, int Y) : Objeto(X, Y) {}

    /**
     * @brief Salva o estado do jogo atual em um arquivo.
     * 
     * @param evento - Evento que esta sendo manipulado no momento.
     */
    void handleEvent(SDL_Event* evento);
};

/**
 * @brief Manipulaç~ao dos cliques de compra durante o jogo.
 * 
 * @param evento - Evento que esta sendo manipulado no momento.
 */
void buttomEvents(SDL_Event* evento);

/**
 * @brief Localiza em que area da tela foi clicada para ver se o player esta
 * comprando algo.
 * 
 * @param x - Coordenada X do mause no tempo atual.
 * @param y - Coordenada Y do mause no tempo atual.
 */
void retornaBotao(int* x, int* y);

/**
 * @brief Tranformaçao das Coordenadas do mause para uma grid que fica mais
 * facil para manipular.
 * 
 * @param X - Coordenada X do mause no tempo atual.
 * @param Y - Coordenada Y do mause no tempo atual.
 */
void to_Cord(int* X, int* Y);

/**
 * @brief Verifica se um clique atual foi em uma fabrica.
 * 
 * @param X - Coordenada X do mause no tempo atual.
 * @param Y - Coordenada Y do mause no tempo atual.
 * @return true - O clique foi em uma fabrica.
 * @return false - O clique nao foi em uma fabrica.
 */
bool verifica_clique_fabrica(const int* X, const int* Y);

/**
 * @brief Verfica se o clique foi dentro do mapa.
 * 
 * @param x - Coordenada X do mause no tempo atual.
 * @param y - Coordenada Y do mause no tempo atual.
 * @return true - O clique foi dentro do mapa.
 * @return false - O clique foi fora do mapa.
 */
bool in_range_mapa(int x, int y); /* Testado */

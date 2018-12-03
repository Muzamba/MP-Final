/**
 * @file Objeto.h
 * @author Nome do time (a definir)
 * @brief Definiçao e implementaçao da casse objeto.
 * @version 0.99
 * @date 2018-12-02
 * 
 * @copyright Copyright (c) 2018 (nao sei o que colocar aqui)
 * 
 */

// Copyright 2018 João Pedro Assis
#pragma once
#include <SDL2/SDL.h>
/**
 * @class Objeto Objeto.h
 *
 * @brief Classe Objeto, responsável pela rederização da posição
 * e imagem de todos os objetos do jogo (unidades, prédios e menus)
 *
 * A classe de testes possui duas variáveis, pos_x, pox_y.
 * São responsáveis pela devida inicialização da classe, que será herdada
 * por qualquer instância que precisar de tais atributos
 */
class Objeto {
 public:
    /**
     * @brief Constrói um objeto Objeto
     *   Recebe as coordenadas da imagem
     *
     * @param X - Coordenada X
     * @param Y - Coordenada Y
     */
     Objeto(int X, int Y);

    /**
     * @brief Renderiza o objeto
     * 
     * @param r - Renderer onde vai seri renderizado o objeto
     */
    void render(SDL_Renderer* r);

    /**
     * @brief Retorna a coordenada Y da posição do objeto
     *
     * @return int pos_X
     */
    int get_x();

    /**
     * @brief Inicializa a coordenada X do objeto
     *
     * @param X - coordenada x
     */
    void set_x(int X);

    /**
     * @brief Retorna a coordenada Y da posição do objeto
     *
     * @return int pos_Y
     */
    int get_y();

    /**
     * @brief Inicializa a coordenada Y do objeto
     *
     * @param Y - coordenada y
     */
    void set_y(int Y);

    /**
     * @brief Altera a textura atual do objeto.
     * 
     * @param textura - Ponteiro para nova textura.
     */
    void mudaTextura(SDL_Texture* textura);

    /**
     * @brief Inicializa o Src Rect
     * 
     * @param x - Coordenada X.
     * @param y - Coordenada Y.
     * @param w - Largura.
     * @param h - Altura.
     */
    void setSrcRect(int x, int y, int w, int h);

    /**
     * @brief Inicializa o Dest Rect.
     * 
     * @param x - Coordenada X.
     * @param y - Coordenada Y.
     * @param w - Largura.
     * @param h - Altura.
     */
    void setDestRect(int x, int y, int w, int h);
    /**
     * @brief Destrutor do objeto Objeto
     * 
     */
    ~Objeto();
    /**************************************************************************
     *  Variaveis Publicas
     *************************************************************************/
    SDL_Texture* textura = NULL;
    SDL_Rect* srcRect = NULL;
    SDL_Rect* destRect = NULL;

 protected:
    /**************************************************************************
     *  Variaveis Privadas
     *************************************************************************/
    int pos_X;
    int pos_Y;
};

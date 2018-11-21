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

    // por fazer
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

    void mudaTextura(SDL_Texture* textura);

    void setSrcRect(int x, int y, int w, int h);
    
    void setDestRect(int x, int y, int w, int h);

    ~Objeto();
protected:
    SDL_Texture* textura = NULL;
    SDL_Rect* srcRect = NULL;
    SDL_Rect* destRect = NULL;
    int pos_X;
    int pos_Y;
};

/**
 * @file Predio.h
 * @author Nome do time (a definir)
 * @brief Definiçao e implementaçao da classe Predio.
 * @version 0.99
 * @date 2018-12-02
 * 
 * @copyright Copyright (c) 2018 (nao sei o que colocar aqui)
 * 
 */
#pragma once
// Copyright 2018 João Pedro Assis
#ifndef PREDIO
#define PREDIO
#include "Objeto.h"
// #include "Menu.h"



/**
 * @class Predio Predio.h
 *  
 * @brief Classe Predio, responsável pelo gerenciamento geral de todos os
 * prédios presente no jogo. Herda a classe Objeto, portanto possui uma posição
 * e imagem associada 
 * 
 */
class Predio : public Objeto {
 public:
    /**
    * @brief Constrói um objeto Prédio
    *  O Prédio é construído da mesa maneira que um Objeto, pois a inicialização
    *  da variável "vida" é de responsabilidade da classe Fabrica
    * 
    * @param X - Coordenada X.
    * @param Y - Coordenada Y.
    */
    Predio(int X, int Y) : Objeto(X, Y) {}
    // provavel remoçao
    void destroy();
    /**
    * @brief Destrói o objeto Predio
    * 
    */

    ~Predio() {}
    /**
    * @brief Inicializa a variável vida.
    * 
    * @param vida - Vida desejada.
    */
    void set_vida(int vida);

    /**
     * @brief Retorna a variável vida.
     * 
     * @return int - Vida. 
     */
    int get_vida();

 protected:
    /**************************************************************************
     *  Variaveis Protegidas
     *************************************************************************/
    int vida_predio = 0;
    //  Menu menu();
};

#endif

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
    * @param X 
    * @param Y
    */
    Predio(int X, int Y) : Objeto(X, Y) {}

    void destroy();
    /**
    * @brief Destrói o objeto Predio
    * 
    */

    ~Predio() {}
    /**
    * @brief Inicializa a variável vida
    * 
    * @param vida 
    */
    void set_vida(int vida);

    /**
     * @brief Retorna a variável vida
     * 
     * @return int vida 
     */
    int get_vida();

 protected:
    int vida_predio;
    //  Menu menu();
};

#endif
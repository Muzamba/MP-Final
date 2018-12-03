/**
 * @file Unidade.h
 * @author Nome do time (a definir)
 * @brief Definiçao e implementaçao da classe Unidade.
 * @version 0.99
 * @date 2018-12-02
 * 
 * @copyright Copyright (c) 2018 (nao sei o que colocar aqui)
 * 
 */
#pragma once
#include "Objeto.h"
#include <vector>
// "Copyright [2018] <Waliff Cordeiro>"

/**
 * @class Unidade Unidade.h
 *
 * @brief Classe Unidade, responsável pelas ações das unidades
 * como movimentação, ataque, mudança de imagem e destruição dos personagens
 *
 * A classe de testes possui seis variáveis:
 * pos_x, pos_y. tipo da unidade, vida, velocidade e dano
 * Tais atributos inicializam a classe e contém características de suas heranças
 * por qualquer instância que precisar de tais atributos
 */

class Unidade : public Objeto {
 public:
    /**
     * @brief Constroi um objeto Unidade
     * 
     * @param X - Coordenada X.
     * @param Y - Coordenada Y.
     * @param tipo - Tipo desejada.
     * @param vida - Vida desejada.
     * @param velocidade - Velocidae desejada.
     * @param dano - Dano desejado.
     * @param nivel - Nivel desejado.
     */
    Unidade(int X, int Y, int tipo, int vida, int velocidade,
            int dano, int nivel);

    /**
     * @brief Destrutor do objeto Unidade.
     * 
     */
    virtual ~Unidade();

    /**
     * @brief Movimenta personagem
     * Recebe a coordenada do personagem e
     * de acordo com sua velocidade, retorna sua nova posição
     *
     */
    void anda();
    /**
     * @brief Ataca um predio.(possivel remoçao)
     * 
     */
    void ataca_predio();

    /**
     * @brief Muda uma imagem (possivel remoçao)
     * 
     */
    void mudaImagem();

    /**
     * @brief Destroi uma Unidade. (possivel remoçao)
     * 
     * @param unidades - Vetor de unidades.
     */
    void destroy(std::vector<Unidade> *unidades);

    /**
     * @brief Retorna recursos
     * 
     * @return int - Recursos
     */
    int getPreco_recursos() const;

    /**
     * @brief Inicializa Preco recursos
     * 
     * @param preco_recursos - Preco recursos desejado.
     */
    void setPreco_recursos(int preco_recursos);

    /**
     * @brief Retorna dinheiro.
     * 
     * @return int - Dinheiro.
     */
    int getPreco_dinheiro() const;

    /**
     * @brief Inicializa Preco dinheiro.
     * 
     * @param preco_dinheiro - Preco dinheiro desejado.
     */
    void setPreco_dinheiro(int preco_dinheiro);

    /**
     * @brief Retorna Vida.
     * 
     * @return int - Vida.
     */
    int getVida() const;

    /**
     * @brief Inicializa Vida.
     * 
     * @param vida - Vida desejada.
     */
    void setVida(int vida);

    /**
     * @brief Retorna Velocidade.
     * 
     * @return int - Velocidade.
     */
    int getVelocidade() const;

    /**
     * @brief Inicializa Velocidade.
     * 
     * @param velocidade - Velocidade desejada.
     */
    void setVelocidade(int velocidade);

    /**
     * @brief Retorna Tipo.
     * 
     * @return int - Tipo.
     */
    int getTipo() const;

    /**
     * @brief Inicializa Tipo.
     * 
     * @param tipo - Tipo desejado.
     */
    void setTipo(int tipo);

    /**
     * @brief Retorna Dano.
     * 
     * @return int - Dano.
     */
    int getDano() const;

    /**
     * @brief Inicializa Dano.
     * 
     * @param dano - Dano desejado.
     */
    void setDano(int dano);

    /**************************************************************************
     *  Variaveis Publicas
     *************************************************************************/
    int tipo;

 protected:
    /**************************************************************************
     *  Variaveis Protegidas
     *************************************************************************/
     int nivel;

public:
    /**
     * @brief Retorna Nivel.
     * 
     * @return int - Nivel.
     */
    int getNivel() const;

    /**
     * @brief Inicializa Nivel.
     * 
     * @param nivel - Nivel desejado.
     */
    void setNivel(int nivel);

protected:
    /**************************************************************************
     *  Variaveis Protegidas
     *************************************************************************/
    int vida;

    // int preco_recursos;

    // int preco_dinheiro;

    int velocidade;

    int dano;
};

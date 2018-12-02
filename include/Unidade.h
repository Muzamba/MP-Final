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
    Unidade(int X, int Y, int tipo, int vida, int velocidade, int dano, int nivel);

    virtual ~Unidade();

    /**
     * @brief Movimenta personagem
     * Recebe a coordenada do personagem e
     * de acordo com sua velocidade, retorna sua nova posição
     *
     */
    void anda();

    void ataca_predio();

    void mudaImagem();

    void destroy(std::vector<Unidade> *unidades);

    int getPreco_recursos() const;

    void setPreco_recursos(int preco_recursos);

    int getPreco_dinheiro() const;

    void setPreco_dinheiro(int preco_dinheiro);

    int getVida() const;

    void setVida(int vida);

    int getVelocidade() const;

    void setVelocidade(int velocidade);

    int getTipo() const;

    void setTipo(int tipo);

    int getDano() const;

    void setDano(int dano);

    int tipo;
 protected:
    int nivel;
public:
    int getNivel() const;

    void setNivel(int nivel);

protected:

    int vida;

    int preco_recursos;

    int preco_dinheiro;

    int velocidade;

    int dano;
};

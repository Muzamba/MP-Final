
/**
 * @file Fabrica.h
 * @author Nome do time (a definir)
 * @brief Definiçao e implementaçao da classe Fabrica
 * @version 0.99
 * @date 2018-12-02
 * 
 * @copyright Copyright (c) 2018 (nao sei o que colocar aqui)
 * 
 */
// Copyright 2018 João Pedro Assis
#ifndef MP_FINAL_INCLUDE_FABRICA_H_
#define  INCLUDE_FABRICA_H_
#include "Predio.h"
#include "Head.h"
#include "Unidade.h"
/*struct Referencias {
int T_ESPERA_INICIAL = 20;
int NIVEL = 1;
};

Referencias ref;*/


/******************************************************************************
 *  Typedefs
 *****************************************************************************/
typedef int FABRICA;
typedef int UNIDADES;

/**
 * @class Fabrica Fabrica.h
 * @brief Classe da construçao do tipo Fabrica.
 */
class Fabrica : public Predio {
 public:
    /**
     * @brief Controi um objeto Fabrica.
     * 
     * @param X - Coordenada X.
     * @param Y - Coordenada Y.
     * @param tipo - Tipo desejado do objeto fabrica
     */
    Fabrica(int X, int Y, int tipo)
    : Predio(X, Y) {
       Fabrica::tipo = tipo;
       Fabrica::tempoEspera = TEMPO_ESPERA_INICIAL_FABRICA;
       Fabrica::nivel = 1;
       Fabrica::vida_predio = VIDA_INICIAL_FABRICA;
       Fabrica::atributos_unidade(Fabrica::nivel);
    }

    /**
     * @brief Retorna o tempoEspera.
     * 
     * @return int - Tempo de espera.
     */
    int get_tempoEspera();

    /**
     * @brief Inicializa o tempoEspera
     * 
     * @param tempo - Tempo desejado;
     */
    void set_tempoEspera(int tempo);

    /**
     * @brief Retorna o nivel.
     * 
     * @return int - Nivel.
     */
    int get_nivel();

    /**
     * @brief Inicializa o nivel.
     * 
     * @param nivel - Nivel desejado.
     */
    void set_nivel(int nivel);

    /**
     * @brief Verifica a possibilidade de poder dar upgrade em uma fabrica.
     * 
     * @param custo - Preço do upgrade.
     * @param capital - Recurso Atual.
     * @return true - Pode dar upgrade.
     * @return false - Nao pode dar upgrade.
     */
    bool can_upgrade_fabrica(int custo, int capital);

    /**
     * @brief Realiza o upgrade na fabrica.
     * 
     * @param dinheiro - Ponteiro para o dinheiro do jogador.
     */
    /* <EU 004> e <EU 005> */
    bool upgrade_fabrica(int* dinheiro);

    /**
     * @brief Atualiza atributos das tropas geradas por essa fabrica.
     * 
     * @param nivel - Nivel atual dessa fabrica.
     */
    void atributos_unidade(FABRICA nivel);

    /**
     * @brief Sei la nao tem implementaçao.
     * 
     * @param matI 
     * @param matJ 
     * @return Unidade* 
     */
    Unidade* geraUnidade(int matI, int matJ);

    /**
     * @brief Retorna o Tipo
     * 
     * @return int - Tipo
     */
    int getTipo() const;

    /**
     * @brief Inicializa o Tipo.
     * 
     * @param tipo - Tipo desejado.
     */
    void setTipo(int tipo);

    /**
     * @brief Destrutor do objeto Fabrica
     * 
     */
    ~Fabrica() {}

    /**************************************************************************
     *  Variaveis Publicas
     *************************************************************************/
    //  -------------------- Variáveis da Fábrica em si -----------------------
    int tipo;
    FABRICA tempoEspera;  // T de espera para uma unidade ser gerada
    int nivel = 1;  // Nível da fábrica (nível maior, menor tempo de espera)
    // FABRICA tipo;  // Variável não deve ser alterada
    FABRICA preco_recurso = PRECO_RECURSO_FABRICA;
    FABRICA custo_upgrade_fab = CUSTO_INICIAL_DO_UPGRADE_UNIDADE;

    // ---------------------- Variáveis das Unidades geradas ------------------

    UNIDADES vida = 5;
    UNIDADES dano = 5;
    UNIDADES velocidade = 5;
    UNIDADES custo_upgrade_und = CUSTO_INICIAL_DO_UPGRADE_UNIDADE;
    UNIDADES custo_unidade = PRECO_INICIAL_UNIDADE;
};

#endif  // MP_FINAL_INCLUDE_FABRICA_H_

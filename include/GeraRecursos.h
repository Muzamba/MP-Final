/**
 * @file GeraRecursos.h
 * @author Nome do time (a definir)
 * @brief Definiçao e implementaçao da classe GeraRecursos. 
 * @version 0.99
 * @date 2018-12-02
 * 
 * @copyright Copyright (c) 2018 (nao sei o que colocar aqui)
 * 
 */
#pragma once
#ifndef INCLUDE_GERARECURSOS_H_
#define INCLUDE_GERARECURSOS_H_
// "Copyright [year] <Pedro>"
#include "Head.h"
#include "Predio.h"

/**
 * @class GeraRecursos GeraRecursos.h
 * @brief Classe da construçao do tipo GeraRecursos.
 * 
 */
class GeraRecursos : public Predio {
 public:
    /**
     * @brief Constro um objeto Gera Recursos.
     * 
     * @param X - Coordenada X.
     * @param Y - Coordenada Y.
     * @param tipo - Tipo da GeraRecursos.
     */
    GeraRecursos(int X, int Y, int tipo);

    /**
     * @brief Produz os recurso
     * 
     * @return int - Taxa de produçao.
     */
    int produzirRecurso();

    /**
     * @brief Realiza o upgrade de uma GeraRecursos.
     * 
     * @param dinheiro - Ponteiro para o dinheiro do jogador.
     * @return true - Upgrade realizado.
     * @return false - Nao e possivel realizar o upgrade.
     */
    bool upgrade(int *dinheiro);

    /**
     * @brief Destrutor do objeto Gera Recursos.
     * 
     */
    ~GeraRecursos();

    /**
     * @brief Retorna o Nivel
     * 
     * @return int - NIvel.
     */
    int getNivel() const;

    /**
     * @brief Inicializa o Nivel.
     * 
     * @param nivel - Nivel desejado.
     */
    void setNivel(int nivel);

    /**
     * @brief Retorna a Taxa.
     * 
     * @return int - Taxa.
     */
    int getTaxa() const;

    /**
     * @brief Inicializa a Taxa
     * 
     * @param taxa - Taxa desejada.
     */
    void setTaxa(int taxa);

    /**
     * @brief Retorna o Tipo.
     * 
     * @return int - Tipo;
     */
    int getTipo() const;

    /**
     * @brief Inicializa o Tipo.
     * 
     * @param tipo - Tipo desejado.
     */
    void setTipo(int tipo);

 private:
    /**************************************************************************
     *  Variaveis Privadas
     *************************************************************************/
    int nivel = 0;  // Nivel incial 0
    int taxa = TAXA_COLETA;  // Taxa de coleta inicial TAXA_COLETA
    int tipo;  // Selecionado pelo construtor
    int preco_recurso = PRECO_RECURSO_GERA;
    int preco_dinheiro = PRECO_DINHEIRO_GERA;
};
#endif  // INCLUDE_GERARECURSOS_H_

/**
 * @file Player.h
 * @author Nome do time (a definir)
 * @brief Definiçao e implementaçao da classe Player.
 * @version 0.99
 * @date 2018-12-02
 * 
 * @copyright Copyright (c) 2018 (nao sei o que colocar aqui)
 * 
 */
#pragma once
//#pragma once
#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_

// "Copyright [year] <Pedro>"

#include "Head.h"
#include <vector>
#include "GeraRecursos.h"
#include "Fabrica.h"
#include "Unidade.h"
#include "Jogo.h"


/**
 * @class Player Player.h
 * @brief Classe que possui todos os dados de um jogador ou cpu.
 * 
 */
class Player {
 public:
    /* funcionalidades */
    /**
     * @brief Compra uma GeraRecurso.
     * 
     * @param x - Coordenada X de onde sera efetuada a compra.
     * @param y - Coordenada Y de onde sera efetuada a compra.
     * @param tipo - Tipo da GeraRecursos comprada.
     * @return true - Compra realizada com sucesso.
     * @return false - Falha na compra.
     */
    bool compra_GeraRecurso(int x, int y, RECURSO tipo);

    /**
     * @brief Compra uma Fabrica.
     * 
     * @param x - Coordenada X de onde sera efetuada a compra.
     * @param y - Coordenada Y de onde sera efetuada a compra.
     * @param tipo - Tipo da Fabrica comprada.
     * @return true - Compra realizada com sucesso.
     * @return false - Falha na compra.
     */
    bool compra_Fabrica(int x, int y, UNIDADE tipo);

    /**
     * @brief Compra uma Unidade.
     * 
     * @param x - Coordenada X de onde sera efetuada a compra.
     * @param y - Coordenada Y de onde sera efetuada a compra.
     * @param tipo - Tipo da Unidade comprada.
     * @param nivel - Nivel da Unidade comprada.
     * @return true - Compra realizada com sucesso.
     * @return false -Falha na compra.
     */
    bool compra_Unidade(int x, int y, UNIDADE tipo, int nivel);

    /**
     * @brief Atualiza os recursos de acordo com as suas GeraRecursos.
     * 
     */
    void atualizar_Recursos();

    /**
     * @brief Retorna Vida.
     * 
     * @return int - Vida.
     */
    int getVida() const;

    /**
     * @brief Inicializa Vida
     * 
     * @param vida - Vida desejada.
     */
    void setVida(int vida);

    /*Listas de Objetos*/
    //std::vector<GeraRecursos> lista_GeraRecursos;
    //std::vector<Fabrica> lista_Fabrica;
    //std::vector<Unidade> lista_Unidade;

    /* Construtor e destrutor(depende do obj) */
    /**
     * @brief Constroi um objeto Player.
     * 
     */
    Player();
    /**
     * @brief Destrutor do objeto Player.
     * 
     */
    virtual ~Player();

    /* Get e Set */
    /**
     * @brief Retorna Pedregulho.
     * 
     * @return int - Pedregulho.
     */
    int getPedregulho() const;

    /**
     * @brief Inicializa Pedregulho.
     * 
     * @param pedregulho - Pedregulho desejado.
     */
    void setPedregulho(int pedregulho);

    /**
     * @brief Retorna Celulose.
     * 
     * @return int - Celulose.
     */
    int getCelulose() const;

    /**
     * @brief Inicializa Celulose.
     * 
     * @param celulose - Celulose desejada.
     */
    void setCelulose(int celulose);

    /**
     * @brief Retorna Metal.
     * 
     * @return int - Metal.
     */
    int getMetal() const;

    /**
     * @brief Inicializa Metal.
     * 
     * @param metal - Metal desejado.
     */
    void setMetal(int metal);

    /**
     * @brief Returna Dinheiro.
     * 
     * @return int - Dinheiro.
     */
    int getDinheiro() const;

    /**
     * @brief Inicializa Dinheiro.
     * 
     * @param dinheiro - Dinheiro desejado.
     */
    void setDinheiro(int dinheiro);
    
    /**
     * @brief Returna Pontos.
     * 
     * @return int - Pontos.
     */
    int getPontos() const;

    /**
     * @brief Inicializa Pontos.
     * 
     * @param pontos - Pontos desejados.
     */
    void setPontos(int pontos);

    /**************************************************************************
     *  Variaveis Publicas
     *************************************************************************/
    int vida;
    int pedregulho;  // Pedra
    int celulose;    // Papel
    int metal;       // Tesoura
    int dinheiro;
    int pontos;
private:
    /* Metodos auxiliares */
    /**
     * @brief Retira recursos na hora da compra.
     * 
     * @param tipo - Tipo da unidade comprada.
     */
    void retira_recurso_fabrica(UNIDADE tipo);

    /**
     * @brief Verifica a possibilidade de compra.
     * 
     * @param tipo - Tipo da fabrica desejada.
     * @return true - Compra possivel.
     * @return false - Compra impossivel.
     */
    bool possui_recursos_fabrica(UNIDADE tipo);

    /**
     * @brief Retira recursos na hora da compra.
     * 
     * @param tipo - Tipo da GeraRecursos comprada.
     */
    void retira_recurso_geraRecurso(RECURSO tipo);

    /**
     * @brief Verifica a possibilidade de compra.
     * 
     * @param tipo - Tipo de GeraRecursos desejado.
     * @return true - Compra possivel.
     * @return false - Compra impossivel.
     */
    bool possui_recursos_geraRecurso(RECURSO tipo);

    /**
     * @brief Retira recursos na hora da compra.
     * 
     * @param tipo - Tipo da unidade desejada.
     * @param nivel - Nivel da unidade comprada.
     */
    void retira_recurso_unidade(UNIDADE tipo, int nivel);

    /**
     * @brief Verifica a possibilidade de compra.
     * 
     * @param tipo - Tipo de unidade desejado.
     * @param nivel - Nivel da unidade.
     * @return true - Compra possivel.
     * @return false - Compra impossivel.
     */
    bool possui_recursos_unidade(int tipo, int nivel);

    /**
     * @brief Verifica se o espaço e adequado para colocar um predio.
     * 
     * @param x - Coordenadas X do mouse atual.
     * @param y - Coordenadas Y do mouse atual.
     * @return true - Espaço valido.
     * @return false - Espaço invalido.
     */
    bool verifica_espaco_predio(int x, int y);

    /**
     * @brief Verifica se o espaço ja esta ocupado.
     * 
     * @param x 
     * @param y 
     * @return true 
     * @return false 
     */
    bool verifica_espaco_ocupado(int x, int y);
};

/* Funções auxiliares para compra */
/**
 * @brief Funçao auxiliar para definir uma textura na hora a compra um GeraRecursos
 * 
 * @param tipo - Tipo da compra.
 * @return TEXTURAS - Textura que sera utilizada.
 */
TEXTURAS retorna_textura_recurso(int tipo);

/**
 * @brief Funçao auxiliar para definir uma textura na hora a compra uma Fabrica.
 * 
 * @param tipo - Tipo da Compra
 * @return TEXTURAS - Textura que sera utilizada.
 */
TEXTURAS retorna_textura_fabrica(int tipo);

/**
 * @brief Funçao auxiliar para definir uma textura na hora a compra uma Unidade.
 * 
 * @param nivel - Nivel da Unidade comprada.
 * @param tipo - Tipo da Compra.
 * @return TEXTURAS - Textura que sera utilizada.
 */
TEXTURAS retorna_textura_unidade(int nivel, int tipo);

#endif  // INCLUDE_PLAYER_H_
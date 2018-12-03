/**
 * @file Head.h
 *
 * @brief Arquivo cabeçalho para defines e declaraçoes de enum's
 *
 * @copyright Copyright (c) 2018 (nao sei o que colocar aqui)
 */
#pragma once
#ifndef HEAD
#define HEAD

/******************************************************************************
 *  Enum's
 *****************************************************************************/
enum UNIDADE {PAPEL, PEDRA, TESOURA};
enum RECURSO {CELULOSE, PEDREGULHO, METAL};
enum TEXTURAS {
    MAPA,
    TEMPO,
    VITORIA,
    DERROTA,
    RECURSO_DINHEIRO_PLAYER,
    RECURSO_CELULOSE_PLAYER,
    RECURSO_PEDREGULHO_PLAYER,
    RECURSO_METAL_PLAYER,
    RECURSO_DINHEIRO_CPU,
    RECURSO_CELULOSE_CPU,
    RECURSO_PEDREGULHO_CPU,
    RECURSO_METAL_CPU,
    MENU_PRINCIPAL,
    BOTAO_INICIAR,
    BOTAO_INICIAR_SOBRE,
    BOTAO_INICIAR_CLICK,
    BOTAO_SAIR,
    BOTAO_SAIR_SOBRE,
    BOTAO_SAIR_CLICK,
    BOTAO_PAUSE,
    BOTAO_PAUSE_SOBRE,
    BOTAO_PAUSE_CLICK,
    BOTAO_RESUME,
    BOTAO_RESUME_SOBRE,
    BOTAO_RESUME_CLICK,
    BOTAO_LOAD,
    BOTAO_LOAD_SOBRE,
    BOTAO_LOAD_CLICK,
    BOTAO_SAVE,
    BOTAO_SAVE_SOBRE,
    TROPA_PAPEL,
    TROPA_PAPEL2,
    TROPA_PAPEL_CPU,
    TROPA_PAPEL2_CPU,
    TROPA_PEDRA,
    TROPA_PEDRA2,
    TROPA_PEDRA_CPU,
    TROPA_PEDRA2_CPU,
    TROPA_TESOURA,
    TROPA_TESOURA2,
    TROPA_TESOURA_CPU,
    TROPA_TESOURA2_CPU,
    FABRICA_PAPEL,
    FABRICA_PAPEL_UP,
    FABRICA_PEDRA,
    FABRICA_PEDRA_UP,
    FABRICA_TESOURA,
    FABRICA_TESOURA_UP,
    GERAR_PAPEL,
    GERAR_PAPEL_UP,
    GERAR_PEDRA,
    GERAR_PEDRA_UP,
    GERAR_TESOURA,
    GERAR_TESOURA_UP,
    BASE_PLAYER,
    BASE_CPU,
    TEX_TOTAL
};

enum TIPO {
    NADA,
    UNIDADE_PAPEL,
    UNIDADE_PEDRA,
    UNIDADE_TESOURA,
    GERA_CELULOSE,
    GERA_PEDREGULHO,
    GERA_METAL,
    FABRICAR_PAPEL,
    FABRICAR_PEDRA,
    FABRICAR_TESOURA,
    U_GERA_CELULOSE,
    U_GERA_PEDREGULHO,
    U_GERA_METAL,
    U_FABRICA_PAPEL,
    U_FABRICA_PEDRA,
    U_FABRICA_TESOURA
};

enum EFEITOS {
    EXPLOSAO,
    SOCO,
    SEM_DINHEIRO,
    SEM_RECURSO,
    LUGAR_INV,
    EFEITO_TOTAL
};
enum MUSICAS {
    MUS_INICIAL,
    MUS_JOGO_NARUTO,
    MUS_TOTAL
};
/******************************************************************************
 *  Define Unidade
 *****************************************************************************/
#define PRECO_INICIAL_UNIDADE 50
#define CUSTO_INICIAL_DO_UPGRADE_UNIDADE 20

/******************************************************************************
 *  Define Player
 *****************************************************************************/
#define VIDA_INCIAL_PLAYER 1000
#define RECURSO_INICIAL 200
#define DINHEIRO_INICIAL 100

/******************************************************************************
 *  Define Fabrica
 *****************************************************************************/
#define PRECO_RECURSO_FABRICA 100
#define PRECO_DINHEIRO_FABRICA 30
#define VIDA_INICIAL_FABRICA 100
#define TEMPO_ESPERA_INICIAL_FABRICA 20
#define CUSTO_INICIAL_UPGRADE_FABRICA 20


/******************************************************************************
 *  Define GeraRecurso
 *****************************************************************************/
#define TAXA_COLETA 1
#define PRECO_RECURSO_GERA 100
#define PRECO_DINHEIRO_GERA 30
#define PRECO_UPGRADE_GERA 20

/******************************************************************************
 *  Define Atributos Unidades
 *****************************************************************************/
#define VIDA_UNIDADE_1 10
#define VELO_UNIDADE_1 1
#define VELO_UNIDADE_1_CPU -1
#define DANO_UNIDADE_1 10
#define PRECO_UNIDADE_1 50

#define VIDA_UNIDADE_2 20
#define VELO_UNIDADE_2 1
#define VELO_UNIDADE_2_CPU -1
#define DANO_UNIDADE_2 20
#define PRECO_UNIDADE_2 75

#define VIDA_UNIDADE_3 30
#define VELO_UNIDADE_3 1
#define VELO_UNIDADE_3_CPU -1
#define DANO_UNIDADE_3 30
#define PRECO_UNIDADE_3 100

/******************************************************************************
 *  Define para melhor entendimento do codigo
 *****************************************************************************/
#define PLAYER_MORREU 1
#define PLAYER_N_MORREU 0
#endif // HEAD

// copyright 2018 Switch Dreams
#ifndef INCLUDE_HEAD_H_
#define INCLUDE_HEAD_H_

enum UNIDADE {
    PAPEL,
    PEDRA,
    TESOURA
};

enum RECURSO {
    CELULOSE,
    PEDREGULHO,
    METAL
};

enum TEXTURAS {
    MAPA,
    MENU_PRINCIPAL,
    BOTAO_INICIAR,
    BOTAO_INICIAR_S,
    BOTAO_INICIAR_P,
    TROPA_PAPEL,
    TROPA_PAPEL2,
    TROPA_PEDRA,
    TROPA_PEDRA2,
    TROPA_TESOURA,
    TROPA_TESOURA2,
    FABRICA_PAPEL,
    FABRICA_PEDRA,
    FABRICA_TESOURA,
    GERAR_PAPEL,
    GERAR_PEDRA,
    GERAR_TESOURA,
    BASE_PLAYER,
    BASE_CPU,
    TEX_TOTAL
};

enum OPERACOES{
    NADA,
    INICIA_JOGO,
    TOTAL
};

// ---------- Define Unidade ----------------

#define PRECO_INICIAL_UNIDADE 50

// ---------- Define Player -----------------

#define RECURSO_INICIAL 100
#define DINHEIRO_INICIAL 200

// --------- Define Fabrica ----------------

#define PRECO_RECURSO_FABRICA 50
#define PRECO_DINHEIRO_FABRICA 100
#define VIDA_INICIAL_FABRICA 100
#define TEMPO_ESPERA_INICIAL_FABRICA 20
#define CUSTO_INICIAL_DO_UPGRADE_FABRICA 200
#define CUSTO_INICIAL_DO_UPGRADE_UNIDADE 200

// -------- Define GeraRecuso--------------

#define TAXA_COLETA 5
#define PRECO_RECURSO_GERA 50
#define PRECO_DINHEIRO_GERA 100

#endif  // INCLUDE_HEAD_H_

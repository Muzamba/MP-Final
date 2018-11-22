#pragma once
#ifndef HEAD
#define HEAD

enum UNIDADE {PAPEL, PEDRA, TESOURA};
enum RECURSO {CELULOSE, PEDREGULHO, METAL};
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


enum TIPO {
    NADA, 
    GERA_CELULOSE, 
    GERA_PEDREGULHO, 
    GERA_METAL, 
    GERA_PAPEL, 
    GERA_PEDRA, 
    GERA_TESOURA
};


//----------Define Player -----------------

#define RECURSO_INICIAL 200
#define DINHEIRO_INICIAL 100

//---------_Define Fabrica ----------------

#define PRECO_RECURSO_FABRICA 100
#define PRECO_DINHEIRO_FABRICA 100

// -------- Define GeraRecuso--------------

#define TAXA_COLETA 1
#define PRECO_RECURSO_GERA 100
#define PRECO_DINHEIRO_GERA 100

#endif //HEAD
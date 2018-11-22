// Copyright 2018 João Pedro Assis
#ifndef  INCLUDE_FABRICA_H_
#define  INCLUDE_FABRICA_H_
#include "Predio.h"
#include "Head.h"
/*struct Referencias {
int T_ESPERA_INICIAL = 20;
int NIVEL = 1;
};

Referencias ref;*/



typedef int FABRICA;
typedef int UNIDADES;


class Fabrica : public Predio {
 public:
    Fabrica(int X, int Y, UNIDADE tipo)
    : Predio(X, Y) {
       Fabrica::tipo = tipo;
       Fabrica::tempoEspera = TEMPO_ESPERA_INICIAL_FABRICA;
       Fabrica::nivel = 1;
       Fabrica::vida_predio = VIDA_INICIAL_FABRICA;
       Fabrica::atributos_unidade(Fabrica::nivel);
    }
    int get_tempoEspera();
    void set_tempoEspera(int tempo);

    int get_nivel();
    void set_nivel(int nivel);

    bool can_upgrade_fabrica(int custo, int capital);
    void upgrade_fabrica(int* dinheiro);

    void atributos_unidade(FABRICA nivel);
    void geraUnidade();

    bool can_upgrade_unidade(int custo, int capital);
    void upgrade_unidade();


    ~Fabrica() {}

    //  -------------------- Variáveis da Fábrica em si -----------------------

    FABRICA tempoEspera;  // T de espera para uma unidade ser gerada
    FABRICA nivel;  // Nível da fábrica (nível maior, menor tempo de espera)
    FABRICA tipo;  // Variável não deve ser alterada
    FABRICA preco_recurso = PRECO_RECURSO_FABRICA;
    FABRICA custo_upgrade_fab = CUSTO_INICIAL_DO_UPGRADE_UNIDADE;

    // ---------------------- Variáveis das Unidades geradas ------------------

    UNIDADES vida;
    UNIDADES dano;
    UNIDADES velocidade;
    UNIDADES custo_upgrade_und = CUSTO_INICIAL_DO_UPGRADE_UNIDADE;
};

#endif  // INCLUDE_FABRICA_H_

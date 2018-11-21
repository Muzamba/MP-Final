// Copyright 2018 João Pedro Assis
#ifndef EPADAD
#define EPADAD
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
       Fabrica::tempoEspera = 20;
       Fabrica::nivel = 1;
    }
    int get_tempoEspera();
    void set_tempoEspera(int tempo);

    int get_nivel();
    void set_nivel(int nivel);

    void geraUnidade();
    bool can_upgrade();
    void atributos_unidade(FABRICA nivel);
    ~Fabrica() {}

 protected:
    //  -------------------- Variáveis da Fábrica em si -----------------------

    FABRICA tempoEspera;  // T de espera para uma unidade ser gerada
    FABRICA nivel;  // Nível da fábrica (nível maior, menor tempo de espera)
    FABRICA tipo;  // Variável não deve ser alterada
    FABRICA preco_recurso;
    FABRICA preco_dinheiro;

    // ---------------------- Variáveis das Unidades geradas ------------------

    UNIDADES vida;
    UNIDADES dano;
    UNIDADES velocidade;

    void upgrade();
};

#endif

#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_

// "Copyright [year] <Pedro>"

#include <vector>
#include "GeraRecursos.h"
#include "Fabrica.h"
#include "Unidade.h"
#define RECURSO_INICIAL 50
#define DINHEIRO_INICIAL 200


class Player {
 public:
    /* funcionalidades */
    bool compra_GeraRecurso(int recurso);

    bool compra_Fabrica(int tipo);

    bool compra_Unidade();

    bool atualizar_recursos();

    int pedregulho;  // Pedra
    int celulose;    // Papel
    int metal;       // Tesoura
    int dinheiro;
    int pontos;

    /*Listas de Objetos*/
    std::vector<GeraRecursos> lista_GeraRecursos;
    std::vector<Fabrica> lista_Fabrica;
    std::vector<Unidade> lista_Unidade;

    /* Construtor e destrutor(depende do obj) */
    Player();

    virtual ~Player();

    /* Get e Set */
    int getPedregulho() const;

    void setPedregulho(int pedregulho);

    int getCelulose() const;

    void setCelulose(int celulose);

    int getMetal() const;

    void setMetal(int metal);

    int getDinheiro() const;

    void setDinheiro(int dinheiro);

    int getPontos() const;

    void setPontos(int pontos);
};

#endif  // INCLUDE_PLAYER_H_

#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_

// "Copyright [year] <Pedro>"

#include <vector>
#include "Head.h"
#include "GeraRecursos.h"
#include "Fabrica.h"
#include "Unidade.h"

class Player {
 public:
    /* funcionalidades */
    bool compra_GeraRecurso(RECURSO tipo);

    bool compra_Fabrica(UNIDADE tipo);

    bool compra_Unidade();

    void atualizar_Recursos();

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

 private:
    /* Metodos auxiliares */
    void retira_recurso_fabrica(UNIDADE tipo);

    bool possui_recursos_fabrica(UNIDADE tipo);

    void retira_recurso_geraRecurso(RECURSO tipo);

    bool possui_recursos_geraRecurso(RECURSO tipo);
};

#endif  // INCLUDE_PLAYER_H_

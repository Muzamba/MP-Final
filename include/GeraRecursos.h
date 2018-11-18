#ifndef GERA_RECURSOS_H
#define GERA_RECURSOS_H

#include "Head.h"
#include "Predio.h"

#define TAXA_COLETA 5
#define PRECO_RECURSO_GERA 50
#define PRECO_DINHEIRO_GERA 100
class GeraRecursos : public Predio {
public:
    GeraRecursos(int tipo);

    /* Precisa da classe player pronto */
    void produzirRecurso();

    ~GeraRecursos();

    int getNivel() const;

    void setNivel(int nivel);

    int getTaxa() const;

    void setTaxa(int taxa);

    int getTipo() const;

    void setTipo(int tipo);

    //~GeraRecursos();

private:
    int nivel = 0; //Nivel incial 0
    int taxa = TAXA_COLETA; //Taxa de coleta inicial TAXA_COLETA
    int tipo; //Selecionado pelo construtor
    int preco_recurso = PRECO_RECURSO_GERA;
    int preco_dinheiro = PRECO_DINHEIRO_GERA;

};
#endif //GERA_RECURSOS_H


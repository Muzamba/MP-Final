#pragma once
#ifndef INCLUDE_GERARECURSOS_H_
#define INCLUDE_GERARECURSOS_H_
// "Copyright [year] <Pedro>"
#include "Head.h"
#include "Predio.h"

class GeraRecursos : public Predio {
 public:
    GeraRecursos(int X, int Y, int tipo);

    /* Precisa da classe player pronto */
    int produzirRecurso();

    ~GeraRecursos();

    int getNivel() const;

    void setNivel(int nivel);

    int getTaxa() const;

    void setTaxa(int taxa);

    int getTipo() const;

    void setTipo(int tipo);

 private:
    int nivel = 0;  // Nivel incial 0
    int taxa = TAXA_COLETA;  // Taxa de coleta inicial TAXA_COLETA
    int tipo;  // Selecionado pelo construtor
    int preco_recurso = PRECO_RECURSO_GERA;
    int preco_dinheiro = PRECO_DINHEIRO_GERA;
};
#endif  // INCLUDE_GERARECURSOS_H_

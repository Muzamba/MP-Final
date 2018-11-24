//
// Created by pedro on 14/11/18.
//
#include <GeraRecursos.h>

/**
 * Produzir Recurso
 * @brief acrescenta o recurso dessa determinada geradora(de acordo com a taxa) para o jogador passado de parametro
 * @param jogador - Jogador no qual sera adicionado o recurso
 */
int GeraRecursos::produzirRecurso(){
    return GeraRecursos::taxa;
}

/** Upgrade GeraRecuros
 * @brief O metodo melhora(dobra) a taxa de coleta de recursos da fabrica se a fabrica não ter chegado no nível máximo
 * e se o jogador possui dinheiro suficiente para realizar o upgrade
 * @param dinheiro - Dinheiro do jogador no qual quer da upgrade em sua geraRecurso
 * @return true se conseguiu realizar o upgrade
 *         false se o upgrade não obteve sucesso
 */
bool GeraRecursos::upgrade(int *dinheiro){
    if (GeraRecursos::nivel >= 3) {
        return false;
    }else if (*dinheiro >= PRECO_UPGRADE_GERA) {
        *dinheiro -= PRECO_UPGRADE_GERA;
        GeraRecursos::nivel += 1;
        GeraRecursos::taxa *= 2;
        return true;
    } else {
        /* Mensagem de sem dinheiro */
        return false;
    }
}

/* Constructor */
GeraRecursos::GeraRecursos(int X, int Y, int tipo) : Predio(X, Y), tipo(tipo) {
    GeraRecursos::tipo = tipo;
}

/* Destructor */
GeraRecursos::~GeraRecursos() = default;

/* Get e Setters */
int GeraRecursos::getNivel() const {
    return nivel;
}

void GeraRecursos::setNivel(int nivel) {
    GeraRecursos::nivel = nivel;
}

int GeraRecursos::getTaxa() const {
    return taxa;
}

void GeraRecursos::setTaxa(int taxa) {
    GeraRecursos::taxa = taxa;
}

int GeraRecursos::getTipo() const {
    return tipo;
}

void GeraRecursos::setTipo(int tipo) {
    GeraRecursos::tipo = tipo;
}

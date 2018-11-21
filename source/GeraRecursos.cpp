// Copyright 2018 Pedro Augusto Duarte
// Created by pedro on 14/11/18.
//
#include <GeraRecursos.h>

/**
 * Produzir Recurso
 * @brief acrescenta o recurso dessa determinada geradora(de acordo com a taxa) para o jogador passado de parametro
 * @param jogador - Jogador no qual sera adicionado o recurso
 */
int GeraRecursos::produzirRecurso() {
    return GeraRecursos::taxa;
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

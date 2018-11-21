// Copyright 2018 João Pedro Assis
#include "../include/Fabrica.h"
#include "../include/Player.h"

int Fabrica::get_tempoEspera() {
    return Fabrica::tempoEspera;
}

void Fabrica::set_tempoEspera(int tempo) {
    Fabrica::tempoEspera = tempo;
}

int Fabrica::get_nivel() {
    return Fabrica::nivel;
}

void Fabrica::set_nivel(int nivel) {
    Fabrica::nivel = nivel;
}

void Fabrica::atributos_unidade(FABRICA nivel) {
    Fabrica::vida = nivel*10;
    Fabrica::dano = nivel*5;
    Fabrica::velocidade = nivel*2;
}

bool Fabrica::can_upgrade(int custo, int capital) {
    if (capital >= custo) {
        return true;
    } else {
        return false;
    }
}

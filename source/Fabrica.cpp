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

bool Fabrica::can_upgrade_fabrica(int custo, int capital) {
    if (capital >= custo) {
        return true;
    } else {
        return false;
    }
}

void Fabrica::upgrade_fabrica(int* dinheiro) {
    *dinheiro = *dinheiro - Fabrica::custo_upgrade_fab;
    Fabrica::nivel++;
    Fabrica::custo_upgrade_fab += 20*Fabrica::nivel;
    Fabrica::atributos_unidade(Fabrica::nivel);
    Fabrica::set_vida(Fabrica::nivel*VIDA_INICIAL_FABRICA);
    Fabrica::tempoEspera -= 5;  // cte que pode ser mudado
    if (Fabrica::tempoEspera < 5) {
        Fabrica::tempoEspera = 5;
    }
}

bool Fabrica::can_upgrade_unidade(int custo, int capital) {
    if (capital >= custo) {
        return true;
    } else {
        return false;
    }
}


void Fabrica::upgrade_unidade() {}

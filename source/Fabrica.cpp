// Copyright 2018 João Pedro Assis
#include "../include/Fabrica.h"
#include "../include/Unidade.h"

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
    return capital >= custo;
}

bool Fabrica::upgrade_fabrica(int* dinheiro) {
    if (Fabrica::nivel <= 2) {
        if (Fabrica::can_upgrade_fabrica(Fabrica::custo_upgrade_fab, *dinheiro)) {
            *dinheiro = *dinheiro - Fabrica::custo_upgrade_fab;
            Fabrica::nivel++;
            Fabrica::custo_upgrade_fab += 20 * Fabrica::nivel;
            Fabrica::custo_unidade += 10 * Fabrica::nivel;
            Fabrica::atributos_unidade(Fabrica::nivel);
            Fabrica::set_vida(Fabrica::nivel * VIDA_INICIAL_FABRICA);
            Fabrica::tempoEspera -= 5;  // cte que pode ser mudado
            if (Fabrica::tempoEspera < 5) {
                Fabrica::tempoEspera = 5;
            }
            return true;
        } else {
            /* Mensagem de erro sem dinheiro */
            return false;
        }
    } else {
        /* Mensagem de erro nivel máximo */
        return false;
    }
}

int Fabrica::getTipo() const {
    return tipo;
}

void Fabrica::setTipo(int tipo) {
    Fabrica::tipo = tipo;
}

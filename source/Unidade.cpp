#include <Predio.h>
#include "../include/Unidade.h"
// "Copyright [2018] <Waliff Cordeiro>"

void Unidade::anda() {
    // Atualiza a posição de acordo com a velocidade da unidade
    Unidade::pos_X += velocidade;
}

/*void Unidade::ataca_predio(Predio predio, Player jogador){
    predio.set_vida(predio.get_vida()-Unidade::dano);
    if (predio.get_vida() <= 0) {
        predio.destroy();
    }
}*/

int Unidade::getVida() const {
    return vida;
}

void Unidade::setVida(int vida) {
    Unidade::vida = vida;
}

int Unidade::getVelocidade() const {
    return velocidade;
}

void Unidade::setVelocidade(int velocidade) {
    Unidade::velocidade = velocidade;
}

int Unidade::getDano() const {
    return dano;
}

void Unidade::setDano(int dano) {
    Unidade::dano = dano;
}

Unidade::Unidade(int X, int Y, int tipo, int vida,
        int velocidade, int dano, int nivel) :
Objeto(X, Y), tipo(tipo), vida(vida),
velocidade(velocidade), dano(dano), nivel(nivel) {}

Unidade::~Unidade() {
}

int Unidade::getTipo() const {
    return tipo;
}

void Unidade::setTipo(int tipo) {
    Unidade::tipo = tipo;
}

int Unidade::getNivel() const {
    return nivel;
}

void Unidade::setNivel(int nivel) {
    Unidade::nivel = nivel;
}

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

void Unidade::destroy(std::vector<Unidade> *unidades) {
    // Não tentar remover se estiver vazio
    if (unidades->empty()) {
        return;
    }
    for (auto it = unidades->begin(); it != unidades->end(); it++) {
        // Percorre a lista de unidades para remover a tropa que será destruida
        if (it->pos_X == Unidade::pos_X && it->pos_Y == Unidade::pos_Y) {
            unidades->erase(it);  // Remove a unidade
        }
    }
    // Remover imagem
}

int Unidade::getPreco_recursos() const {
    return preco_recursos;
}

void Unidade::setPreco_recursos(int preco_recursos) {
    Unidade::preco_recursos = preco_recursos;
}

int Unidade::getPreco_dinheiro() const {
    return preco_dinheiro;
}

void Unidade::setPreco_dinheiro(int preco_dinheiro) {
    Unidade::preco_dinheiro = preco_dinheiro;
}

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

Unidade::Unidade(int X, int Y, int tipo, int vida, int velocidade, int dano) :
Objeto(X, Y), tipo(tipo), vida(vida),
velocidade(velocidade), dano(dano) {}

Unidade::~Unidade() {
}

int Unidade::getTipo() const {
    return tipo;
}

void Unidade::setTipo(int tipo) {
    Unidade::tipo = tipo;
}

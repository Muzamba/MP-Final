#include "../include/Unidade.h"

void Unidade::anda() {
	Unidade::pos_X += velocidade;
}

Unidade :: Unidade(int tipo){
	switch (tipo) { // 0 - Papel | 1 - Pedra | 2 - Tesoura
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
	}
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

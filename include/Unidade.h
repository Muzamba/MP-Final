#pragma once
#include "Objeto.h"

class Unidade : public Objeto {
public:
	Unidade (int tipo);
    Unidade() : Objeto() {}
    void anda();
    void ataca();
    void mudaImagem();
    void destroy();
	int getPreco_recursos() const;

	void setPreco_recursos(int preco_recursos);

	int getPreco_dinheiro() const;

	void setPreco_dinheiro(int preco_dinheiro);

	int getVida() const;

	void setVida(int vida);

	int getVelocidade() const;

	void setVelocidade(int velocidade);

	int getDano() const;

	void setDano(int dano);
    ~Unidade();

protected:
    int vida;
	int preco_recursos;
	int preco_dinheiro;
	int velocidade;
	int dano;


};

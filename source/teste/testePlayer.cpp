//
// Created by pedro on 15/11/18.
//
#include"../include/Player.h"
#include"../include/catch.hpp"

TEST_CASE("Construtor da classe Player"){
    Player cpu;
    REQUIRE(cpu.getCelulose() == RECURSO_INICIAL);
    REQUIRE(cpu.getPedregulho() == RECURSO_INICIAL);
    REQUIRE(cpu.getPontos()== 0);
    REQUIRE(cpu.getDinheiro() == DINHEIRO_INICIAL);
    REQUIRE(cpu.getMetal() == RECURSO_INICIAL);
}

/* Testar depois posicao ja ocupada
 * Testar depois maximo de predios*/
TEST_CASE("Compra_GeraRecursos", "Player"){
    Player jogador;
    SECTION(" Jogador sem dinheiro "){
        jogador.setDinheiro(0);
        REQUIRE(!jogador.compra_GeraRecurso(RECURSO::PEDREGULHO));
    }
    SECTION(" Jogador sem recurso"){
        jogador.setPedregulho(0);
        REQUIRE(!jogador.compra_GeraRecurso(RECURSO::PEDREGULHO));
    }
    SECTION("Jogador com recurso e dinheiro suficiente"){
        jogador.setPedregulho(1000);
        jogador.setDinheiro(1000);
        REQUIRE(jogador.compra_GeraRecurso(RECURSO::PEDREGULHO));
        REQUIRE(jogador.getDinheiro() == 1000 - PRECO_DINHEIRO_GERA);
        REQUIRE(jogador.getPedregulho() == 1000 - PRECO_RECURSO_GERA);
    }
}
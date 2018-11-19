//
// Created by pedro on 15/11/18.
//
#include"../include/Player.h"
#include"../include/catch.hpp"

// "Copyright [year] <Pedro>"

TEST_CASE("Construtor da classe Player", "Player") {
    Player cpu;
    REQUIRE(cpu.getCelulose() == RECURSO_INICIAL);
    REQUIRE(cpu.getPedregulho() == RECURSO_INICIAL);
    REQUIRE(cpu.getPontos()== 0);
    REQUIRE(cpu.getDinheiro() == DINHEIRO_INICIAL);
    REQUIRE(cpu.getMetal() == RECURSO_INICIAL);
}

TEST_CASE("Compra_GeraRecursos", "Player") {
    Player jogador;
    SECTION(" Jogador sem dinheiro ") {
        jogador.setDinheiro(0);
        REQUIRE(!jogador.compra_GeraRecurso(RECURSO::PEDREGULHO));
    }
    SECTION(" Jogador sem recurso") {
        jogador.setPedregulho(0);
        REQUIRE(!jogador.compra_GeraRecurso(RECURSO::PEDREGULHO));
    }
    SECTION("Jogador com recurso e dinheiro suficiente") {
        jogador.setPedregulho(1000);
        jogador.setDinheiro(1000);
        REQUIRE(jogador.compra_GeraRecurso(RECURSO::PEDREGULHO));
        REQUIRE(jogador.getDinheiro() == 1000 - PRECO_DINHEIRO_GERA);
        REQUIRE(jogador.getPedregulho() == 1000 - PRECO_RECURSO_GERA);
    }
}

TEST_CASE("Compra_Fabrica", "Player") {
    Player jogador;
    SECTION(" Jogador sem dinheiro ") {
        jogador.setDinheiro(0);
        REQUIRE(!jogador.compra_Fabrica(UNIDADE::PEDRA));
    }
    SECTION(" Jogador sem recurso") {
        jogador.setPedregulho(0);
        REQUIRE(!jogador.compra_Fabrica(UNIDADE::PEDRA));
    }
    SECTION("Jogador com recurso e dinheiro suficiente") {
        jogador.setPedregulho(1000);
        jogador.setDinheiro(1000);
        REQUIRE(jogador.compra_Fabrica(UNIDADE::PEDRA));
        REQUIRE(jogador.getDinheiro() == 1000 - PRECO_DINHEIRO_FABRICA);
        REQUIRE(jogador.getPedregulho() == 1000 - PRECO_RECURSO_FABRICA);
    }
}

TEST_CASE("Atualizar Recursos", "Player") {
    Player jogador;
    /* Player com muitos recursos */
    jogador.setPedregulho(5000);
    jogador.setDinheiro(5000);
    /* Compra 3 gerarRecursos */
    for (int i = 0; i < 3; i++) {
        jogador.compra_GeraRecurso(RECURSO::PEDREGULHO);
    }
    /* Atualizar Recursos */
    jogador.atualizar_Recursos();
    /* Pedregulho inicial - 3 * preco da geraRecurso + 3 * a taxa_coleta */
    REQUIRE(jogador.getPedregulho() ==
    5000-(3*PRECO_RECURSO_GERA)+(3*TAXA_COLETA));
}

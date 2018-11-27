// "Copyright [year] <Pedro>"
//
// Created by pedro on 15/11/18.
// Edited by Joao Pedro

#include <stdio.h>
#include"../include/Player.h"
#include"../include/catch.hpp"


#include "../include/Jogo.h"
#include "../include/Fabrica.h"


Player* cpu ;
Player* jogador;
Jogo* jogo = new Jogo();


TEST_CASE("Construtor da classe Player", "Player") {
    Player player1;
    REQUIRE(player1.getCelulose() == RECURSO_INICIAL);
    REQUIRE(player1.getPedregulho() == RECURSO_INICIAL);
    REQUIRE(player1.getPontos()== 0);
    REQUIRE(player1.getDinheiro() == DINHEIRO_INICIAL);
    REQUIRE(player1.getMetal() == RECURSO_INICIAL);
}


TEST_CASE("Compra_GeraRecursos", "Player") {
    int x = 0, y = 0;
    Player player1;
    SECTION(" player1 sem dinheiro ") {
        player1.setDinheiro(0);
        REQUIRE(!player1.compra_GeraRecurso(x, y, RECURSO::PEDREGULHO));
    }
    SECTION(" player1 sem recurso") {
        player1.setPedregulho(0);
        REQUIRE(!player1.compra_GeraRecurso(x, y, RECURSO::PEDREGULHO));
    }
    SECTION("player1 com recurso e dinheiro suficiente") {
        printf("01");
        player1.setPedregulho(1000);
        printf("01");
        player1.setDinheiro(1000);
        printf("01");
        REQUIRE(player1.compra_GeraRecurso(1, 1, RECURSO::PEDREGULHO));
        REQUIRE(player1.getDinheiro() == 1000 - PRECO_DINHEIRO_GERA);
        REQUIRE(player1.getPedregulho() == 1000 - PRECO_RECURSO_GERA);
    }
}

/*
TEST_CASE("Compra Unidades") {
    Player player1;
    Fabrica fbrc(0, 0, PEDRA);
    SECTION("player1 sem recursos") {
        int x = 4, y = 1;
        player1.setPedregulho(0);
        REQUIRE(!player1.compra_Unidade(x, y, fbrc));
    }
    SECTION("player1 com recursos") {
        int x = 3, y = 1;
        player1.setPedregulho(400);
        REQUIRE(player1.compra_Unidade(x, y, fbrc));
    }
}*/

TEST_CASE("Compra_Fabrica", "Player") {
    Player player1;
    int x = 2, y = 0;
    SECTION(" player1 sem dinheiro ") {
        player1.setDinheiro(0);
        REQUIRE(!player1.compra_Fabrica(x, y, UNIDADE::PEDRA));
    }
    SECTION(" player1 sem recurso") {
        player1.setPedregulho(0);
        REQUIRE(!player1.compra_Fabrica(x, y, UNIDADE::PEDRA));
    }
    SECTION("Coluna de tropa") {
        y = 5;
        REQUIRE(!player1.compra_Fabrica(x, y, UNIDADE::PEDRA));
    }
    SECTION("player1 com recurso e dinheiro suficiente") {
        player1.setPedregulho(1000);
        player1.setDinheiro(1000);
        REQUIRE(player1.compra_Fabrica(x, y, UNIDADE::PEDRA));
        REQUIRE(player1.getDinheiro() == 1000 - PRECO_DINHEIRO_FABRICA);
        REQUIRE(player1.getPedregulho() == 1000 - PRECO_RECURSO_FABRICA);
    }
}


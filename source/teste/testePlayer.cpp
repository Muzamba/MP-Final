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
        player1.setPedregulho(1000);
        player1.setDinheiro(1000);
        REQUIRE(player1.compra_GeraRecurso(1, 1, RECURSO::PEDREGULHO));
        REQUIRE(player1.getDinheiro() == 1000 - PRECO_DINHEIRO_GERA);
        REQUIRE(player1.getPedregulho() == 1000 - PRECO_RECURSO_GERA);
    }
}


TEST_CASE("Compra Unidades") {
    Player player1;
    delete jogo;
    jogo = new Jogo();
    SECTION("Nivel invalido") {
        int x = 3, y = 3;
        REQUIRE(!player1.compra_Unidade(x, y, UNIDADE::PEDRA, 0));
        REQUIRE(!player1.compra_Unidade(x, y, UNIDADE::PEDRA, 4));
    }
    SECTION("Nivel 1") {
        int x = 5, y = 5;
        // Sem Recurso
        player1.setPedregulho(PRECO_UNIDADE_1 - 1);
        REQUIRE(!player1.compra_Unidade(x, y, UNIDADE::PEDRA, 1));
        // Com Recurso
        player1.setPedregulho(PRECO_UNIDADE_1);
        REQUIRE(player1.compra_Unidade(x, y, UNIDADE::PEDRA, 1));
    }
}


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

/* Metodos Auxiliares */
TEST_CASE("Possui recurso unidade") {
    Player jogador;
    // Pedra Nivel 1
    jogador.setPedregulho(PRECO_UNIDADE_1);
    REQUIRE(jogador.possui_recursos_unidade(UNIDADE::PEDRA, 1));
    jogador.setPedregulho(PRECO_UNIDADE_1 - 1);
    REQUIRE(!jogador.possui_recursos_unidade(UNIDADE::PEDRA, 1));

    // Pedra Nivel 2
    jogador.setPedregulho(PRECO_UNIDADE_2);
    REQUIRE(jogador.possui_recursos_unidade(UNIDADE::PEDRA, 2));
    jogador.setPedregulho(PRECO_UNIDADE_2 - 1);
    REQUIRE(!jogador.possui_recursos_unidade(UNIDADE::PEDRA, 2));

    // Pedra Nivel 3
    jogador.setPedregulho(PRECO_UNIDADE_3);
    REQUIRE(jogador.possui_recursos_unidade(UNIDADE::PEDRA, 3));
    jogador.setPedregulho(PRECO_UNIDADE_3 - 1);
    REQUIRE(!jogador.possui_recursos_unidade(UNIDADE::PEDRA, 3));

    // Papel Nivel 1
    jogador.setCelulose(PRECO_UNIDADE_1);
    REQUIRE(jogador.possui_recursos_unidade(UNIDADE::PAPEL, 1));
    jogador.setCelulose(PRECO_UNIDADE_1 - 1);
    REQUIRE(!jogador.possui_recursos_unidade(UNIDADE::PAPEL, 1));

    // Tesoura Nivel 1
    jogador.setMetal(PRECO_UNIDADE_1);
    REQUIRE(jogador.possui_recursos_unidade(UNIDADE::TESOURA, 1));
    jogador.setMetal(PRECO_UNIDADE_1 - 1);
    REQUIRE(!jogador.possui_recursos_unidade(UNIDADE::TESOURA, 1));

}

TEST_CASE("Possui recursos geraRecurso") {
    Player jogador;

    // Teste geraRecurso Pedregulho
    jogador.setPedregulho(PRECO_RECURSO_GERA);
    jogador.setDinheiro(PRECO_DINHEIRO_GERA);
    REQUIRE(jogador.possui_recursos_geraRecurso(RECURSO::PEDREGULHO));
    // Teste sem Recurso
    jogador.setPedregulho(PRECO_RECURSO_GERA - 1);
    REQUIRE(!jogador.possui_recursos_geraRecurso(RECURSO::PEDREGULHO));
    // Teste sem Dinheiro
    jogador.setDinheiro(PRECO_DINHEIRO_GERA - 1);
    REQUIRE(!jogador.possui_recursos_geraRecurso(RECURSO::PEDREGULHO));

    // Teste geraRecurso Celulose
    jogador.setCelulose(PRECO_RECURSO_GERA);
    jogador.setDinheiro(PRECO_DINHEIRO_GERA);
    REQUIRE(jogador.possui_recursos_geraRecurso(RECURSO::CELULOSE));
    // Teste sem Recurso
    jogador.setCelulose(PRECO_RECURSO_GERA - 1);
    REQUIRE(!jogador.possui_recursos_geraRecurso(RECURSO::CELULOSE));
    // Teste sem Dinheiro
    jogador.setDinheiro(PRECO_DINHEIRO_GERA - 1);
    REQUIRE(!jogador.possui_recursos_geraRecurso(RECURSO::CELULOSE));

    // Teste geraRecurso Metal
    jogador.setMetal(PRECO_RECURSO_GERA);
    jogador.setDinheiro(PRECO_DINHEIRO_GERA);
    REQUIRE(jogador.possui_recursos_geraRecurso(RECURSO::METAL));
    // Teste sem Recurso
    jogador.setMetal(PRECO_RECURSO_GERA - 1);
    REQUIRE(!jogador.possui_recursos_geraRecurso(RECURSO::METAL));
    // Teste sem Dinheiro
    jogador.setDinheiro(PRECO_DINHEIRO_GERA - 1);
    REQUIRE(!jogador.possui_recursos_geraRecurso(RECURSO::METAL));
}

TEST_CASE("Possui recursos fabrica") {
    Player jogador;

    // Teste Fabrica de Pedra
    jogador.setPedregulho(PRECO_RECURSO_FABRICA);
    jogador.setDinheiro(PRECO_DINHEIRO_FABRICA);
    REQUIRE(jogador.possui_recursos_fabrica(UNIDADE::PEDRA));
    // Teste sem Recurso
    jogador.setPedregulho(PRECO_RECURSO_FABRICA - 1);
    REQUIRE(!jogador.possui_recursos_fabrica(UNIDADE::PEDRA));
    // Teste sem Dinheiro
    jogador.setDinheiro(PRECO_DINHEIRO_FABRICA - 1);
    REQUIRE(!jogador.possui_recursos_fabrica(UNIDADE::PEDRA));

    // Teste Fabrica de Papel
    jogador.setCelulose(PRECO_RECURSO_FABRICA);
    jogador.setDinheiro(PRECO_DINHEIRO_FABRICA);
    REQUIRE(jogador.possui_recursos_fabrica(UNIDADE::PAPEL));
    // Teste sem Recurso
    jogador.setCelulose(PRECO_RECURSO_FABRICA - 1);
    REQUIRE(!jogador.possui_recursos_fabrica(UNIDADE::PAPEL));
    // Teste sem Dinheiro
    jogador.setDinheiro(PRECO_DINHEIRO_FABRICA - 1);
    REQUIRE(!jogador.possui_recursos_fabrica(UNIDADE::PAPEL));

    // Teste Fabrica de Tesoura
    jogador.setMetal(PRECO_RECURSO_FABRICA);
    jogador.setDinheiro(PRECO_DINHEIRO_FABRICA);
    REQUIRE(jogador.possui_recursos_fabrica(UNIDADE::TESOURA));
    // Teste sem Recurso
    jogador.setMetal(PRECO_RECURSO_FABRICA - 1);
    REQUIRE(!jogador.possui_recursos_fabrica(UNIDADE::TESOURA));
    // Teste sem Dinheiro
    jogador.setDinheiro(PRECO_DINHEIRO_FABRICA - 1);
    REQUIRE(!jogador.possui_recursos_fabrica(UNIDADE::TESOURA));
}

/* Teste Funções auxilares para compra */
TEST_CASE("Retorna textura recurso") {
    REQUIRE(retorna_textura_recurso(RECURSO::METAL) == TEXTURAS::GERAR_TESOURA);
    REQUIRE(retorna_textura_recurso(RECURSO::PEDREGULHO) == TEXTURAS::GERAR_PEDRA);
    REQUIRE(retorna_textura_recurso(RECURSO::CELULOSE) == TEXTURAS::GERAR_PAPEL);
}

TEST_CASE("Retorna textura fabrica") {
    REQUIRE(retorna_textura_fabrica(UNIDADE::TESOURA) == TEXTURAS::FABRICA_TESOURA);
    REQUIRE(retorna_textura_fabrica(UNIDADE::PEDRA) == TEXTURAS::FABRICA_PEDRA);
    REQUIRE(retorna_textura_fabrica(UNIDADE::PEDRA) == TEXTURAS::FABRICA_PEDRA);
}

TEST_CASE("Retorna textura unidade") {
    // Nivel 1
    REQUIRE(retorna_textura_unidade(1, UNIDADE::PEDRA) == TEXTURAS::TROPA_PEDRA);
    REQUIRE(retorna_textura_unidade(1, UNIDADE::PAPEL) == TEXTURAS::TROPA_PAPEL);
    REQUIRE(retorna_textura_unidade(1, UNIDADE::TESOURA) == TEXTURAS::TROPA_TESOURA);
    // Nivel 2
    REQUIRE(retorna_textura_unidade(2, UNIDADE::PEDRA) == TEXTURAS::TROPA_PEDRA);
    REQUIRE(retorna_textura_unidade(2, UNIDADE::PAPEL) == TEXTURAS::TROPA_PAPEL);
    REQUIRE(retorna_textura_unidade(2, UNIDADE::TESOURA) == TEXTURAS::TROPA_TESOURA);
    // Nivel 3
    REQUIRE(retorna_textura_unidade(3, UNIDADE::PEDRA) == TEXTURAS::TROPA_PEDRA2);
    REQUIRE(retorna_textura_unidade(3, UNIDADE::PAPEL) == TEXTURAS::TROPA_PAPEL2);
    REQUIRE(retorna_textura_unidade(3, UNIDADE::TESOURA) == TEXTURAS::TROPA_TESOURA2);
}
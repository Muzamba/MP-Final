//
// Created by pedro on 29/11/18.
//

#include "../include/catch.hpp"
#include "../include/Jogo.h"

TEST_CASE("Anda") {
    Unidade* atual = new Unidade(0, 0, UNIDADE::TESOURA, 300, 1, 2);
    Unidade* destino = NULL;
    printf("%d\n", destino);
    printf("%d", atual);
    anda(&atual, &destino);
    CHECK(atual == NULL);
    REQUIRE(destino->getVelocidade() == 1);
    REQUIRE(destino->get_x() == 0);
    REQUIRE(destino->get_y() == 0);
    REQUIRE(destino->getDano() == 2);
    REQUIRE(destino->getVida() == 300);
    REQUIRE(destino->getTipo() == UNIDADE::TESOURA);
}


TEST_CASE("Combate Unidade") {
    //X, Y, tipo, vida, velocidade, dano
    Unidade* unidade1 = new Unidade(2, 20, UNIDADE::PAPEL, 230, 1, 230);
    Unidade* unidade2 = new Unidade(1, 20, UNIDADE::PAPEL, 231, -1, 230);
    SECTION("Combate Unidade1 morre") {
        combate_unidade(&unidade1, &unidade2);
        CHECK(unidade1 == NULL);
        REQUIRE(unidade2->getVida() == 1);
    }
    SECTION("Combate Unidade2 morre") {
        unidade2->setTipo(UNIDADE::PEDRA);
        combate_unidade(&unidade1, &unidade2);
        REQUIRE(unidade1->getVida() == 0);
        REQUIRE(unidade2 == NULL);
    }
    SECTION("Ambos morrem") {
        unidade2->setTipo(UNIDADE::PAPEL);
        unidade2->setDano(230);
        unidade2->setVida(230);
        combate_unidade(&unidade1, &unidade2);
        REQUIRE(unidade1 == NULL);
        REQUIRE(unidade2 == NULL);
    }
}


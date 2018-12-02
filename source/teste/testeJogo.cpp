//
// Copyright [2018] <Waliff Cordeiro>"
//

#include "../include/catch.hpp"
#include "../include/Jogo.h"

TEST_CASE("Anda") {
    Unidade* atual = new Unidade(0, 0, UNIDADE::TESOURA, 300, 1, 2);
    Unidade* destino = NULL;
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
    // X, Y, tipo, vida, velocidade, dano
    Unidade* unidade1 = new Unidade(2, 20, UNIDADE::PAPEL, 200, 1, 100);
    Unidade* unidade2 = new Unidade(1, 20, UNIDADE::PEDRA, 200, -1, 100);

    SECTION("Combate Unidade2 morre") {
        combate_unidade(&unidade1, &unidade2);
        REQUIRE(combate_unidade(&unidade1, &unidade2) == 2);
        REQUIRE(unidade1->getVida() >= 0);
        REQUIRE(unidade2->getVida() <= 0);
}
SECTION("Combate Unidade2 morre") {
        unidade2->setTipo(UNIDADE::PEDRA);
        combate_unidade(&unidade1, &unidade2);
        REQUIRE(combate_unidade(&unidade1, &unidade2) == 2);
        REQUIRE(unidade1->getVida() == 100);
        REQUIRE(unidade2->getVida() == 0);
    }
    SECTION("Ambos morrem") {
        unidade2->setTipo(UNIDADE::PAPEL);
        REQUIRE(combate_unidade(&unidade1, &unidade2) == 3);
        REQUIRE(unidade1->getVida() <= 0);
        REQUIRE(unidade2->getVida() <= 0);
    }
    SECTION("Dobro de dano") {
        unidade2->setTipo(UNIDADE::TESOURA);
        unidade2->setDano(200);
        unidade2->setVida(1000);
        REQUIRE(combate_unidade(&unidade1, &unidade2) == 1);
        REQUIRE(unidade1->getVida() == -200);
        REQUIRE(unidade2->getVida() == 900);
    }
}
TEST_CASE("Ataca Geradora") {
    Unidade* unidade = new Unidade(2, 20, UNIDADE::PAPEL, 200, 1, 20);
    GeraRecursos* geradora = new GeraRecursos(3, 20, UNIDADE::PAPEL);
    SECTION("Geradora não morre") {
        geradora->set_vida(21);
        printf("\ndano unidade: %d\n", unidade->getDano());
        printf("\nvida geradora: %d\n", geradora->get_vida());
        REQUIRE(ataca_geraRecurso(&unidade, &geradora) == 0);
        printf("\ndano unidade: %d\n", unidade->getDano());
        printf("\nvida geradora: %d\n", geradora->get_vida());
        REQUIRE(geradora->get_vida() == 1);
    }
    SECTION("Geradora morre") {
        geradora->set_vida(19);
        REQUIRE(ataca_geraRecurso(&unidade, &geradora) == 1);
        REQUIRE(geradora->get_vida() == -1);
    }
    SECTION("Tropa counter") {
        unidade->setTipo(UNIDADE::TESOURA);
        geradora->set_vida(40);
        REQUIRE(ataca_geraRecurso(&unidade, &geradora) == 1);
        REQUIRE(geradora->get_vida() == 0);
    }
}

TEST_CASE("Ataca Fabrica") {
    Unidade* unidade = new Unidade(2, 20, UNIDADE::PAPEL, 200, 1, 5);
    Fabrica* fbrc = new Fabrica(3, 20, UNIDADE::PEDRA);
    SECTION("Fabrica não morre") {
    fbrc->set_vida(11);
    REQUIRE(ataca_fabrica(&unidade, &fbrc) == 0);
    REQUIRE(fbrc->get_vida() == 1);
    }
    SECTION("Fabrica morre - counter") {
    fbrc->set_vida(1);
    REQUIRE(ataca_fabrica(&unidade, &fbrc) == 1);
    REQUIRE(fbrc->get_vida() == -9);
    }
    unidade->setTipo(UNIDADE::PEDRA);
    SECTION("Batalhas de mesmo tipo - Fabrica morre") {
        fbrc->set_vida(4);
        REQUIRE(ataca_fabrica(&unidade, &fbrc) == 1);
        REQUIRE(fbrc->get_vida() == -1);
        fbrc->set_vida(5);
        REQUIRE(ataca_fabrica(&unidade, &fbrc) == 1);
        REQUIRE(fbrc->get_vida() == 0);
    }
    SECTION("Batalhas de mesmo tipo - Fabrica não morre") {
        fbrc->set_vida(10);
        REQUIRE(ataca_fabrica(&unidade, &fbrc) == 0);
        REQUIRE(fbrc->get_vida() == 5);
        fbrc->set_vida(100);
        REQUIRE(ataca_fabrica(&unidade, &fbrc) == 0);
        REQUIRE(fbrc->get_vida() == 95);
    }
}

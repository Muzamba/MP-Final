// Copyright 2018 João Pedro Assis
#define CATCH_CONFIG_MAIN
#include "Fabrica.h"
#include "catch.hpp"

TEST_CASE("Compile") {
    SECTION("Compile") {
        REQUIRE(1 == 1);
    }
}

TEST_CASE("Class Fabrica") {
    SECTION("Check inheritance") {
        Fabrica fbrc(30, 40, PEDRA);
        int x, y;
        x = fbrc.get_x();
        y = fbrc.get_y();

        fbrc.set_vida(100);

        REQUIRE(x == 30);
        REQUIRE(y == 40);
        REQUIRE(fbrc.get_vida() == 100);

        fbrc.set_x(50);
        fbrc.set_y(60);

        x = fbrc.get_x();
        y = fbrc.get_y();

        REQUIRE(x == 50);
        REQUIRE(y == 60);
        REQUIRE(fbrc.get_vida() == 100);
    }
    SECTION("Get/Set") {
        Fabrica fbrc(30, 40, PEDRA);
        fbrc.set_nivel(10);
        fbrc.set_tempoEspera(25);

        int nivel, tempoEspera;
        nivel = fbrc.get_nivel();
        tempoEspera = fbrc.get_tempoEspera();

        REQUIRE(nivel == 10);
        REQUIRE(tempoEspera == 25);
    }
}

TEST_CASE("Methods") {
    SECTION("Get attributes") {
        Fabrica fbrc(30, 40, TESOURA);
    }
}


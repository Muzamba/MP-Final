// Copyright 2018 João Pedro Assis
#include "../../include/Predio.h"
#include "../../include/Objeto.h"
#include "../../lib/catch.hpp"

TEST_CASE("Compile") {
    SECTION("Compile") {
        REQUIRE(1 == 1);
    }
}

TEST_CASE("Class Predio") {
    SECTION("Check inheritance") {
        // test case que verifica se a herança foi feita
        // corretamente
        Predio prd(30, 40);
        int x, y;
        char* img;
        x = prd.get_x();
        y = prd.get_y();

        REQUIRE(x == 30);
        REQUIRE(y == 40);
    }
    SECTION("Set/Get life") {
        Predio prd(30, 40);
        prd.set_vida(100);
        int life = prd.get_vida();
        REQUIRE(life == 100);
    }
}

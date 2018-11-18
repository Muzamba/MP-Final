// Copyright 2018 João Pedro Assis
#define CATCH_CONFIG_MAIN
#include "../../include/Objeto.h"
#include "../../lib/catch.hpp"

TEST_CASE("Compile") {
    SECTION("Compile") {
        REQUIRE(1 == 1);
    }
}

TEST_CASE("Object") {
    SECTION("INIT X Y") {
        Objeto obj(30, 40);
        int x, y;
        char* img;

        x = obj.get_x();
        y = obj.get_y();

        REQUIRE(x == 30);
        REQUIRE(y == 40);
    }

    SECTION("SET/GET") {
        Objeto obj(30, 40);
        obj.set_x(50);
        obj.set_y(60);
        int x, y;
        x = obj.get_x();
        y = obj.get_y();

        REQUIRE(x == 50);
        REQUIRE(y == 60);
    }
}

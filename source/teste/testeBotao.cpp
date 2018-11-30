//
// Created by pedro on 29/11/18.
//

#include "../include/catch.hpp"
#include "../include/Botao.h"

TEST_CASE("in_range_mapa") {
    /* Os 2 fora do range*/
    REQUIRE(!in_range_mapa(22, 22));
    /* O x fora do range */
    REQUIRE(!in_range_mapa(10, 6));
    /* O y fora do range*/
    REQUIRE(!in_range_mapa(3, 12));
    /* os dois dentro do range */
    REQUIRE(in_range_mapa(0, 0));
}

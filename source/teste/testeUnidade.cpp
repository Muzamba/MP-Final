#include <vector>
#include"../include/catch.hpp"
#include "../include/Unidade.h"
// "Copyright [2018] <Waliff Cordeiro>"

TEST_CASE("Unidades") {
    /*SECTION("Fazer o personagem se movimentar") {
        // (x, y, tipo, vida, velocidade, dano)
        Unidade uniteste(2, 20, 1, 231, 2, 312);
        uniteste.anda();
        REQUIRE(uniteste.get_x() == 4);
    }*/
    /*SECTION("Destruindo unidade") {
        std::vector<Unidade> unidades;

        // (x, y, tipo, vida, velocidade, dano)
        Unidade uniteste1(2, 20, 1, 231, 2, 312);
        Unidade uniteste2(7, 5, 2, 232, 3, 313);
        Unidade uniteste3(9, 3, 3, 233, 4, 314);

        // Atribuindo 3 unidades
        unidades.push_back(uniteste1);
        unidades.push_back(uniteste2);
        unidades.push_back(uniteste3);

        // Verificando lista de unidades
        REQUIRE(unidades.size() == 3);
        uniteste2.destroy(&unidades);

        // Verificando lista de unidades após remoção
        REQUIRE(unidades.size() == 2);
        REQUIRE(unidades[2].get_x() != 7);
        REQUIRE(unidades[2].get_y() != 5);
    }
}*/

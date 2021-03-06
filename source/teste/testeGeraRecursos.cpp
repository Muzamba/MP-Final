//
// Created by pedro on 15/11/18.
//
#include"../include/Head.h"
#include"../include/GeraRecursos.h"
#include"../include/catch.hpp"

// "Copyright [year] <Pedro>"
/** Teste Construtor
 *  -----------------
 *  Testa se as variaveis são incializadas da seguinte forma:
 *  nivel = 0
 *  tipo = RECURSO[tipo]
 *  taxa = TAXA_COLETA
 */
TEST_CASE("Construtor da Classe") {
    GeraRecursos geradora(0, 0, RECURSO::PEDREGULHO);
    REQUIRE(geradora.getNivel() == 0);
    REQUIRE(geradora.getTaxa() == TAXA_COLETA);
    REQUIRE(geradora.getTipo() == RECURSO::PEDREGULHO);
    REQUIRE(geradora.get_x() == 0);
    REQUIRE(geradora.get_y() == 0);
}


TEST_CASE("Produzir Recurso ") {
    GeraRecursos geradora(0, 0, RECURSO::PEDREGULHO);
    int qte_recurso = geradora.produzirRecurso();
    REQUIRE(qte_recurso == geradora.getTaxa());
}

TEST_CASE("Testando Enum") {
    REQUIRE(RECURSO::CELULOSE == 0);
    REQUIRE(RECURSO::PEDREGULHO == 1);
    REQUIRE(RECURSO::METAL == 2);
}

TEST_CASE("Upgrade geraRecurso") {
    GeraRecursos geradora(0, 0, RECURSO::PEDREGULHO);
    int *dinheiro = (int*) malloc(sizeof(int));
    *dinheiro = 10000;
    int taxa = geradora.getTaxa();
    int nivel = geradora.getNivel();
    geradora.upgrade(dinheiro);
    REQUIRE(*dinheiro == 10000 - PRECO_UPGRADE_GERA);
    REQUIRE(geradora.getTaxa() == 2 * taxa);
    REQUIRE(geradora.getNivel() == nivel + 1);
}
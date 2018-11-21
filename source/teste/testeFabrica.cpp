// Copyright 2018 João Pedro Assis
#include "../../include/Fabrica.h"
#include "../include/catch.hpp"
#include "../../include/Head.h"
#include "../../include/Player.h"

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

        fbrc.set_vida(VIDA_INICIAL_FABRICA);

        REQUIRE(x == 30);
        REQUIRE(y == 40);
        REQUIRE(fbrc.get_vida() == VIDA_INICIAL_FABRICA);

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
    SECTION("New Constructors") {
        Fabrica fbrc(30, 40, PEDRA);
        SECTION("Fabrica variables") {
            REQUIRE(fbrc.tipo == PEDRA);
            REQUIRE(fbrc.tempoEspera == TEMPO_ESPERA_INICIAL_FABRICA);
            REQUIRE(fbrc.nivel == 1);
            REQUIRE(fbrc.get_vida() == VIDA_INICIAL_FABRICA);
        }
        SECTION("Unidade variables") {
            REQUIRE(fbrc.vida == fbrc.nivel*10);
            REQUIRE(fbrc.dano == fbrc.nivel*5);
            REQUIRE(fbrc.velocidade == fbrc.nivel*2);
        }
    }
}

TEST_CASE("Verify upgrade") {
        Fabrica fbrc(30, 40, TESOURA);
        Player player;
    SECTION("Can Upgrade") {
        REQUIRE(fbrc.can_upgrade(fbrc.custo_upgrade, player.getDinheiro())
        == true);
        player.setDinheiro(100);
        REQUIRE(fbrc.can_upgrade(fbrc.custo_upgrade, player.getDinheiro())
        == false);
    }
}

TEST_CASE("Upgrade") {
    Fabrica fbrc(30, 40, PEDRA);
    Player player;
    SECTION("with enough money") {
        if (fbrc.can_upgrade(fbrc.custo_upgrade, player.getDinheiro())) {
            fbrc.upgrade(&player.dinheiro);
            REQUIRE(fbrc.nivel == 2);
        } else {
            REQUIRE(fbrc.nivel == 1);
        }
    }
    SECTION("Not enough Money") {
        player.setDinheiro(7);
        if (fbrc.can_upgrade(fbrc.custo_upgrade, player.getDinheiro())) {
            fbrc.upgrade(&player.dinheiro);
            REQUIRE(fbrc.nivel == 2);
        } else {
            REQUIRE(fbrc.nivel == 1);
        }
    }
    SECTION("New attributes") {
        if (fbrc.can_upgrade(fbrc.custo_upgrade, player.getDinheiro())) {
            fbrc.upgrade(&player.dinheiro);
            REQUIRE(fbrc.nivel == 2);
            SECTION("Life/Unidades attributes") {
                REQUIRE(fbrc.vida == fbrc.nivel*10);
                REQUIRE(fbrc.dano == fbrc.nivel*5);
                REQUIRE(fbrc.velocidade == fbrc.nivel*2);
                REQUIRE(fbrc.get_vida() == fbrc.nivel*VIDA_INICIAL_FABRICA);
            }
        } else {
            REQUIRE(fbrc.nivel == 1);
        }
    }
    SECTION("Donti ravi mônei") {
        player.setDinheiro(player.getDinheiro() + 800);
        for (int i = 0; i < 10; i++) {
            int nivel_atual = fbrc.nivel;
            int novo_nivel = fbrc.nivel+1;
            int dinheiro_atual = player.dinheiro;
            int novo_dinheiro = player.dinheiro - fbrc.custo_upgrade;
            if (fbrc.can_upgrade(fbrc.custo_upgrade, player.getDinheiro())) {
                fbrc.upgrade(&player.dinheiro);
                REQUIRE(fbrc.nivel == novo_nivel);
                REQUIRE(player.getDinheiro() == novo_dinheiro);
            } else {
                REQUIRE(fbrc.nivel == nivel_atual);
                REQUIRE(player.getDinheiro() == dinheiro_atual);
            }

        }
    }
}


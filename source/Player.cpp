#include "../include/Player.h"
#include <stdio.h>

/* "Copyright [2018] <Pedro>" */

extern Jogo* jogo;
/**Construtor da classe Player
 * -------------------------
 * Seta todos os atributos para os valores inciais, e os pontos para 0
 */
Player::Player() {
    pedregulho = RECURSO_INICIAL;
    celulose = RECURSO_INICIAL;
    metal = RECURSO_INICIAL;
    pontos = 0;
    dinheiro = DINHEIRO_INICIAL;
    vida = VIDA_INCIAL_PLAYER;
}

/** coompra_GeraRecurso
 *  @brief A função antes de comprar verifica se o espaço selecionado esta ocupado, ou é possivel,
 *  se atinge o limite maximo de construcoes, caso as condicoes acima sao verificadas, a funcao
 *  constroi uma geraRecurso do tipo de recursos, adiciona na lista geraRecursos e substrai o dinheiro
 *  gasto
 *
 * @param recurso : tipo de recursos que se deseja comprar
 * @return true : se for possivel comprar
 *         false : se nao for possivel comprar
 */
bool Player::compra_GeraRecurso(int x, int y, RECURSO tipo) {
    /* Verifica se o jogador tem recursos suficientes */
    if (possui_recursos_geraRecurso(tipo)) {
        /*  Verifica se a matriz de posicao esta vazia */
        if (verifica_espaco_ocupado(x, y) && verifica_espaco_predio(x, y)) {
            /* Retira o dinheiro da compra */
            Player::retira_recurso_geraRecurso(tipo);
            /* Adiciona a fabrica na lista da classe Player*/
            jogo->matriz_geraRecurso[x][y] = new GeraRecursos(x, y, tipo);
            TEXTURAS text = retorna_textura_recurso(tipo);
            jogo->matriz_geraRecurso[x][y]->mudaTextura(jogo->texturas[text]);
            jogo->matriz_geraRecurso[x][y]->setDestRect
            ((y + 2) * 80 , (x + 2) * 72, 64, 64);
            jogo->matriz_geraRecurso[x][y]->setSrcRect(0, 0, 64, 64);
        } else {
            return false;
        }
        return true;
    } else {
        return false;
    }
}

TEXTURAS retorna_textura_recurso(int tipo) {
    switch (tipo) {
        case RECURSO::CELULOSE:
            return TEXTURAS::GERAR_PAPEL;
        case RECURSO::PEDREGULHO:
            return TEXTURAS::GERAR_PEDRA;
        case RECURSO::METAL:
            return TEXTURAS::GERAR_TESOURA;
        default:
            return TEXTURAS::BOTAO_INICIAR;
    }
}

bool Player::compra_Fabrica(int x, int y, UNIDADE tipo) {
    if (possui_recursos_fabrica(tipo)) {
        /* Retira o dinheiro da compra */
        /*  Verifica se a matriz de posicao esta vazia */
        if (verifica_espaco_ocupado(x, y) && verifica_espaco_predio(x, y)) {
            /* Retira o dinheiro da compra */
            Player::retira_recurso_fabrica(tipo);
            /* Adiciona a fabrica na lista da classe Player*/
            jogo->matriz_fabrica[x][y] = new Fabrica(x, y, tipo);
            TEXTURAS text = retorna_textura_fabrica(tipo);
            jogo->matriz_fabrica[x][y]->mudaTextura(jogo->texturas[text]);
            jogo->matriz_fabrica[x][y]->setDestRect
            ((y + 2) * 80 , (x + 2) * 72, 64, 64);
            jogo->matriz_fabrica[x][y]->setSrcRect(0, 0, 64, 64);
            return true;
        } else { /* Se a posicao e invalida */
            return false;
        }
    } else { /* Se o jogador nao tiver recursos suficientes */
        return false;
    }
}


TEXTURAS retorna_textura_fabrica(int tipo) {
    switch (tipo) {
        case RECURSO::CELULOSE:
            return TEXTURAS::FABRICA_PAPEL;
        case RECURSO::PEDREGULHO:
            return TEXTURAS::FABRICA_PEDRA;
        case RECURSO::METAL:
            return TEXTURAS::FABRICA_TESOURA;
        default:
            return TEXTURAS::BOTAO_INICIAR;
    }
}

bool Player::possui_recursos_unidade(int tipo, int nivel) {
    int custo = 0;
    int recurso = 0;
    switch (nivel) {
        case 1:
            custo = PRECO_UNIDADE_1;
            break;
        case 2:
            custo = PRECO_UNIDADE_2;
            break;
        case 3:
            custo = PRECO_UNIDADE_3;
            break;
        default:
            printf("ERRO : Nivel Invalido %d: compra unidade\n", nivel);
            return false;
    }

    switch (tipo) {
        case RECURSO::CELULOSE :
            recurso = Player::getCelulose();
            break;
        case RECURSO::PEDREGULHO :
            recurso = Player::getPedregulho();
            break;
        case RECURSO::METAL :
            recurso = Player::getMetal();
            break;
        default:
            printf("ERRO : Recurso Invalido : compra_unidade \n");
            return false;
    }
    return recurso >= custo;
}

void Player::retira_recurso_unidade(UNIDADE tipo, int nivel) {
    int custo = 0;
    switch (nivel) {
        case 1:
            custo = PRECO_UNIDADE_1;
            break;
        case 2:
            custo = PRECO_UNIDADE_3;
            break;
        case 3:
            custo = PRECO_UNIDADE_3;
            break;
        default:
            custo = 32000;
            printf("ERRO : Nivel Invalido : compra unidade");
    }
    /* Retira recurso */
    switch (tipo) {
        case RECURSO::CELULOSE:
            Player::celulose -= custo;
            break;
        case RECURSO::PEDREGULHO:
            Player::pedregulho -= custo;
            break;
        case RECURSO:: METAL:
            Player::metal -= custo;
            break;
        default:
            printf("ERRO : Recurso Invalido : compra_unidade \n");
    }
}

bool verifica_espaco_unidade(int x, int y) {
    return y >= 2 && y <= 9;
}

TEXTURAS retorna_textura_unidade(int nivel, int tipo) {
    if (nivel == 1 || nivel == 2) {
        switch (tipo) {
            case UNIDADE::PEDRA:
                return TEXTURAS::TROPA_PEDRA;
            case UNIDADE ::PAPEL:
                return TEXTURAS ::TROPA_PAPEL;
            case UNIDADE ::TESOURA:
                return TEXTURAS ::TROPA_TESOURA;
        }
    } else {
        switch (tipo) {
            case UNIDADE::PEDRA:
                return TEXTURAS::TROPA_PEDRA2;
            case UNIDADE ::PAPEL:
                return TEXTURAS ::TROPA_PAPEL2;
            case UNIDADE ::TESOURA:
                return TEXTURAS ::TROPA_TESOURA2;
        }
    }
}

bool Player::compra_Unidade(int x, int y, UNIDADE tipo, int nivel) {
    if (possui_recursos_unidade(tipo, nivel)) {
        if (verifica_espaco_ocupado(x, y) && verifica_espaco_unidade(x, y)) {
            retira_recurso_unidade(tipo, nivel);
            switch (nivel) {
                case 1:
                    jogo->matriz_unidade[x][y] =
                            new Unidade(x, y, tipo, VIDA_UNIDADE_1,
                                    VELO_UNIDADE_1, DANO_UNIDADE_1, 1);
                    jogo->matriz_unidade[x][y]->mudaTextura
                    (jogo->texturas[retorna_textura_unidade(1, tipo)]);
                    break;
                case 2:
                    jogo->matriz_unidade[x][y] =
                            new Unidade(x, y, tipo, VIDA_UNIDADE_2,
                                    VELO_UNIDADE_2, DANO_UNIDADE_2, 2);
                    jogo->matriz_unidade[x][y]->mudaTextura
                    (jogo->texturas[retorna_textura_unidade(2, tipo)]);
                    break;
                case 3:
                    jogo->matriz_unidade[x][y] =
                            new Unidade(x, y, tipo, VIDA_UNIDADE_3,
                                    VELO_UNIDADE_3, DANO_UNIDADE_3, 3);
                    jogo->matriz_unidade[x][y]->mudaTextura
                    (jogo->texturas[retorna_textura_unidade(3, tipo)]);
                    break;
                default:
                    printf("NIVEL INVALIDO :: COMPRA UNIDADE\n");
                    break;
            }
            jogo->matriz_unidade[x][y]->setDestRect
            ((y + 2) * 80 , (x + 2) * 72, 64, 64);
            jogo->matriz_unidade[x][y]->setSrcRect(0, 0, 64, 64);
            return true;
        }
    }
    return false;
}

/*bool Player::compra_Unidade(int x, int y, Fabrica fabrica) {
    printf("Entrou na funcao \n");
    if (possui_recursos_unidade(fabrica.tipo, fabrica.custo_unidade)) {
        printf("Possui Recursos\n");
        // Retira o dinheiro da compra
        //  Verifica se a matriz de posicao esta vazia
        if (verifica_espaco_ocupado(x, y)) {
            printf("Espaço livre\n");
            // Retira o dinheiro da compra
            Player::retira_recurso_unidade(fabrica.tipo, fabrica);
            printf("Retirou recurso\n");
            // Adiciona a fabrica na matriz unidade
            //jogo->matriz_unidade[x][y] = fabrica.geraUnidade(1, 2);
            //jogo->matriz_unidade[x][y] = new Unidade(x, y, fabrica.getTipo(), fabrica.vida, fabrica.velocidade, fabrica.dano);
            TEXTURAS text = retorna_textura_unidade(fabrica.getTipo());
            jogo->matriz_fabrica[x][y]->mudaTextura(jogo->texturas[text]);
            jogo->matriz_fabrica[x][y]->setDestRect((y + 2) * 80 ,(x + 2) * 72, 64, 64);
            jogo->matriz_fabrica[x][y]->setSrcRect(0, 0, 64, 64);
            printf("Alocou memoria\n");
            return true;
        } else { // Se a posicao e invalida
            return false;
        }
    } else { // Se o jogador nao tiver recursos suficientes
        return false;
    }
}*/

/** Função atualizar_Recursos
 * @brief A função percorre a lista de geraRecursos e soma os recursos gerados nos atributos do player
 * */
void Player::atualizar_Recursos() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (jogo->matriz_geraRecurso[i][j] != NULL) {
                switch (jogo->matriz_geraRecurso[i][j]->getTipo()) {
                    case RECURSO::PEDREGULHO:
                        Player::pedregulho +=
                                jogo->matriz_geraRecurso[i][j]->getTaxa();
                        break;
                    case RECURSO::METAL:
                        Player::metal +=
                                jogo->matriz_geraRecurso[i][j]->getTaxa();
                        break;
                    case RECURSO::CELULOSE:
                        Player::celulose +=
                                jogo->matriz_geraRecurso[i][j]->getTaxa();
                        break;
                    default:
                        printf("ERRO: atualizar_Recursos\n");
                        return;
                }
            }
        }
    }
}

/* get e setters*/
int Player::getPedregulho() const {
    return pedregulho;
}

void Player::setPedregulho(int pedregulho) {
    Player::pedregulho = pedregulho;
}

int Player::getCelulose() const {
    return celulose;
}

void Player::setCelulose(int celulose) {
    Player::celulose = celulose;
}

int Player::getMetal() const {
    return metal;
}

void Player::setMetal(int metal) {
    Player::metal = metal;
}

int Player::getDinheiro() const {
    return dinheiro;
}

void Player::setDinheiro(int dinheiro) {
    Player::dinheiro = dinheiro;
}

int Player::getPontos() const {
    return pontos;
}

void Player::setPontos(int pontos) {
    Player::pontos = pontos;
}

Player::~Player() {}

/* Metodos auxiliares */
bool Player::possui_recursos_fabrica(UNIDADE tipo) {
    int recurso = 0;
    switch (tipo) {
        case UNIDADE::PAPEL:
            recurso = Player::getCelulose();
            break;
        case UNIDADE ::PEDRA:
            recurso = Player::getPedregulho();
            break;
        case UNIDADE ::TESOURA:
            recurso = Player::getMetal();
            break;
        default:
            printf("ERRO : Recurso Invalido : compra_fabrica \n");
            return false;
    }

    if ( recurso >= PRECO_RECURSO_FABRICA ) {
        if ( Player::dinheiro >= PRECO_DINHEIRO_FABRICA ) {
            return true;
        } else {
            /* Mensagem de não ter dinheiro */
            return false;
        }
    } else {
        /* Mensagem de não ter recurso */
        return false;
    }
}

void Player::retira_recurso_fabrica(UNIDADE tipo) {
    /* Retira recurso */
    switch (tipo) {
        case UNIDADE::PAPEL:
            Player::celulose -= PRECO_RECURSO_FABRICA;
            break;
        case UNIDADE ::PEDRA:
            Player::pedregulho -= PRECO_RECURSO_FABRICA;
            break;
        case UNIDADE ::TESOURA:
            Player::metal -= PRECO_RECURSO_FABRICA;
            break;
        default:
            printf("ERRO : Recurso Invalido : compra_fabrica \n");
    }
    /* retira dinheiro*/
    Player::dinheiro -= PRECO_DINHEIRO_FABRICA;
}

bool Player::possui_recursos_geraRecurso(RECURSO tipo) {
    int recurso = 0;
    switch (tipo) {
        case RECURSO::CELULOSE :
            recurso = Player::getCelulose();
            break;
        case RECURSO::PEDREGULHO :
            recurso = Player::getPedregulho();
            break;
        case RECURSO::METAL :
            recurso = Player::getMetal();
            break;
        default:
            printf("ERRO : Recurso Invalido : compra_fabrica \n");
            return false;
    }

    if ( recurso >= PRECO_RECURSO_GERA ) {
        if ( Player::dinheiro >= PRECO_DINHEIRO_GERA ) {
            return true;
        } else {
            /* Mensagem de não ter dinheiro */
            return false;
        }
    } else {
        /* Mensagem de não ter recurso */
        return false;
    }
}

void Player::retira_recurso_geraRecurso(RECURSO tipo) {
    /* Retira recurso */
    switch (tipo) {
        case RECURSO ::CELULOSE:
            Player::celulose -= PRECO_RECURSO_GERA;
            break;
        case RECURSO ::PEDREGULHO:
            Player::pedregulho -= PRECO_RECURSO_GERA;
            break;
        case RECURSO :: METAL:
            Player::metal -= PRECO_RECURSO_GERA;
            break;
        default:
            printf("ERRO : Recurso Invalido : compra_fabrica \n");
    }
    /* retira dinheiro*/
    Player::dinheiro -= PRECO_DINHEIRO_GERA;
}

bool Player::verifica_espaco_predio(int x, int y) {
    return y < 2;
}

bool Player::verifica_espaco_ocupado(int x, int y) {
    if (x >= 0 && y >=0 && x < 6 && y < 12) {
        return jogo->matriz_fabrica[x][y] == NULL &&
               jogo->matriz_geraRecurso[x][y] == NULL &&
               jogo->matriz_unidade[x][y] == NULL;
    }
    return false;
}

int Player::getVida() const {
    return vida;
}

void Player::setVida(int vida) {
    Player::vida = vida;
}

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
            jogo->matriz_geraRecurso[x][y]->mudaTextura(jogo->texturas[GERAR_PAPEL]);
            jogo->matriz_geraRecurso[x][y]->setDestRect((y + 2) * 80 ,(x + 2) * 72, 64, 64);
            jogo->matriz_geraRecurso[x][y]->setSrcRect(0, 0, 64, 64);
        } else {
            return false;
        }
        return true;
    } else {
        return false;
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
            return true;
        } else { /* Se a posicao e invalida */
            return false;
        }
    } else { /* Se o jogador nao tiver recursos suficientes */
        return false;
    }
}

/** Função atualizar_Recursos
 * @brief A função percorre a lista de geraRecursos e soma os recursos gerados nos atributos do player
 * */
void Player::atualizar_Recursos() {
    for(int i = 0;i < 6;++i) {
        for(int j = 0; j < 12;++j) {
            if(jogo->matriz_geraRecurso[i][j] != NULL) {
                switch (jogo->matriz_geraRecurso[i][j]->getTipo()) {
                    case RECURSO::PEDREGULHO:
                        Player::pedregulho += jogo->matriz_geraRecurso[i][j]->getTaxa();
                        break;
                    case RECURSO::METAL:
                         Player::metal += jogo->matriz_geraRecurso[i][j]->getTaxa();
                        break;
                    case RECURSO::CELULOSE:
                        Player::celulose += jogo->matriz_geraRecurso[i][j]->getTaxa();
                        break;
                    default:
                        printf("ERRO: atualizar_Recursos\n");
                        return;
                }
            }

        }

    }

    for (auto &lista_GeraRecurso : lista_GeraRecursos) {

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
    return jogo->matriz_fabrica[x][y] == NULL &&
    jogo->matriz_geraRecurso[x][y] == NULL &&
    jogo->matriz_unidade[x][y] == NULL;
}

#include "../include/Player.h"
#include <stdio.h>

/* "Copyright [2018] <Pedro>" */

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
bool Player::compra_GeraRecurso(int recurso) {
    bool success = true;  // Incializa a flag de sucesso
    /* Se tiver recursos e dinheiro para comprar*/
    if (Player::pedregulho > PRECO_RECURSO_GERA && Player::dinheiro > PRECO_DINHEIRO_GERA) {
        /* Retira os recusos da compra */
        Player::pedregulho -= PRECO_RECURSO_GERA;
        Player::dinheiro -= PRECO_DINHEIRO_GERA;
        /* Compra */
        GeraRecursos geradora(0,0, recurso);  /* Cria uma geradora de tal recurso */ // MELHORAR CONSTRUTOR
        Player::lista_GeraRecursos.push_back(geradora);  /* Adiciona a geradora na lista GeraRecursos */
        // ~geradora Free geradora
        success = true;
    } else {/* Se o dinheiro ou recurso for insuficiente */
        success = false;
    }
    return success;
}

/** Função atualizar_Recursos
 * @brief A função percorre a lista de geraRecursos e soma os recursos gerados nos atributos do player
 * */
void Player::atualizar_Recursos(){
    for (auto &lista_GeraRecurso : lista_GeraRecursos) {
        switch (lista_GeraRecurso.getTipo()){
            case RECURSO::PEDREGULHO:
                Player::pedregulho += lista_GeraRecurso.produzirRecurso();
                break;
            case RECURSO::METAL:
                Player::metal += lista_GeraRecurso.produzirRecurso();
                break;
            case RECURSO::CELULOSE:
                Player::celulose += lista_GeraRecurso.produzirRecurso();
                break;
            default:
                printf("tipo geraRecurso %d == %d \n", RECURSO::PEDREGULHO ,lista_GeraRecurso.getTipo());
                printf("ERRO: atualizar_Recursos\n");
                return;
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

Player::~Player() {

}

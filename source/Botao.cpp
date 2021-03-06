#include "Botao.h"
#include "Jogo.h"
#include "Player.h"
// Copyright [2018] <Switch Dreams>
extern Jogo* jogo;
extern Player* jogador;
extern Player* cpu;

void Botao_Sair::handleEvent(SDL_Event* evento) {
    // OPERACOES retorno = NADA;
    int x, y;
    SDL_GetMouseState(&x, &y);
    bool dentro = true;
    if (x < destRect->x) {
        dentro = false;
    } else if (x > (destRect->x + destRect->w)) {
        dentro = false;
    } else if (y < destRect->y) {
        dentro = false;
    } else if (y > (destRect->y + destRect->h)) {
        dentro = false;
    }
    if (!dentro) {
        textura = jogo->texturas[BOTAO_SAIR];
    } else {
        switch ( evento->type ) {
            case SDL_MOUSEMOTION:
                textura = jogo->texturas[BOTAO_SAIR_SOBRE];
                break;
            case SDL_MOUSEBUTTONDOWN:
                textura = jogo->texturas[BOTAO_SAIR_CLICK];
                break;
            case SDL_MOUSEBUTTONUP:
                textura = jogo->texturas[BOTAO_SAIR_CLICK];
                jogo->turnOff();
                break;
        }
    }
}

void Botao_Save::handleEvent(SDL_Event* evento) {
    // OPERACOES retorno = NADA;
    int x, y;
    SDL_GetMouseState(&x, &y);
    bool dentro = true;
    if (x < destRect->x) {
        dentro = false;
    } else if (x > (destRect->x + destRect->w)) {
        dentro = false;
    } else if (y < destRect->y) {
        dentro = false;
    } else if (y > (destRect->y + destRect->h)) {
        dentro = false;
    }
    if (!dentro) {
        textura = jogo->texturas[BOTAO_SAVE];
    } else {
        switch ( evento->type ) {
            case SDL_MOUSEMOTION:
                textura = jogo->texturas[BOTAO_SAVE_SOBRE];
                break;
            case SDL_MOUSEBUTTONDOWN:
                textura = jogo->texturas[BOTAO_SAVE_SOBRE];
                break;
            case SDL_MOUSEBUTTONUP:
                textura = jogo->texturas[BOTAO_SAVE_SOBRE];
                //  implementar funcao save();
                printf("Jogo Salvo\n");
                jogo->save();
                break;
        }
    }
}

void Botao_Iniciar::handleEvent(SDL_Event* evento) {
    // OPERACOES retorno = NADA;
    int x, y;
    SDL_GetMouseState(&x, &y);
    bool dentro = true;

    if (x < destRect->x) {
        dentro = false;
    } else if (x > (destRect->x + destRect->w)) {
        dentro = false;
    } else if (y < destRect->y) {
        dentro = false;
    } else if (y > (destRect->y + destRect->h)) {
        dentro = false;
    }

    if (!dentro) {
        textura = jogo->texturas[BOTAO_INICIAR];
    } else {
        switch ( evento->type ) {
            case SDL_MOUSEMOTION:
                textura = jogo->texturas[BOTAO_INICIAR_SOBRE];
                break;

            case SDL_MOUSEBUTTONDOWN:
                textura = jogo->texturas[BOTAO_INICIAR_CLICK];
                break;

            case SDL_MOUSEBUTTONUP:
                textura = jogo->texturas[BOTAO_INICIAR_CLICK];
                jogo->menu_inicial = false;
                break;
            }
    }
}

void Botao_Load::handleEvent(SDL_Event* evento) {
    // OPERACOES retorno = NADA;
    int x, y;
    SDL_GetMouseState(&x, &y);
    bool dentro = true;
    if (x < destRect->x) {
        dentro = false;
    } else if (x > (destRect->x + destRect->w)) {
        dentro = false;
    } else if (y < destRect->y) {
        dentro = false;
    } else if (y > (destRect->y + destRect->h)) {
        dentro = false;
    }
    if (!dentro) {
        textura = jogo->texturas[BOTAO_LOAD];
    } else {
        switch ( evento->type ) {
            case SDL_MOUSEMOTION:
                textura = jogo->texturas[BOTAO_LOAD_SOBRE];
                break;
            case SDL_MOUSEBUTTONDOWN:
                textura = jogo->texturas[BOTAO_LOAD_CLICK];
                break;
            case SDL_MOUSEBUTTONUP:
                textura = jogo->texturas[BOTAO_LOAD_CLICK];
                jogo->load();
                jogo->menu_inicial = false;
                break;
        }
    }
}

void Botao_Pause::handleEvent(SDL_Event* evento) {
    // OPERACOES retorno = NADA;
    int x, y;
    SDL_GetMouseState(&x, &y);
    bool dentro = true;
    if (x < destRect->x) {
        dentro = false;
    } else if (x > (destRect->x + destRect->w)) {
        dentro = false;
    } else if (y < destRect->y) {
        dentro = false;
    } else if (y > (destRect->y + destRect->h)) {
        dentro = false;
    }
    if (!dentro) {
        textura = jogo->texturas[BOTAO_PAUSE];
    } else {
        switch ( evento->type ) {
            case SDL_MOUSEMOTION:
                textura = jogo->texturas[BOTAO_PAUSE_SOBRE];
                break;
            case SDL_MOUSEBUTTONDOWN:
                textura = jogo->texturas[BOTAO_PAUSE_CLICK];
                break;
            case SDL_MOUSEBUTTONUP:
                textura = jogo->texturas[BOTAO_PAUSE_CLICK];
                jogo->paused = true;
                break;
        }
    }
}
void Botao_Resume::handleEvent(SDL_Event* evento) {
    // OPERACOES retorno = NADA;
    int x, y;
    SDL_GetMouseState(&x, &y);
    bool dentro = true;
    if (x < destRect->x) {
        dentro = false;
    } else if (x > (destRect->x + destRect->w)) {
        dentro = false;
    } else if (y < destRect->y) {
        dentro = false;
    } else if (y > (destRect->y + destRect->h)) {
        dentro = false;
    }
    if (!dentro) {
        textura = jogo->texturas[BOTAO_RESUME];
    } else {
        switch ( evento->type ) {
            case SDL_MOUSEMOTION:
                textura = jogo->texturas[BOTAO_RESUME_SOBRE];
                break;
            case SDL_MOUSEBUTTONDOWN:
                textura = jogo->texturas[BOTAO_RESUME_CLICK];
                break;
            case SDL_MOUSEBUTTONUP:
                textura = jogo->texturas[BOTAO_RESUME_CLICK];
                jogo->paused = false;
                break;
        }
    }
}


void buttomEvents(SDL_Event* evento) {
    int x = 0, y = 0;

    SDL_GetMouseState(&x, &y);

    switch (evento->type) {
        case SDL_MOUSEMOTION:
            break;
        case SDL_MOUSEBUTTONDOWN:
            break;
        case SDL_MOUSEBUTTONUP:
            if (jogo->comprando) {
                to_Cord(&x, &y);
                x -= 2;
                y -= 2;
                if (x < 0 || x >= 12 || y < 0 || y >= 6) {
                    jogo->comprando = false;
                    jogo->tipoCompra = NADA;
                    break;
                }
                switch (jogo->tipoCompra) {
                    case NADA:
                        jogo->ultima_acao.last[NADA] = true;
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        break;
                    case UNIDADE_PAPEL:
                        if (jogador->compra_Unidade(y, x, UNIDADE::PAPEL,
                                jogo->nivelCompra)) {
                            printf("Tropa papel comprada com sucesso \n");
                        } else {
                            printf("Falha na compra da tropa papel\n");
                        }
                        jogo->ultima_acao.last[UNIDADE_PAPEL] = true;
                        jogo->ultima_acao.ondeX = x;
                        jogo->ultima_acao.ondeY = y;
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        jogo->nivelCompra = 0;
                        break;
                    case UNIDADE_PEDRA:
                        if (jogador->compra_Unidade(y, x, UNIDADE::PEDRA,
                                jogo->nivelCompra)) {
                            printf("Tropa pedra comprada com sucesso \n");
                        } else {
                            printf("Falha na compra da tropa pedra\n");
                        }
                        jogo->ultima_acao.last[UNIDADE_PEDRA] = true;
                        jogo->ultima_acao.ondeX = x;
                        jogo->ultima_acao.ondeY = y;
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        jogo->nivelCompra = 0;
                        break;
                    case UNIDADE_TESOURA:
                        if (jogador->compra_Unidade(y, x, UNIDADE::TESOURA,
                                jogo->nivelCompra)) {
                            printf("Tropa tesoura comprada com sucesso \n");
                        } else {
                            printf("Falha na compra da tropa tesoura\n");
                        }
                        jogo->ultima_acao.last[UNIDADE_TESOURA] = true;
                        jogo->ultima_acao.ondeX = x;
                        jogo->ultima_acao.ondeY = y;
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        jogo->nivelCompra = 0;
                        break;
                    case U_FABRICA_PAPEL:
                        if (jogo->matriz_fabrica[y][x] != NULL) {
                            if (jogo->matriz_fabrica[y][x]->tipo ==
                            UNIDADE::PAPEL) {
                                if (jogo->matriz_fabrica[y][x]->upgrade_fabrica
                                (&(jogador->dinheiro))) {
                                    printf("Upgrade realizado FABRICA PAPEL\n");
                                    printf("Novo nivel da fabrica %d\n",
                                            jogo->matriz_fabrica[y][x]->
                                            get_nivel());
                                    jogo->matriz_fabrica[y][x]->mudaTextura
                                          (jogo->texturas[FABRICA_PAPEL_UP]);
                                } else {
                                    printf("Nao foi possivel dar o upgrade\n");
                                }
                            }
                        }
                        jogo->ultima_acao.last[U_FABRICA_PAPEL] = true;
                        jogo->ultima_acao.ondeX = x;
                        jogo->ultima_acao.ondeY = y;
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        break;
                    case U_FABRICA_PEDRA:
                        if (jogo->matriz_fabrica[y][x] != NULL) {
                            if (jogo->matriz_fabrica[y][x]->tipo ==
                            UNIDADE::PEDRA) {
                                if (jogo->matriz_fabrica[y][x]->upgrade_fabrica
                                (&(jogador->dinheiro))) {
                                    printf("Upgrade realizado FABRICA PAPEL\n");
                                    printf("Novo nivel da fabrica %d\n",
                                            jogo->matriz_fabrica[y][x]->
                                            get_nivel());
                                    jogo->matriz_fabrica[y][x]->mudaTextura
                                          (jogo->texturas[FABRICA_PEDRA_UP]);
                                } else {
                                    printf("Nao foi possivel dar o upgrade\n");
                                }
                            }
                        }
                        jogo->ultima_acao.last[U_FABRICA_PEDRA] = true;
                        jogo->ultima_acao.ondeX = x;
                        jogo->ultima_acao.ondeY = y;
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        break;
                    case U_FABRICA_TESOURA:
                        if (jogo->matriz_fabrica[y][x] != NULL) {
                            if (jogo->matriz_fabrica[y][x]->tipo ==
                            UNIDADE::TESOURA) {
                                if (jogo->matriz_fabrica[y][x]->upgrade_fabrica
                                (&(jogador->dinheiro))) {
                                    printf("Upgrade realizado FABRICA PAPEL\n");
                                    printf("Novo nivel da fabrica %d\n",
                                            jogo->matriz_fabrica[y][x]->
                                            get_nivel());
                                    jogo->matriz_fabrica[y][x]->mudaTextura
                                          (jogo->texturas[FABRICA_TESOURA_UP]);
                                } else {
                                    printf("Nao foi possivel dar upgrade\n");
                                }
                            }
                        }
                        jogo->ultima_acao.last[U_FABRICA_TESOURA] = true;
                        jogo->ultima_acao.ondeX = x;
                        jogo->ultima_acao.ondeY = y;
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        break;
                    case U_GERA_METAL:
                        if (jogo->matriz_geraRecurso[y][x] != NULL) {
                            if (jogo->matriz_geraRecurso[y][x]->getTipo() ==
                            RECURSO::METAL) {
                                printf("upgrade realizado gera metal\n ");
                                jogo->matriz_geraRecurso[y][x]->upgrade
                                (&(jogador->dinheiro));
                                jogo->matriz_geraRecurso[y][x]->mudaTextura
                                      (jogo->texturas[GERAR_TESOURA_UP]);
                            } else {
                                printf("Upgrade negado gera metal\n");
                            }
                        }
                        jogo->ultima_acao.last[U_GERA_METAL] = true;
                        jogo->ultima_acao.ondeX = x;
                        jogo->ultima_acao.ondeY = y;
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        break;

                    case U_GERA_PEDREGULHO:
                        if (jogo->matriz_geraRecurso[y][x] != NULL) {
                            if (jogo->matriz_geraRecurso[y][x]->getTipo() ==
                            RECURSO::PEDREGULHO) {
                                printf("upgrade realizado gera pedregulho\n ");
                                jogo->matriz_geraRecurso[y][x]->upgrade
                                (&(jogador->dinheiro));
                                jogo->matriz_geraRecurso[y][x]->mudaTextura
                                      (jogo->texturas[GERAR_PEDRA_UP]);
                            } else {
                                printf("Upgrade negado gera pedregulho\n");
                            }
                        }
                        jogo->ultima_acao.last[U_GERA_PEDREGULHO] = true;
                        jogo->ultima_acao.ondeX = x;
                        jogo->ultima_acao.ondeY = y;
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        break;

                    case U_GERA_CELULOSE:
                        if (jogo->matriz_geraRecurso[y][x] != NULL) {
                            if (jogo->matriz_geraRecurso[y][x]->getTipo()
                            == RECURSO::CELULOSE) {
                                printf("upgrade realizado gera celulose \n");
                                jogo->matriz_geraRecurso[y][x]->upgrade
                                (&(jogador->dinheiro));
                                jogo->matriz_geraRecurso[y][x]->mudaTextura
                                      (jogo->texturas[GERAR_PAPEL_UP]);
                            } else {
                                printf("Upgrade negado gera celulose\n");
                            }
                        }
                        jogo->ultima_acao.last[U_GERA_CELULOSE] = true;
                        jogo->ultima_acao.ondeX = x;
                        jogo->ultima_acao.ondeY = y;
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        break;

                    case FABRICAR_PAPEL:
                        jogador->compra_Fabrica(y, x, PAPEL);
                        jogo->ultima_acao.last[FABRICAR_PAPEL] = true;
                        jogo->ultima_acao.ondeX = x;
                        jogo->ultima_acao.ondeY = y;
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        break;

                    case FABRICAR_TESOURA:
                        jogador->compra_Fabrica(y, x, TESOURA);
                        jogo->ultima_acao.last[FABRICAR_TESOURA] = true;
                        jogo->ultima_acao.ondeX = x;
                        jogo->ultima_acao.ondeY = y;
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        break;

                    case FABRICAR_PEDRA:
                        jogador->compra_Fabrica(y, x, PEDRA);
                        jogo->ultima_acao.last[FABRICAR_PEDRA] = true;
                        jogo->ultima_acao.ondeX = x;
                        jogo->ultima_acao.ondeY = y;
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        break;

                    case GERA_CELULOSE:
                        if (jogador->compra_GeraRecurso(y, x, CELULOSE)) {
                            printf("Gera celulose comprado com sucesso\n");
                        } else {
                            printf("Falha na compra\n");
                        }
                        jogo->ultima_acao.last[GERA_CELULOSE] = true;
                        jogo->ultima_acao.ondeX = x;
                        jogo->ultima_acao.ondeY = y;
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                    break;

                    case GERA_PEDREGULHO:
                        if (jogador->compra_GeraRecurso(y, x, PEDREGULHO)) {
                            printf("Gera pedregulho comprado com sucesso\n");
                        } else {
                            printf("Falha na compra\n");
                        }
                        jogo->ultima_acao.last[GERA_PEDREGULHO] = true;
                        jogo->ultima_acao.ondeX = x;
                        jogo->ultima_acao.ondeY = y;
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        break;

                    case GERA_METAL:
                        if (jogador->compra_GeraRecurso(y, x, METAL)) {
                            printf("Gera pedregulho comprado com sucesso\n");
                        } else {
                            printf("Falha na compra\n");
                        }
                        jogo->ultima_acao.last[GERA_METAL] = true;
                        jogo->ultima_acao.ondeX = x;
                        jogo->ultima_acao.ondeY = y;
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        break;

                    default:
                        printf("aaaa\n");
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                }  // switch
            } /* if */else {
                retornaBotao(&x, &y);
            }  // else
            printf("tipo: %d , comprando: %d, nivelCompra: %d \n",
                    jogo->tipoCompra, (jogo->comprando ? 1 : 0),
                    jogo->nivelCompra);
            // printf("x: %d , y: %d\n", x, y);
    }
}

bool in_range_mapa(int x, int y) {
    return x >= 0 && y >=0 && x < 6 && y < 12;
}

bool verifica_clique_fabrica(const int* X, const int* Y) {
    /* Conversao de coordenadas de clique para coordenadas de mapa */
    int x = *X - 2;
    int y = *Y - 2;
    /* Se x e y estiverem dentro do escopo do mapa*/
    if (in_range_mapa(y, x)) {
        // Verifica se o clique foi em cima de uma fabrica
        if (jogo->matriz_fabrica[y][x] != NULL) {
            // Verifica o nivel da fabrica e
            jogo->comprando = true;
            switch (jogo->matriz_fabrica[y][x]->getTipo()) {
                case UNIDADE::TESOURA:
                    jogo->tipoCompra = UNIDADE_TESOURA;
                    jogo->nivelCompra = jogo->matriz_fabrica[y][x]->get_nivel();
                    break;
                case UNIDADE::PEDRA:
                    jogo->tipoCompra = UNIDADE_PEDRA;
                    jogo->nivelCompra = jogo->matriz_fabrica[y][x]->get_nivel();
                    break;
                case UNIDADE::PAPEL:
                    jogo->tipoCompra = UNIDADE_PAPEL;
                    jogo->nivelCompra = jogo->matriz_fabrica[y][x]->get_nivel();
                    break;
            }
            return true; /* Clicou em uma fabrica */
        }
    }
    return false; /* Nao clicou em uma fabrica*/
}

void retornaBotao(int* X, int* Y) {
    jogo->comprando = true;
    to_Cord(X, Y);
    /* Se o clique for em uma fabrica */
    if (verifica_clique_fabrica(X, Y))
        return;
    switch (*Y) {
        case 8:
            switch (*X) {
                case 4:
                    jogo->tipoCompra = FABRICAR_PAPEL;
                    return;
                case 5:
                    jogo->tipoCompra = FABRICAR_TESOURA;
                    return;
                case 6:
                    jogo->tipoCompra = FABRICAR_PEDRA;
                    return;
                case 11:
                    jogo->tipoCompra = U_FABRICA_PAPEL;
                    return;
                case 12:
                    jogo->tipoCompra = U_FABRICA_TESOURA;
                    return;
                case 13:
                    jogo->tipoCompra = U_FABRICA_PEDRA;
                    return;
                default:
                    jogo->tipoCompra = NADA;
                    jogo->comprando = false;
                    return;
            }
        case 9:
            switch (*X) {
                case 4:
                    jogo->tipoCompra = GERA_PEDREGULHO;
                    return;
                case 5:
                    jogo->tipoCompra = GERA_METAL;
                    return;
                case 6:
                    jogo->tipoCompra = GERA_CELULOSE;
                    return;
                case 11:
                    jogo->tipoCompra = U_GERA_PEDREGULHO;
                    return;
                case 12:
                    jogo->tipoCompra = U_GERA_METAL;
                    return;
                case 13:
                    jogo->tipoCompra = U_GERA_CELULOSE;
                    return;
                default:
                    jogo->tipoCompra = NADA;
                    jogo->comprando = false;
                    return;
            }
        default:
            jogo->tipoCompra = NADA;
            jogo->comprando = false;
    }
}

void to_Cord(int* X, int* Y) {
    if ((*X % 80) != 0) {
        *X -= (*X % 80);
        *X = *X / 80;
        // *X = *X / 72;
    } else {
        *X = *X / 80;
    }
    if ((*Y % 74) != 0) {
        *Y -= (*Y % 72);
        *Y = *Y / 72;
    } else {
        *Y = *Y / 72;
    }
    printf("x: %d , y: %d\n", *X, *Y);
}

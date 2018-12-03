#include "Jogo.h"

// "Copyright [2018] <SW Dreams>"

extern Player* jogador;
extern Player* cpu;


Jogo::Jogo() {
    matriz_fabrica = new Fabrica **[6];
    matriz_unidade = new Unidade **[6];
    matriz_geraRecurso = new GeraRecursos**[6];
    for (int i=0; i < 6; i++) {
        matriz_fabrica[i] = new Fabrica *[12];
        matriz_unidade[i] = new Unidade *[12];
        matriz_geraRecurso[i] = new GeraRecursos *[12];
    }
    for (int i=0; i< 6; i++) {
        for (int j=0; j < 12; j++) {
            matriz_fabrica[i][j] = NULL;
            matriz_unidade[i][j] = NULL;
            matriz_geraRecurso[i][j] = NULL;
        }
    }
    jogador = new Player();
    cpu = new Player();
    mapa = new Objeto(0, 0);/* Set e get depois*/
    bIniciar = new Botao_Iniciar(0, 0);
    menuInicial = new Objeto(0, 0);
    bLoad = new Botao_Load(0, 0);
    pause = new Botao_Pause(0, 0);
    resume = new Botao_Resume(0, 0);
    bSair = new Botao_Sair(0, 0);
    bSalvar = new Botao_Save(0, 0);
    vitoria = new Objeto(0, 0);
    derrota = new Objeto(0, 0);

    recursoDinheiroJogador = new Objeto(0, 0);
    recursoCeluloseJogador = new Objeto(0, 0);
    recursoPedregulhoJogador = new Objeto(0, 0);
    recursoMetalJogador = new Objeto(0, 0);
    recursoDinheiroCpu = new Objeto(0, 0);
    recursoCeluloseCpu = new Objeto(0, 0);
    recursoPedregulhoCpu = new Objeto(0, 0);
    recursoMetalCpu = new Objeto(0, 0);
    tempo_Obj = new Objeto(0, 0);

    ultima_acao.last = reinterpret_cast<bool*>(malloc(16*sizeof(bool)));
}

Jogo::~Jogo() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (matriz_fabrica[i][j] != NULL) {
                delete matriz_fabrica[i][j];
            }
            if (matriz_geraRecurso[i][j] != NULL) {
                delete matriz_geraRecurso[i][j];
            }
            if (matriz_unidade[i][j] != NULL) {
                delete matriz_unidade[i][j];
            }
        }
    }
    for (int i = 0; i < 6; ++i) {
        delete[] matriz_fabrica[i];
        delete[] matriz_geraRecurso[i];
        delete[] matriz_unidade[i];
    }
    delete[] matriz_fabrica;
    delete[] matriz_geraRecurso;
    delete[] matriz_unidade;

    // delete jogador;
    // jogador = NULL;
    // delete cpu;
    // cpu = NULL;

    delete derrota;
    derrota = NULL;
    delete vitoria;
    vitoria = NULL;
    delete bSalvar;
    bSalvar = NULL;
    delete bSair;
    bSair = NULL;
    delete pause;
    pause = NULL;
    delete resume;
    resume = NULL;
    delete bLoad;
    bLoad = NULL;
    delete bIniciar;
    bIniciar = NULL;
    delete menuInicial;
    menuInicial = NULL;
    delete mapa;
    mapa = NULL;
    delete recursoDinheiroJogador;
    recursoDinheiroJogador = NULL;
    delete recursoCeluloseJogador;
    recursoCeluloseJogador = NULL;
    delete recursoPedregulhoJogador;
    recursoPedregulhoJogador = NULL;
    delete recursoMetalJogador;
    recursoMetalJogador = NULL;
    delete recursoDinheiroCpu;
    recursoDinheiroCpu = NULL;
    delete recursoCeluloseCpu;
    recursoCeluloseCpu = NULL;
    delete recursoPedregulhoCpu;
    recursoPedregulhoCpu = NULL;
    delete recursoMetalCpu;
    recursoMetalCpu = NULL;
    delete tempo_Obj;
    tempo_Obj = NULL;

    free(ultima_acao.last);
}

int ataca_base(Unidade* unidade, Player* jogador) {
    jogador->setVida(jogador->getVida() - unidade->getDano());
    printf("Atacou a Base: Vida atual %d\n", jogador->getVida());
    if (jogador->getVida() <= 0) {
        return PLAYER_MORREU;
    }
    return PLAYER_N_MORREU;
}

void Jogo::turnOff() {
    on = false;
}

int retorna_dano(Unidade* unidade1, int tipo2) {
    int dano = unidade1->getDano();
    if ((unidade1->getTipo() == UNIDADE::PAPEL && tipo2 == UNIDADE::PEDRA) ||
        (unidade1->getTipo() == UNIDADE::PEDRA && tipo2 == UNIDADE::TESOURA) ||
        (unidade1->getTipo() == UNIDADE::TESOURA && tipo2 == UNIDADE::PAPEL)) {
            dano *= 2;
    }
    return dano;
}


int combate_unidade(Unidade** atacante, Unidade** defensor) {
    Unidade** aux;
    int mortes = 0;
    // Define dano de acordo com as fraquezas
    int danoAtacante = retorna_dano((*atacante), (*defensor)->getTipo());
    int danoDefensor = retorna_dano((*defensor), (*atacante)->getTipo());

    // Enquanto alguma unidade tem vida, ataca
    while ((*atacante)->getVida() > 0 && (*defensor)->getVida() > 0) {
        (*atacante)->setVida((*atacante)->getVida() - danoDefensor);
        (*defensor)->setVida((*defensor)->getVida() - danoAtacante);
    }

    // Se alguma unidade não tem vida, destrói
    if ((*defensor)->getVida() <= 0 && (*atacante)->getVida() <= 0) {
        auto aux = (*defensor);
        return 3;
    }
    if ((*defensor)->getVida() <= 0) {
        if((*atacante)->getNivel() == 1){
            if((*atacante)->getVida() < (1 * (VIDA_UNIDADE_1 / 3))) {

                (*atacante)->setSrcRect(128, (*atacante)->srcRect->y,
                (*atacante)->srcRect->w,(*atacante)->srcRect->h);
            } else if((*atacante)->getVida() < (2 * (VIDA_UNIDADE_1 / 3))) {
                (*atacante)->setSrcRect(64, (*atacante)->srcRect->y,
                (*atacante)->srcRect->w, (*atacante)->srcRect->h);
            }

        } else if((*atacante)->getNivel() == 2) {
            if((*atacante)->getVida() < (1 * (VIDA_UNIDADE_2 / 3))) {

                (*atacante)->setSrcRect(128, (*atacante)->srcRect->y,
                (*atacante)->srcRect->w, (*atacante)->srcRect->h);
            } else if((*atacante)->getVida() < (2 * (VIDA_UNIDADE_2 / 3))) {
                (*atacante)->setSrcRect(64, (*atacante)->srcRect->y,
                (*atacante)->srcRect->w, (*atacante)->srcRect->h);
            }

        } else if ((*atacante)->getNivel() == 3) {
            if ((*atacante)->getVida() < (1 * (VIDA_UNIDADE_3 / 3))) {
                (*atacante)->setSrcRect(128, (*atacante)->srcRect->y,
                (*atacante)->srcRect->w, (*atacante)->srcRect->h);
            } else if ((*atacante)->getVida() < (2 * (VIDA_UNIDADE_3 / 3))) {
                (*atacante)->setSrcRect(64, (*atacante)->srcRect->y,
                (*atacante)->srcRect->w, (*atacante)->srcRect->h);
            }
        }
        return 2;
    }
    if ((*atacante)->getVida() <= 0) {
        if ((*defensor)->getNivel() == 1) {
            if ((*defensor)->getVida() < (1 * (VIDA_UNIDADE_1 / 3))) {
                (*defensor)->setSrcRect(128, (*defensor)->srcRect->y,
                (*defensor)->srcRect->w, (*defensor)->srcRect->h);
            } else if ((*defensor)->getVida() < (2 * (VIDA_UNIDADE_1 / 3))) {
                (*defensor)->setSrcRect(64, (*defensor)->srcRect->y,
                (*defensor)->srcRect->w, (*defensor)->srcRect->h);
            }
        } else if ((*defensor)->getNivel() == 2) {
            if ((*defensor)->getVida() < (1 * (VIDA_UNIDADE_2 / 3))) {
                (*defensor)->setSrcRect(128, (*defensor)->srcRect->y,
                (*defensor)->srcRect->w, (*defensor)->srcRect->h);
            } else if ((*defensor)->getVida() < (2 * (VIDA_UNIDADE_2 / 3))) {
                (*defensor)->setSrcRect(64, (*defensor)->srcRect->y,
                (*defensor)->srcRect->w, (*defensor)->srcRect->h);
            }

        } else if ((*defensor)->getNivel() == 3) {
            if ((*defensor)->getVida() < (1 * (VIDA_UNIDADE_3 / 3))) {
                (*defensor)->setSrcRect(128, (*defensor)->srcRect->y,
                (*defensor)->srcRect->w, (*defensor)->srcRect->h);
            } else if ((*defensor)->getVida() < (2 * (VIDA_UNIDADE_3 / 3))) {
                (*defensor)->setSrcRect(64, (*defensor)->srcRect->y,
                (*defensor)->srcRect->w, (*defensor)->srcRect->h);
            }
        }
        return 1;
    }
}

void anda(Unidade** unidade, Unidade** destino) {
    Unidade* aux;
    aux = *destino;
    *destino = *unidade;
    *unidade = aux;
}

int ataca_fabrica(Unidade** unidade1, Fabrica** fbrc1) {
    int dano = retorna_dano((*unidade1), (*fbrc1)->getTipo());
    // Unidade retira vida da fábrica
    (*fbrc1)->set_vida((*fbrc1)->get_vida() - dano);
    // Unidade é destruida
    // Se fábrica não tem vida, é destruida
    if ((*fbrc1)->get_vida() <= 0) {
        return 1;
    }
    if ((*fbrc1)->get_vida() < (1 * (VIDA_INICIAL_FABRICA))) {
        (*fbrc1)->setSrcRect(128, (*fbrc1)->srcRect->y, (*fbrc1)->srcRect->w,
        (*fbrc1)->srcRect->h);
    } else if ((*fbrc1)->get_vida() < (2 * (VIDA_INICIAL_FABRICA))) {
        (*fbrc1)->setSrcRect(64, (*fbrc1)->srcRect->y, (*fbrc1)->srcRect->w,
        (*fbrc1)->srcRect->h);
    }

    return 0;
}

int ataca_geraRecurso(Unidade** unidade1, GeraRecursos** geradora) {
    int dano = retorna_dano((*unidade1), (*geradora)->getTipo());
    // Unidade retira vida da geradora
    (*geradora)->set_vida((*geradora)->get_vida() - dano);
    // Unidade é destruida
    // Se geradora não tem vida, é destruida
    if ((*geradora)->get_vida() <= 0) {
        return 1;
    }
    if ((*geradora)->get_vida() < (1 * (VIDA_INICIAL_FABRICA))) {
        (*geradora)->setSrcRect(128, (*geradora)->srcRect->y,
        (*geradora)->srcRect->w, (*geradora)->srcRect->h);
    } else if ((*geradora)->get_vida() < (2 * (VIDA_INICIAL_FABRICA))) {
        (*geradora)->setSrcRect(64, (*geradora)->srcRect->y,
        (*geradora)->srcRect->w, (*geradora)->srcRect->h);
    }
    return 0;
}

void Jogo::movimentacao() {
    /* Casos meio da matriz */
    for (int lin = 0; lin < 6 ; lin++) {
        /* Condicoes de atacar base principal*/
        if (Jogo::matriz_unidade[lin][11] != NULL
        && Jogo::matriz_unidade[lin][11]->getVelocidade() > 0) {
            // ataca base cpu, e despois se auto destroi
            if (ataca_base(Jogo::matriz_unidade[lin][11], cpu) == PLAYER_MORREU) {
                ganhou = true;
                printf("CPU Perdeu...");
            }
            delete Jogo::matriz_unidade[lin][11];
            Jogo::matriz_unidade[lin][11] = NULL;
        }
        if (Jogo::matriz_unidade[lin][0] != NULL
        && Jogo::matriz_unidade[lin][0]->getVelocidade() < 0) {
            // ataca base player, e despois se auto destroi
            if (ataca_base(Jogo::matriz_unidade[lin][0], jogador) == PLAYER_MORREU) {
                perdeu = true;
                printf("Jogador Perdeu...");
            }
            delete Jogo::matriz_unidade[lin][0];
            Jogo::matriz_unidade[lin][0] = NULL;
        }

        /* Na 11 ja foi verificado, e so pode ser criado apartir da
         * 2 as tropas com  velocidade positiva */
        for (int col = 10; col >= 2; col --) {
            if (Jogo::matriz_unidade[lin][col] != NULL) {
                if (Jogo::matriz_unidade[lin][col]->getVelocidade() > 0) {
                   if (Jogo::matriz_unidade[lin][col + 1] != NULL) {
                       // ataca tropa
                       switch (combate_unidade(&Jogo::matriz_unidade[lin][col],
                               &Jogo::matriz_unidade[lin][col + 1])) {
                           case 1:
                               // atacante morre
                               delete Jogo::matriz_unidade[lin][col];
                               Jogo::matriz_unidade[lin][col] = NULL;
                               break;
                           case 2:
                               // defensor morre
                               Jogo::matriz_unidade[lin][col + 1];
                               Jogo::matriz_unidade[lin][col] = NULL;
                               Jogo::matriz_unidade[lin][col]->setDestRect
                               ((lin + 2) * 80 , (col + 2) * 72, 64, 64);
                               anda(&Jogo::matriz_unidade[lin][col],
                                       &Jogo::matriz_unidade[lin][col + 1]);
                               break;
                           case 3:
                               // ambos morrem
                               delete Jogo::matriz_unidade[lin][col];
                               Jogo::matriz_unidade[lin][col] = NULL;

                               Jogo::matriz_unidade[lin][col + 1];
                               Jogo::matriz_unidade[lin][col] = NULL;
                               break;
                       }
                   } else if (Jogo::matriz_geraRecurso[lin][col + 1] != NULL) {
                       // ataca geraRecurso
                       switch (ataca_geraRecurso
                       (&Jogo::matriz_unidade[lin][col],
                               &Jogo::matriz_geraRecurso[lin][col + 1])) {
                           case 0:
                               delete Jogo::matriz_unidade[lin][col];
                               Jogo::matriz_unidade[lin][col] = NULL;
                               break;
                           case 1:
                               // Geradora morre
                               delete Jogo::matriz_unidade[lin][col];
                               Jogo::matriz_unidade[lin][col] = NULL;
                               delete Jogo::matriz_geraRecurso[lin][col + 1];
                               Jogo::matriz_geraRecurso[lin][col + 1] = NULL;
                               break;
                       }
                   } else if (Jogo::matriz_fabrica[lin][col + 1] != NULL) {
                       // ataca fabrica
                       switch (ataca_fabrica
                       (&Jogo::matriz_unidade[lin][col],
                               &Jogo::matriz_fabrica[lin][col + 1])) {
                           case 0:
                               delete Jogo::matriz_unidade[lin][col];
                               Jogo::matriz_unidade[lin][col] = NULL;
                               break;
                           case 1:
                               // Fábrica morre
                               delete Jogo::matriz_fabrica[lin][col +1];
                               Jogo::matriz_fabrica[lin][col +1] = NULL;
                               delete Jogo::matriz_unidade[lin][col];
                               Jogo::matriz_unidade[lin][col] = NULL;
                               break;
                       }
                   } else {
                       Jogo::matriz_unidade[lin][col]->setDestRect
                       ((col + 2) * 80 , (lin + 2) * 72, 64, 64);
                       anda(&Jogo::matriz_unidade[lin][col],
                               &Jogo::matriz_unidade[lin][col + 1]);
                       // anda para direita
                   }
                } /* if velo positiva */
            } /* if != NULL*/
        } /* for col */

        /* Na 0 ja foi verificado, e so pode ser criado apartir da 9
         * as tropas com velocidade negativa */
        for (int col = 1; col < 10; col ++) {
            if (Jogo::matriz_unidade[lin][col] != NULL) {
                if (Jogo::matriz_unidade[lin][col]->getVelocidade() < 0) {
                    if (Jogo::matriz_unidade[lin][col - 1] != NULL) {
                        // ataca tropa
                        switch (combate_unidade
                        (&Jogo::matriz_unidade[lin][col],
                                &Jogo::matriz_unidade[lin][col - 1])) {
                            case 1:
                                // atacante morre
                                delete Jogo::matriz_unidade[lin][col];
                                Jogo::matriz_unidade[lin][col] = NULL;
                                break;
                            case 2:
                                // defensor morre
                                Jogo::matriz_unidade[lin][col - 1];
                                Jogo::matriz_unidade[lin][col] = NULL;
                                Jogo::matriz_unidade[lin][col]->setDestRect
                                ((lin + 2) * 80 , (col + 1) * 72, 64, 64);
                                anda(&Jogo::matriz_unidade[lin][col],
                                        &Jogo::matriz_unidade[lin][col - 1]);
                                break;
                            case 3:
                                // ambos morrem
                                delete Jogo::matriz_unidade[lin][col];
                                Jogo::matriz_unidade[lin][col] = NULL;

                                Jogo::matriz_unidade[lin][col - 1];
                                Jogo::matriz_unidade[lin][col] = NULL;
                                break;
                        }
                    } else if (Jogo::matriz_geraRecurso[lin][col - 1] != NULL) {
                        // ataca geraRecurso
                        switch (ataca_geraRecurso
                        (&Jogo::matriz_unidade[lin][col],
                                &Jogo::matriz_geraRecurso[lin][col - 1])) {
                            case 0:
                                delete Jogo::matriz_unidade[lin][col];
                                Jogo::matriz_unidade[lin][col] = NULL;
                                break;
                            case 1:
                                // Geradora morre
                                delete Jogo::matriz_unidade[lin][col];
                                Jogo::matriz_unidade[lin][col] = NULL;
                                delete Jogo::matriz_geraRecurso[lin][col - 1];
                                Jogo::matriz_geraRecurso[lin][col - 1] = NULL;
                                break;
                        }
                    } else if (Jogo::matriz_fabrica[lin][col - 1] != NULL) {
                        // ataca fabrica
                        switch (ataca_fabrica(&Jogo::matriz_unidade[lin][col],
                                &Jogo::matriz_fabrica[lin][col - 1])) {
                            case 0:
                                delete Jogo::matriz_unidade[lin][col];
                                Jogo::matriz_unidade[lin][col] = NULL;
                                break;
                            case 1:
                                // Fábrica morre
                                delete Jogo::matriz_fabrica[lin][col - 1];
                                Jogo::matriz_fabrica[lin][col - 1] = NULL;
                                delete Jogo::matriz_unidade[lin][col];
                                Jogo::matriz_unidade[lin][col] = NULL;
                                break;
                        }
                    } else {
                        // anda para esquerda
                        Jogo::matriz_unidade[lin][col]->setDestRect
                        ((col + 2) * 80 , (lin + 2) * 72, 64, 64);
                        anda(&Jogo::matriz_unidade[lin][col],
                                &Jogo::matriz_unidade[lin][col - 1]);
                    }
                } /* if velo positiva */
            } /* if != NULL*/
        } /* for col */
    } /* for lin */
} /* Jogo::movimentacao */

void Jogo::init(const char* nome, int x, int y, int w, int h) {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Sistema Inicializado!...." << std::endl;

        janela = SDL_CreateWindow(nome, x, y, w, h, 0);
        if (janela) {
            std::cout << "Janela criada!" << std::endl;
        }
        render = SDL_CreateRenderer(janela, -1, 0);
        if (render) {
            SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
            std::cout << "Render criado!" << std::endl;
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags)) {
                printf("SDL_image could not initialize! SDL_image Error: %s\n",
                        IMG_GetError());
                on = false;
            }
            if ( TTF_Init() == -1 ) {
                printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n",
                        TTF_GetError());
                on = false;
            }

            // Initialize SDL_mixer
            if ( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0 ) {
                printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n",
                 Mix_GetError());
            }
            /* Set e get depois*/
            menu_inicial = true;
        }
        on = true;
    } else {
        on = false;
    }
}

bool Jogo::isOn() {
    return on;
}

void Jogo::handleEvents() {
    SDL_Event evento;
    while (SDL_PollEvent(&evento)) {
        switch (evento.type) {
            case SDL_QUIT:
                turnOff();
                break;
            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
            case SDL_MOUSEMOTION:
                if (menu_inicial) {
                    bIniciar->handleEvent(&evento);
                    bLoad->handleEvent(&evento);
                    bSair->handleEvent(&evento);
                } else {
                    pause->handleEvent(&evento);
                    resume->handleEvent(&evento);
                    bSalvar->handleEvent(&evento);
                    buttomEvents(&evento);
                    break;
                }
            default:
                break;
        }
    }
}

void Jogo::renderizar() {
    int cont = 0;
    static bool musica_parou = true;
    SDL_RenderClear(render);
    // Adione aqui as coisas para renderizar
    if (menu_inicial) {
        // Se nao estiver tocando a musica
        if (!Mix_PlayingMusic()) {
            // Toca a musica Principal
            Mix_PlayMusic(musicas[MUS_INICIAL], -1);
        }
        menuInicial->render(render);
        bIniciar->render(render);
        bLoad->render(render);
        bSair->render(render);
    } else {
        if (musica_parou) {
            Mix_HaltMusic();
            musica_parou = false;
        }
        if (!Mix_PlayingMusic()) {
            Mix_PlayMusic(musicas[MUS_JOGO_NARUTO], -1);
        }
        mapa->render(render);
        // compra->render(render);
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 12; j++) {
                if (matriz_fabrica[i][j] != NULL) {
                    matriz_fabrica[i][j]->render(render);
                }
                if (matriz_geraRecurso[i][j] != NULL) {
                    matriz_geraRecurso[i][j]->render(render);
                    // printf("render %d\n",cont);
                }
                if (matriz_unidade[i][j] != NULL) {
                    matriz_unidade[i][j]->render(render);
                }
                cont++;
            }
        }
        if (ganhou) {
          vitoria->render(render);
        }
        if (perdeu) {
          derrota->render(render);
        }
        recursoDinheiroJogador->render(render);
        recursoCeluloseJogador->render(render);
        recursoPedregulhoJogador->render(render);
        recursoMetalJogador->render(render);
        recursoDinheiroCpu->render(render);
        recursoCeluloseCpu->render(render);
        recursoPedregulhoCpu->render(render);
        recursoMetalCpu->render(render);
        tempo_Obj->render(render);
        pause->render(render);
        resume->render(render);
        bSalvar->render(render);
    }
    SDL_RenderPresent(render);
}

void Jogo::fim() {
    for (int i = 0; i < TEXTURAS::TEX_TOTAL; ++i) {
        SDL_DestroyTexture(texturas[i]);
        texturas[i] = NULL;
    }

    for (int i = 0; i < MUSICAS ::MUS_TOTAL; ++i) {
        Mix_FreeMusic(musicas[i]);
        musicas[i] = NULL;
    }

    for (int i = 0; i < EFEITOS ::EFEITO_TOTAL; ++i) {
        Mix_FreeChunk(efeitos[i]);
        efeitos[i] = NULL;
    }

    SDL_DestroyWindow(janela);
    janela = NULL;
    SDL_DestroyRenderer(render);
    render = NULL;
    TTF_CloseFont(font);
    font = NULL;

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    std::cout << "Jogo fechado" << std::endl;
}

void Jogo::update() {
    if (ganhou) {
      SDL_Delay(5000);
      turnOff();
    }
    if (perdeu) {
      SDL_Delay(5000);
      turnOff();
    }
    static int cont = 0;
    static int cont2 = 0;
    static int cont_mov = 0;
    SDL_Surface* temp;
    cont_mov += 1;
    if (cont_mov % 200 == 0) {
        cont_mov -= 200;
        Jogo::movimentacao();
    }
    //  Pega os valores dos recursos do jogador e transforma em texturas
    SDL_DestroyTexture(texturas[RECURSO_DINHEIRO_PLAYER]);
    temp = TTF_RenderText_Solid
            (font, std::to_string(jogador->getDinheiro()).c_str(), cRecurso);
    texturas[RECURSO_DINHEIRO_PLAYER] =
            SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);

    SDL_DestroyTexture(texturas[RECURSO_CELULOSE_PLAYER]);
    temp = TTF_RenderText_Solid
            (font, std::to_string(jogador->getCelulose()).c_str(), cRecurso);
    texturas[RECURSO_CELULOSE_PLAYER] =
            SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);

    // Recurso Pedregulho Player
    SDL_DestroyTexture(texturas[RECURSO_PEDREGULHO_PLAYER]);
    temp = TTF_RenderText_Solid
            (font, std::to_string(jogador->getPedregulho()).c_str(), cRecurso);
    texturas[RECURSO_PEDREGULHO_PLAYER] =
            SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);

    // Recurso Metal Player
    SDL_DestroyTexture(texturas[RECURSO_METAL_PLAYER]);
    temp = TTF_RenderText_Solid
            (font, std::to_string(jogador->getMetal()).c_str(), cRecurso);
    texturas[RECURSO_METAL_PLAYER] =
            SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);
    //  Pega os valores dos recursos da cpu e transforma em texturas
    SDL_DestroyTexture(texturas[RECURSO_DINHEIRO_CPU]);
    temp = TTF_RenderText_Solid
            (font, std::to_string(cpu->getDinheiro()).c_str(), cRecurso);
    texturas[RECURSO_DINHEIRO_CPU] =
            SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);

    SDL_DestroyTexture(texturas[RECURSO_CELULOSE_CPU]);
    temp = TTF_RenderText_Solid
            (font, std::to_string(cpu->getCelulose()).c_str(), cRecurso);
    texturas[RECURSO_CELULOSE_CPU] =
            SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);

    // Recurso Pedra CPU
    SDL_DestroyTexture(texturas[RECURSO_PEDREGULHO_CPU]);
    temp = TTF_RenderText_Solid
            (font, std::to_string(cpu->getPedregulho()).c_str(), cRecurso);
    texturas[RECURSO_PEDREGULHO_CPU] =
            SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);

    SDL_DestroyTexture(texturas[RECURSO_METAL_CPU]);
    temp = TTF_RenderText_Solid
            (font, std::to_string(cpu->getMetal()).c_str(), cRecurso);
    texturas[RECURSO_METAL_CPU] = SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);

    static int it = 0;
    if (it == 60) {
        SDL_DestroyTexture(texturas[TEMPO]);
        temp = TTF_RenderText_Solid(font, tempo_val.c_str(), cRecurso);
        texturas[TEMPO] = SDL_CreateTextureFromSurface(render, temp);
        tempoPP(&tempo_val);
        SDL_FreeSurface(temp);
        it = 0;
    } else {
        it++;
    }
    if (!menu_inicial) {
        if (cont != 10) {
            cont++;
            cont2++;
        } else {
            jogador->setDinheiro(jogador->getDinheiro() + 1);
            jogador->atualizar_Recursos();

            cpu->setDinheiro(cpu->getDinheiro() + 1);
            cpu->atualizar_Recursos_CPU();
            cont = 0;
            cont2++;
        }
        if (cont2 == 20) {
            // jogador->atualizar_Recursos();
            cont2 = 0;
        }
    }

    recursoDinheiroJogador->mudaTextura(texturas[RECURSO_DINHEIRO_PLAYER]);
    recursoCeluloseJogador->mudaTextura(texturas[RECURSO_CELULOSE_PLAYER]);
    recursoPedregulhoJogador->mudaTextura(texturas[RECURSO_PEDREGULHO_PLAYER]);
    recursoMetalJogador->mudaTextura(texturas[RECURSO_METAL_PLAYER]);
    recursoDinheiroCpu->mudaTextura(texturas[RECURSO_DINHEIRO_CPU]);
    recursoCeluloseCpu->mudaTextura(texturas[RECURSO_CELULOSE_CPU]);
    recursoPedregulhoCpu->mudaTextura(texturas[RECURSO_PEDREGULHO_CPU]);
    recursoMetalCpu->mudaTextura(texturas[RECURSO_METAL_CPU]);
    tempo_Obj->mudaTextura(texturas[TEMPO]);

    // sTempo.clear();
    // sTempo.push_back(tempo);
    // SDL_Surface* textSurface =
    // TTF_RenderText_Solid( font, .c_str(), textColor );

    Jogo::bota_no_mapa();
    Jogo::clear_ultima_acao();
}

bool Jogo::loadMidia() {
    // Loading success flag
    bool success = true;

    // Load Chunk
    efeitos[EXPLOSAO] = Mix_LoadWAV("music/explosao.wav");
    if (efeitos[EXPLOSAO] == NULL) {
        printf("Failed to load Chunk explosao.wav!\n");
        success = false;
    }

    efeitos[SOCO] = Mix_LoadWAV("music/soco.wav");
    if (efeitos[SOCO] == NULL) {
        printf("Failed to load Chunk Soco.wav!\n");
        success = false;
    }

    efeitos[LUGAR_INV] = Mix_LoadWAV("music/lugar_inv.wav");
    if (efeitos[LUGAR_INV] == NULL) {
        printf("Failed to load Chunk lugar_inv.wav!\n");
        success = false;
    }

    efeitos[SEM_DINHEIRO] = Mix_LoadWAV("music/sem_dinheiro.wav");
    if (efeitos[SEM_DINHEIRO] == NULL) {
        printf("Failed to load Chunk sem_dinheiro.wav!\n");
        success = false;
    }

    efeitos[SEM_RECURSO] = Mix_LoadWAV("music/sem_recurso.wav");
    if (efeitos[SEM_RECURSO] == NULL) {
        printf("Failed to load Chunk sem_recurso.wav!\n");
        success = false;
    }
    // Load Music
    musicas[MUS_INICIAL] = Mix_LoadMUS("music/SweetDreamsLoops.wav");
    if (musicas[MUS_INICIAL] == NULL) {
        printf("Failed to load Musica Sweet.wav!\n");
        success = false;
    }

    musicas[MUS_JOGO_NARUTO] = Mix_LoadMUS("music/Naruto.mp3");
    if (musicas[MUS_JOGO_NARUTO] == NULL) {
        printf("Failed to load Musica Naruto.mp3!\n");
        success = false;
    }

    // Load PNG texture
    texturas[TEXTURAS::TROPA_PAPEL] =
            loadTexture("imagens/papel-Vida.png");
    if ( texturas[TEXTURAS::TROPA_PAPEL] == NULL ) {
        printf("Failed to load texture papel-Vida.png!\n");
        success = false;
    }

    texturas[TEXTURAS::TROPA_PAPEL_CPU] =
            loadTexture("imagens/papel_cpu-Vida.png");
    if ( texturas[TEXTURAS::TROPA_PAPEL] == NULL ) {
        printf("Failed to load texture papel_cpu-Vida.png!\n");
        success = false;
    }

    texturas[TEXTURAS::TROPA_PEDRA] =
            loadTexture("imagens/pedra-Vida.png");
    if ( texturas[TEXTURAS::TROPA_PEDRA] == NULL ) {
        printf("Failed to load texture pedra-Vida.png!\n");
        success = false;
    }

    texturas[TEXTURAS::TROPA_PEDRA_CPU] =
            loadTexture("imagens/pedra_cpu-Vida.png");
    if ( texturas[TEXTURAS::TROPA_PEDRA] == NULL ) {
        printf("Failed to load texture pedra_cpu-Vida.png!\n");
        success = false;
    }

    texturas[TEXTURAS::TROPA_TESOURA] =
            loadTexture("imagens/tesoura-Vida.png");
    if ( texturas[TEXTURAS::TROPA_TESOURA] == NULL ) {
        printf("Failed to load texture tesoura-Vida.png!\n");
        success = false;
    }

    texturas[TEXTURAS::TROPA_TESOURA_CPU] =
            loadTexture("imagens/tesoura_cpu-Vida.png");
    if ( texturas[TEXTURAS::TROPA_TESOURA] == NULL ) {
        printf("Failed to load texture tesoura_cpu-Vida-Vida.png!\n");
        success = false;
    }

    texturas[TEXTURAS::TROPA_PAPEL2] =
            loadTexture("imagens/aviao_de_papel-Vida.png");
    if ( texturas[TEXTURAS::TROPA_PAPEL2] == NULL ) {
        printf("Failed to load texture aviao_de_papel-Vida.png!\n");
        success = false;
    }

    texturas[TEXTURAS::TROPA_PAPEL2_CPU] =
            loadTexture("imagens/aviao_de_papel_cpu-Vida.png");
    if ( texturas[TEXTURAS::TROPA_PAPEL2] == NULL ) {
        printf("Failed to load texture aviao_de_papel_cpu-Vida.png!\n");
        success = false;
    }

    texturas[TEXTURAS::TROPA_PEDRA2] =
            loadTexture("imagens/Golem_de_pedra-Vida.png");
    if ( texturas[TEXTURAS::TROPA_PEDRA2] == NULL ) {
        printf("Failed to load texture Golem_de_pedra-Vida.png!\n");
        success = false;
    }

    texturas[TEXTURAS::TROPA_PEDRA2_CPU] =
            loadTexture("imagens/golem_de_pedra_cpu-Vida.png");
    if ( texturas[TEXTURAS::TROPA_PEDRA2] == NULL ) {
        printf("Failed to load texture Golem_de_pedra-Vida.png!\n");
        success = false;
    }

    texturas[TEXTURAS::TROPA_TESOURA2] =
            loadTexture("imagens/katana-Vida.png");
    if ( texturas[TEXTURAS::TROPA_TESOURA2] == NULL ) {
        printf("Failed to load texture katana-Vida.png!\n");
        success = false;
    }

    texturas[TEXTURAS::TROPA_TESOURA2_CPU] =
            loadTexture("imagens/katana_cpu-Vida.png");
    if ( texturas[TEXTURAS::TROPA_TESOURA2] == NULL ) {
        printf("Failed to load texture katana_cpu-Vida.png!\n");
        success = false;
    }

    texturas[TEXTURAS::FABRICA_PAPEL] =
            loadTexture("imagens/GeraTropaPapel-Vida.png");
    if ( texturas[TEXTURAS::FABRICA_PAPEL] == NULL ) {
        printf("Failed to load texture GeraTropaPapel-Vida.png!\n");
        success = false;
    }

    texturas[TEXTURAS::FABRICA_PAPEL_UP] =
        loadTexture("imagens/GeraTropaPapelU-Vida.png");
    if ( texturas[TEXTURAS::FABRICA_PAPEL_UP] == NULL ) {
        printf("Failed to load texture GeraTropaPapelUp.png!\n");
        success = false;
    }

    texturas[TEXTURAS::FABRICA_PEDRA] =
            loadTexture("imagens/GeraTropaPedra-Vida.png");
    if ( texturas[TEXTURAS::FABRICA_PEDRA] == NULL ) {
        printf("Failed to load texture GeraTropaPedra-Vida.png!\n");
        success = false;
    }

    texturas[TEXTURAS::FABRICA_PEDRA_UP] =
         loadTexture("imagens/GeraTropaPedraU-Vida.png");
    if ( texturas[TEXTURAS::FABRICA_PEDRA_UP] == NULL ) {
        printf("Failed to load texture GeraTropaPedraUp.png!\n");
        success = false;
    }

    texturas[TEXTURAS::FABRICA_TESOURA] =
          loadTexture("imagens/GeraTropaTesoura-Vida.png");
    if ( texturas[TEXTURAS::FABRICA_TESOURA] == NULL ) {
        printf("Failed to load texture GeraTropaTesoura-Vida.png!\n");
        success = false;
    }

    texturas[TEXTURAS::FABRICA_TESOURA_UP] =
           loadTexture("imagens/GeraTropaTesouraU-Vida.png");
    if ( texturas[TEXTURAS::FABRICA_TESOURA_UP] == NULL ) {
        printf("Failed to load texture GeraTropaTesouraUp.png!\n");
        success = false;
    }

    texturas[TEXTURAS::GERAR_PAPEL] =
            loadTexture("imagens/Gerador_Madeira-Vida.png");
    if ( texturas[TEXTURAS::GERAR_PAPEL] == NULL ) {
        printf("Failed to load texture Gerador_Madeira.png!\n");
        success = false;
    }

    texturas[TEXTURAS::GERAR_PAPEL_UP] =
            loadTexture("imagens/Gerador_MadeiraU-Vida.png");
    if ( texturas[TEXTURAS::GERAR_PAPEL_UP] == NULL ) {
        printf("Failed to load texture Gerador_Madeira_Upgrade.png!\n");
        success = false;
    }

    texturas[TEXTURAS::GERAR_PEDRA] =
            loadTexture("imagens/Gerador_Pedra-Vida.png");
    if ( texturas[TEXTURAS::GERAR_PEDRA] == NULL ) {
        printf("Failed to load texture Gerador_Pedra-Vida.png!\n");
        success = false;
    }

    texturas[TEXTURAS::GERAR_PEDRA_UP] =
            loadTexture("imagens/Gerador_PedraU-Vida.png");
    if ( texturas[TEXTURAS::GERAR_PEDRA] == NULL ) {
        printf("Failed to load texture Gerador_PedraU-Vida.png!\n");
        success = false;
    }

    texturas[TEXTURAS::GERAR_TESOURA] =
            loadTexture("imagens/Gerador_Metal-Vida.png");
    if ( texturas[TEXTURAS::GERAR_TESOURA] == NULL ) {
        printf("Failed to load texture Gerador_Metal-Vida.png!\n");
        success = false;
    }

    texturas[TEXTURAS::GERAR_TESOURA_UP] =
            loadTexture("imagens/Gerador_MetalU-Vida.png");
    if ( texturas[TEXTURAS::GERAR_TESOURA_UP] == NULL ) {
        printf("Failed to load texture Gerador_Metal.png!\n");
        success = false;
    }

    texturas[TEXTURAS::BASE_PLAYER] =
            loadTexture("imagens/castelo_azul.png");
    if ( texturas[TEXTURAS::BASE_PLAYER] == NULL ) {
        printf("Failed to load texture castelo_azul.png!\n");
        success = false;
    }

    texturas[TEXTURAS::BASE_CPU] =
            loadTexture("imagens/castelo_vermelho.png");
    if ( texturas[TEXTURAS::BASE_CPU] == NULL ) {
        printf("Failed to load texture castelo_vermelho.png!\n");
        success = false;
    }

    texturas[TEXTURAS::MENU_PRINCIPAL] =
            loadTexture("imagens/menu_inicial.png");
    if ( texturas[TEXTURAS::MENU_PRINCIPAL] == NULL ) {
        printf("Failed to load texture menu_inicial.png!\n");
        success = false;
    }

    texturas[TEXTURAS::BOTAO_INICIAR] =
            loadTexture("imagens/botao_iniciar.png");
    if ( texturas[TEXTURAS::BOTAO_INICIAR] == NULL ) {
        printf("Failed to load texture bota1.png!\n");
        success = false;
    }

    texturas[TEXTURAS::BOTAO_INICIAR_SOBRE] =
            loadTexture("imagens/botao_iniciar_sobre.png");
    if ( texturas[TEXTURAS::BOTAO_INICIAR_SOBRE] == NULL ) {
        printf("Failed to load texture botao_inciar_sobre.png!\n");
        success = false;
    }

    texturas[TEXTURAS::BOTAO_INICIAR_CLICK] =
            loadTexture("imagens/botao_init_click.png");
    if ( texturas[TEXTURAS::BOTAO_INICIAR_CLICK] == NULL ) {
        printf("Failed to load texture botao_iniciar_click.png!\n");
        success = false;
    }

    texturas[TEXTURAS::BOTAO_PAUSE] =
            loadTexture("imagens/botao_pause.png");
    if ( texturas[TEXTURAS::BOTAO_PAUSE] == NULL ) {
        printf("Failed to load texture botao_pause.png!\n");
        success = false;
    }
    texturas[TEXTURAS::BOTAO_PAUSE_SOBRE] =
            loadTexture("imagens/botao_pause_sobre.png");
    if ( texturas[TEXTURAS::BOTAO_PAUSE_SOBRE] == NULL ) {
        printf("Failed to load texture botao_pause_sobre.png!\n");
        success = false;
    }
    texturas[TEXTURAS::BOTAO_PAUSE_CLICK] =
            loadTexture("imagens/botao_pause_click.png");
    if ( texturas[TEXTURAS::BOTAO_PAUSE_CLICK] == NULL ) {
        printf("Failed to load texture botao_pause_click.png!\n");
        success = false;
    }

    texturas[TEXTURAS::BOTAO_RESUME] =
            loadTexture("imagens/botao_resume.png");
    if ( texturas[TEXTURAS::BOTAO_RESUME] == NULL ) {
        printf("Failed to load texture botao_resume.png!\n");
        success = false;
    }

    texturas[TEXTURAS::BOTAO_RESUME_SOBRE] =
            loadTexture("imagens/botao_resume_sobre.png");
    if ( texturas[TEXTURAS::BOTAO_RESUME_SOBRE] == NULL ) {
        printf("Failed to load texture botao_resume_sobre.png!\n");
        success = false;
    }

    texturas[TEXTURAS::BOTAO_RESUME_CLICK] =
            loadTexture("imagens/botao_resume_click.png");
    if ( texturas[TEXTURAS::BOTAO_RESUME_CLICK] == NULL ) {
        printf("Failed to load texture botao_resume_click.png!\n");
        success = false;
    }

    //  Carrega as texturas do botao sair
    texturas[TEXTURAS::BOTAO_SAIR] =
            loadTexture("imagens/botao_sair.png");
    if ( texturas[TEXTURAS::BOTAO_SAIR] == NULL ) {
        printf("Failed to load texture botao_sair.png!\n");
        success = false;
    }
    texturas[TEXTURAS::BOTAO_SAIR_SOBRE] =
            loadTexture("imagens/botao_sair_sobre.png");
    if ( texturas[TEXTURAS::BOTAO_SAIR_SOBRE] == NULL ) {
        printf("Failed to load texture botao_sair_sobre.png!\n");
        success = false;
    }
    texturas[TEXTURAS::BOTAO_SAIR_CLICK] =
            loadTexture("imagens/botao_sair_click.png");
    if (texturas[TEXTURAS::BOTAO_SAIR_CLICK] == NULL) {
        printf("Failed to load texture botao_sair_click.png!\n");
        success = false;
    }

    texturas[TEXTURAS::BOTAO_LOAD] =
            loadTexture("imagens/botao_load.png");
    if (texturas[TEXTURAS::BOTAO_LOAD] == NULL) {
        printf("Failed to load texture botao_load.png!\n");
        success = false;
    }
    texturas[TEXTURAS::BOTAO_LOAD_SOBRE] =
            loadTexture("imagens/botao_load_sobre.png");
    if (texturas[TEXTURAS::BOTAO_LOAD_SOBRE] == NULL) {
        printf("Failed to load texture botao_load_sobre.png!\n");
        success = false;
    }
    texturas[TEXTURAS::BOTAO_LOAD_CLICK] =
            loadTexture("imagens/botao_load_click.png");
    if (texturas[TEXTURAS::BOTAO_LOAD_CLICK] == NULL) {
        printf("Failed to load texture botao_load_click.png!\n");
        success = false;
    }

    texturas[TEXTURAS::BOTAO_SAVE] =
            loadTexture("imagens/botao_save.png");
    if (texturas[TEXTURAS::BOTAO_SAVE] == NULL) {
        printf("Failed to load texture botao_save.png!\n");
        success = false;
    }
    texturas[TEXTURAS::BOTAO_SAVE_SOBRE] =
            loadTexture("imagens/botao_save_sobre.png");
    if (texturas[TEXTURAS::BOTAO_SAVE_SOBRE] == NULL) {
        printf("Failed to load texture botao_save_sobre.png!\n");
        success = false;
    }

    texturas[TEXTURAS::VITORIA] = loadTexture("imagens/vitoria.png");
    if (texturas[TEXTURAS::VITORIA] == NULL) {
        printf("Failed to load texture vitoria.png!\n");
        success = false;
    }

    texturas[TEXTURAS::DERROTA] = loadTexture("imagens/derrota.png");
    if (texturas[TEXTURAS::DERROTA] == NULL) {
        printf("Failed to load texture derrota.png!\n");
        success = false;
    }

    texturas[TEXTURAS::MAPA] = loadTexture("imagens/Mapa.png");
    if (texturas[TEXTURAS::MAPA] == NULL) {
        printf("Failed to load texture Mapa.png!\n");
        success = false;
    }
    font = TTF_OpenFont("fonts/04B_08__.TTF", 28);

    // derrota
    derrota->mudaTextura(texturas[DERROTA]);
    derrota->setSrcRect(0, 0, 700, 360);
    derrota->setDestRect(310, 150, 700, 360);
    // VITORIA
    vitoria->mudaTextura(texturas[VITORIA]);
    vitoria->setSrcRect(0, 0, 700, 360);
    vitoria->setDestRect(310, 150, 700, 360);
    // Botao Iniciar
    bIniciar->mudaTextura(texturas[BOTAO_INICIAR]);
    bIniciar->setDestRect(460, 240, 300, 120);
    bIniciar->setSrcRect(0, 0, 300, 120);

    // Menu Principal
    menuInicial->mudaTextura(texturas[MENU_PRINCIPAL]);
    menuInicial->setDestRect(0, 0, 1280, 720);
    menuInicial->setSrcRect(0, 0, 1280, 720);

    // Mapa
    mapa->mudaTextura(texturas[MAPA]);
    mapa->setSrcRect(0, 0, 1280, 720);
    mapa->setDestRect(0, 0, 1280, 720);

    //  Botao Sair
    bSair->mudaTextura(texturas[BOTAO_SAIR]);
    bSair->setSrcRect(0, 0, 300, 120);
    bSair->setDestRect(460, 520, 300, 120);


    // recurso->mudaTextura(texturas[TEXTO_RECURSO]);
    // recursoDinheiroJogador->mudaTextura(texturas[TEXTO_RECURSO]);
    recursoDinheiroJogador->setSrcRect(0, 0, 100, 64);
    recursoDinheiroJogador->setDestRect(235, 20, 80, 60);
    // recursoCeluloseJogador->mudaTextura(texturas[TEXTO_RECURSO]);
    recursoCeluloseJogador->setSrcRect(0, 0, 100, 64);
    recursoCeluloseJogador->setDestRect(400, 80, 80, 60);
    // recursoPedregulhoJogador->mudaTextura(texturas[TEXTO_RECURSO]);
    recursoPedregulhoJogador->setSrcRect(0, 0, 100, 64);
    recursoPedregulhoJogador->setDestRect(235, 80, 80, 60);
    // recursoMetalJogador->mudaTextura(texturas[TEXTO_RECURSO]);
    recursoMetalJogador->setSrcRect(0, 0, 100, 64);
    recursoMetalJogador->setDestRect(400, 20, 80, 60);
    // recursoDinheiroCpu->mudaTextura(texturas[TEXTO_RECURSO]);
    recursoDinheiroCpu->setSrcRect(0, 0, 100, 64);
    recursoDinheiroCpu->setDestRect(875, 20, 80, 60);
    // recursoCeluloseCpu->mudaTextura(texturas[TEXTO_RECURSO]);
    recursoCeluloseCpu->setSrcRect(0, 0, 100, 64);
    recursoCeluloseCpu->setDestRect(1040, 80, 80, 60);
    // recursoPedregulhoCpu->mudaTextura(texturas[TEXTO_RECURSO]);
    recursoPedregulhoCpu->setSrcRect(0, 0, 100, 64);
    recursoPedregulhoCpu->setDestRect(875, 80, 80, 60);
    // recursoMetalCpu->mudaTextura(texturas[TEXTO_RECURSO]);
    recursoMetalCpu->setSrcRect(0, 0, 100, 64);
    recursoMetalCpu->setDestRect(1040, 20, 80, 60);

    // Botao Pause
    pause->mudaTextura(texturas[BOTAO_PAUSE]);
    pause->setSrcRect(0, 0, 64, 64);
    pause->setDestRect(0, 0, 80, 60);
    // Botao Resume
    resume->mudaTextura(texturas[BOTAO_RESUME]);
    resume->setSrcRect(0, 0, 64, 64);
    resume->setDestRect(80, 0, 80, 60);
    // Menu Inicial

    // Botao Load
    bLoad->mudaTextura(texturas[BOTAO_LOAD]);
    bLoad->setSrcRect(0, 0, 300, 120);
    bLoad->setDestRect(460, 380, 300, 120);

    //  Botao Salvar
    bSalvar->mudaTextura(texturas[BOTAO_SAVE]);
    bSalvar->setSrcRect(0, 0, 64, 64);
    bSalvar->setDestRect(0, 64, 80, 60);

    // Iniciando a string do tempo os rects do objeto
    tempo_val = ("00:00");
    tempo_Obj->setSrcRect(0, 0, 100, 64);
    tempo_Obj->setDestRect(560, 32, 160, 100);

    return success;
}

SDL_Texture* Jogo::loadTexture(const char* nome) {
    SDL_Texture* novaTextura = NULL;
    SDL_Surface* surfaceTmp = IMG_Load(nome);

    if (surfaceTmp == NULL) {
        printf("Não foi possível carregar a imagem %s! SDL_image Error: %s\n",
                nome, IMG_GetError() );
    } else {
        novaTextura = SDL_CreateTextureFromSurface(render, surfaceTmp);
        if (novaTextura == NULL) {
            printf("Unable to create texture from %s! SDL Error: %s\n",
                    nome, SDL_GetError());
        }
        SDL_FreeSurface(surfaceTmp);
    }
    return novaTextura;
}

void tempoPP(std::string* string) {
    if (string->at(4) < '9') {
        string->at(4)++;
    } else {
        string->at(4) -= 9;
        if (string->at(3) < '5') {
            string->at(3)++;
        } else {
            string->at(3) -= 5;
            if (string->at(1) < '9') {
                string->at(1)++;
            } else {
                string->at(1) -= 9;
                string->at(0)++;
            }
        }
    }
}

void Jogo::loadInfoPlayer(FILE* arq) {
    char aux[60];
    fscanf(arq, "%[^\n]s", aux);  // Recebe a divisao do Player1
    fgetc(arq);
    fscanf(arq, "%[^\n]s", aux);
    jogador->setVida(atoi(aux));
    fgetc(arq);
    fscanf(arq, "%[^\n]s", aux);
    jogador->setPedregulho(atoi(aux));
    fgetc(arq);
    fscanf(arq, "%[^\n]s", aux);
    jogador->setCelulose(atoi(aux));
    fgetc(arq);
    fscanf(arq, "%[^\n]s", aux);
    jogador->setMetal(atoi(aux));
    fgetc(arq);
    fscanf(arq, "%[^\n]s", aux);
    jogador->setDinheiro(atoi(aux));
    fgetc(arq);
    fscanf(arq, "%[^\n]s", aux);
    jogador->setPontos(atoi(aux));
    fgetc(arq);
}

void Jogo::loadInfoCPU(FILE* arq) {
    char aux[60];
    fscanf(arq, "%[^\n]s", aux);  // Recebe a divisao do Player2
    fgetc(arq);
    fscanf(arq, "%[^\n]s", aux);
    cpu->setVida(atoi(aux));
    fgetc(arq);
    fscanf(arq, "%[^\n]s", aux);
    cpu->setPedregulho(atoi(aux));
    fgetc(arq);
    fscanf(arq, "%[^\n]s", aux);
    cpu->setCelulose(atoi(aux));
    fgetc(arq);
    fscanf(arq, "%[^\n]s", aux);
    cpu->setMetal(atoi(aux));
    fgetc(arq);
    fscanf(arq, "%[^\n]s", aux);
    cpu->setDinheiro(atoi(aux));
    fgetc(arq);
    fscanf(arq, "%[^\n]s", aux);
    cpu->setPontos(atoi(aux));
    fgetc(arq);
}

void Jogo::load() {
    printf("Loading Game...\n");
    FILE* arq = fopen("saves/save.txt", "r");
    char aux[30];
    int x, y, vida, nivel, tipo, taxa, velocidade, dano;
    if (arq != NULL) {
        // Load no tempo do jogo
        fscanf(arq, "%[^\n]s", aux);
        //Jogo::tempo_val = (std::string) aux;
        fgetc(arq);
        // Load nas informacoes dos jogador
        Jogo::loadInfoPlayer(arq);
        Jogo::loadInfoCPU(arq);
        // Load nas matrizes da classe jogo
        fscanf(arq, "%[^\n]s", aux);  // Divao Matriz gera Recuso
        fgetc(arq);
        while (!feof(arq) && fgetc(arq) != '#') {
            fscanf(arq, "%d %d %d %d %d %d", &x, &y, &vida, &nivel, &tipo, &taxa);
            printf("%d %d %d %d %d %d\n", x, y, vida, nivel, tipo, taxa);
            Jogo::matriz_geraRecurso[x][y] = new GeraRecursos(x, y, tipo);
            Jogo::matriz_geraRecurso[x][y]->setNivel(nivel);
            Jogo::matriz_geraRecurso[x][y]->set_vida(vida);
            Jogo::matriz_geraRecurso[x][y]->setTaxa(taxa);
            Jogo::matriz_geraRecurso[x][y]->setDestRect
                    ((y + 2) * 80, (x + 2) * 72, 64, 64);
            Jogo::matriz_geraRecurso[x][y]->setSrcRect(0, 0, 64, 64);
            Jogo::matriz_geraRecurso[x][y]->mudaTextura
                    (Jogo::texturas[retorna_textura_recurso(tipo)]);
            fgetc(arq);
        }
        fscanf(arq, "%[^\n]s", aux);  // Divao Matriz fabrica
        fgetc(arq);
        while (!feof(arq) && fgetc(arq) != '#') {
            fscanf(arq, "%d %d %d %d %d", &x, &y, &vida, &nivel, &tipo);
            printf("%d %d %d %d %d\n", x, y, vida, nivel, tipo);
            Jogo::matriz_fabrica[x][y] = new Fabrica(x, y, tipo);
            Jogo::matriz_fabrica[x][y]->set_nivel(nivel);
            Jogo::matriz_fabrica[x][y]->set_vida(vida);
            Jogo::matriz_fabrica[x][y]->setDestRect
                    ((y + 2) * 80, (x + 2) * 72, 64, 64);
            Jogo::matriz_fabrica[x][y]->setSrcRect(0, 0, 64, 64);
            Jogo::matriz_fabrica[x][y]->mudaTextura
                    (Jogo::texturas[retorna_textura_fabrica(tipo)]);
            fgetc(arq);
        }
        fscanf(arq, "%[^\n]s", aux);  // Divao Matriz unidades
        fgetc(arq);
        while (!feof(arq) && fgetc(arq) != '#') {
            fscanf(arq, "%d %d %d %d %d %d %d",
                   &x, &y, &tipo, &vida, &velocidade, &dano, &nivel);
            printf("%d %d %d %d %d %d %d \n",
                    x, y, tipo, vida, velocidade, dano, nivel);
            Jogo::matriz_unidade[x][y] =
                    new Unidade(x, y, tipo, vida, velocidade, dano, nivel);
            Jogo::matriz_unidade[x][y]->setDestRect
                    ((y + 2) * 80, (x + 2) * 72, 64, 64);
            Jogo::matriz_unidade[x][y]->setSrcRect(0, 0, 64, 64);
            Jogo::matriz_unidade[x][y]->mudaTextura
                    (Jogo::texturas[retorna_textura_unidade(nivel, tipo)]);
            fgetc(arq);
        }
        fclose(arq);
    } else {
        printf("Sem Saves disponiveis");
    }
}

void Jogo::save() {
    FILE* arq = fopen("saves/save.txt", "w+");
    fprintf(arq, "%s\n", Jogo::tempo_val.c_str());  // Convertar para string
    fprintf(arq, "#----------Info do Player1----------\n");
    fprintf(arq, "%d\n", jogador->getVida());
    fprintf(arq, "%d\n", jogador->getPedregulho());
    fprintf(arq, "%d\n", jogador->getCelulose());
    fprintf(arq, "%d\n", jogador->getMetal());
    fprintf(arq, "%d\n", jogador->getDinheiro());
    fprintf(arq, "%d\n", jogador->getPontos());
    fprintf(arq, "#---------Info do Player2(CPU)-------\n");
    fprintf(arq, "%d\n", cpu->getVida());
    fprintf(arq, "%d\n", cpu->getPedregulho());
    fprintf(arq, "%d\n", cpu->getCelulose());
    fprintf(arq, "%d\n", cpu->getMetal());
    fprintf(arq, "%d\n", cpu->getDinheiro());
    fprintf(arq, "%d\n", cpu->getPontos());
    fprintf(arq, "#-----------Matriz gera Recurso-------\n");
    for (int i=0; i< 6; i++) {
        for (int j =0; j < 12; j ++) {
            if (matriz_geraRecurso[i][j] != NULL) {
                fprintf(arq, "-%d %d ", i, j);
                fprintf(arq, "%d ", matriz_geraRecurso[i][j]->get_vida());
                fprintf(arq, "%d ", matriz_geraRecurso[i][j]->getNivel());
                fprintf(arq, "%d ", matriz_geraRecurso[i][j]->getTipo());
                fprintf(arq, "%d\n", matriz_geraRecurso[i][j]->getTaxa());
            }
        }
    }
    fprintf(arq, "#-----------Matriz fabrica------------\n");
    for (int i=0; i< 6; i++) {
        for (int j =0; j < 12; j ++) {
            if (matriz_fabrica[i][j] != NULL) {
                fprintf(arq, "-%d %d ", i, j);
                fprintf(arq, "%d ", matriz_fabrica[i][j]->get_vida());
                fprintf(arq, "%d ", matriz_fabrica[i][j]->get_nivel());
                fprintf(arq, "%d\n", matriz_fabrica[i][j]->getTipo());
            }
        }
    }
    fprintf(arq, "#-----------Matriz unidades-----------\n");
    for (int i=0; i< 6; i++) {
        for (int j =0; j < 12; j ++) {
            if (matriz_unidade[i][j] != NULL) {
                fprintf(arq, "-%d %d ", i, j);
                fprintf(arq, "%d ", matriz_unidade[i][j]->getTipo());
                fprintf(arq, "%d ", matriz_unidade[i][j]->getVida());
                fprintf(arq, "%d ", matriz_unidade[i][j]->getVelocidade());
                fprintf(arq, "%d ", matriz_unidade[i][j]->getDano());
                fprintf(arq, "%d\n", matriz_unidade[i][j]->getNivel());
            }
        }
    }
    fprintf(arq, "#---------------Fim-------------------");
    fclose(arq);
}

// ------------------ Funções da CPU -----------------------------------------

void Jogo::clear_ultima_acao() {
    for (int i = 0; i < 16; i++) {
        Jogo::ultima_acao.last[i] = false;
    }
    Jogo::ultima_acao.ondeX = -1;
    Jogo::ultima_acao.ondeY = -1;
}

int Jogo::counter(bool* ultima_compra) {
    for (int i = 0; i < 16; i++) {
        if (ultima_compra[i] == true) {
            if (i == 0) {
                return 0;
            } else if (i%3 == 0 || i%3 == 2) {
                return (i-1);
            } else {
                return (i+2);
            }
        }
    }
}

UNIDADE Jogo::retorna_tipo_und(int acao) {
    if (acao%3 == 0) {
        return TESOURA;
    } else if (acao%3 == 2) {
        return PEDRA;
    } else {
        return PAPEL;
    }
}

RECURSO Jogo::retorna_tipo_rec(int acao) {
    if (acao%3 == 0) {
        return METAL;
    } else if (acao%3 == 2) {
        return PEDREGULHO;
    } else {
        return CELULOSE;
    }
}

int Jogo::max_index(int* vector, int n) {
    if (n <= 0) return -1;
    int i, max_i = 0;
    int max = vector[0];
    for (i = 1; i < n; i++) {
        if (vector[i] > max) {
            max = vector[i];
            max_i = i;
            }
        }
    return max_i;
}

int Jogo::qual_fbrc(UNIDADE tipo) {
    int hist_fab[6] = {0};
    int onde;
    for (int col = 0; col < 6; col++) {
        if (Jogo::matriz_fabrica[col][10] != NULL) {
            switch (tipo) {
                case UNIDADE::PAPEL:
                    if (Jogo::matriz_fabrica[col][10]->
                    custo_unidade <= cpu->getCelulose()) {
                        hist_fab[col] += 1;
                        hist_fab[col] +=
                         Jogo::matriz_fabrica[col][10]->get_nivel();
                    }
                    break;
                case UNIDADE::PEDRA:
                    if (Jogo::matriz_fabrica[col][10]->
                    custo_unidade <= cpu->getPedregulho()) {
                        hist_fab[col] += 1;
                        hist_fab[col] +=
                         Jogo::matriz_fabrica[col][10]->get_nivel();
                    }
                    break;
                case UNIDADE::TESOURA:
                    if (Jogo::matriz_fabrica[col][10]->
                    custo_unidade <= cpu->getMetal()) {
                        hist_fab[col] += 1;
                        hist_fab[col] +=
                         Jogo::matriz_fabrica[col][10]->get_nivel();
                    }
                    break;
            }
        }
    }
    onde = Jogo::max_index(hist_fab, 6);
    return Jogo::matriz_fabrica[onde][10]->get_nivel();
}

void Jogo::menor_nivel(UNIDADE tipo, int* X, int* Y ) {
    int min_index = 0;
    int index_hist[6] = {0};
    printf("MENOR\n");
    for (int col = 0; col < 6; col++) {
        printf("LOOOOOP\n");
        if (Jogo::matriz_fabrica[col][10] != NULL) {
            switch (tipo) {
                case UNIDADE::PAPEL:
                    index_hist[col] = Jogo::matriz_fabrica[col][10]->get_nivel();
                    printf("PAPEEEL\n");
                    break;
                case UNIDADE::PEDRA:
                    printf("TOOOOOP\n");
                    index_hist[col] = Jogo::matriz_fabrica[col][10]->get_nivel();
                    break;
                case UNIDADE::TESOURA:
                    index_hist[col] = Jogo::matriz_fabrica[col][10]->get_nivel();
                    break;
            }
        } else {
            index_hist[col] = 1000;
        }
    }
    for (int i = 1; i < 6; i++) {
        if (index_hist[i] < index_hist[min_index]) {
            min_index = i;
        }
    }
    *X = Jogo::matriz_fabrica[min_index][10]->get_x();
    *Y = Jogo::matriz_fabrica[min_index][10]->get_y();
}


void Jogo::onde_botar(int* X, int* Y, int counter) {
    if (counter >= 4 && counter <= 6) {
        int posX = 11, posY = 0;
        while (jogador->verifica_espaco_ocupado(posY, posX) == false) {
            // printf("loop\n");
            if (posY == 5) {
                posY = posX = -1;
                break;
            }
            posY++;
        }
        *X = posX;
        *Y = posY;
    } else if (counter >= 7 && counter <= 9) {
        int posX = 10, posY = 0;
        while (jogador->verifica_espaco_ocupado(posY, posX) == false) {
            if (posY == 5) {
                posY = posX = -1;
                break;
            }
            posY++;
        }
        *X = posX;
        *Y = posY;
    } else if (counter >= 1 && counter <= 3) {
        int posX = 9, posY = Jogo::ultima_acao.ondeY;
        while (jogador->verifica_espaco_ocupado(posY, posX) == false) {
            if (posX == 7) {
                posX = 0;
            }
            posX++;
        }
        *X = posX;
        *Y = posY;
    } else {
        return;
    }
}

void Jogo::bota_no_mapa() {
    int counter = Jogo::counter(Jogo::ultima_acao.last);
    int nivel;
    UNIDADE tipo_und = Jogo::retorna_tipo_und(counter);
    RECURSO tipo_rec = Jogo::retorna_tipo_rec(counter);
    TEXTURAS textura;

    int X = -1, Y = -1;
    if (counter > 0 && counter < 10) {
        Jogo::onde_botar(&X, &Y, counter);
    }
    // printf("coord %d : %d\n", X, Y);

    if (counter >= 7 && counter <= 9) {
        cpu->compra_Fabrica_CPU(Y, X, tipo_und);
    } else if (counter >=4 && counter <= 6) {
        cpu->compra_GeraRecurso_CPU(Y, X, tipo_rec);
    } else if (counter >=1 && counter <= 3) {
        printf("ENTROU PORRA UND\n");
        nivel = Jogo::qual_fbrc(tipo_und);
        printf("JA TEMOS O NIVEL %d\n", nivel);
        cpu->compra_Unidade_CPU(Y, X, tipo_und, nivel);
    } else if (counter >= 13 && counter <= 15) {
        Jogo::menor_nivel(tipo_und, &X, &Y);
        printf("OPAAAAA\n");
        Jogo::matriz_fabrica[X][Y]->upgrade_fabrica(&cpu->dinheiro);
        switch (tipo_und) {
            case UNIDADE::PAPEL:
                Jogo::matriz_fabrica[X][Y]->
                mudaTextura(Jogo::texturas[FABRICA_PAPEL_UP]);
                break;
            case UNIDADE::PEDRA:
                Jogo::matriz_fabrica[X][Y]->
                mudaTextura(Jogo::texturas[FABRICA_PEDRA_UP]);
                break;
            case UNIDADE::TESOURA:
                Jogo::matriz_fabrica[X][Y]->
                mudaTextura(Jogo::texturas[FABRICA_TESOURA_UP]);
                break;
        }
    }
}

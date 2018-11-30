#include "Jogo.h"
#include "Player.h"
#include "Botao.h"
#include <iostream>
#include <stdlib.h>

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
    compra = new Botao_Compra(0, 0);

    recursoDinheiroJogador = new Objeto(0, 0);
    recursoCeluloseJogador = new Objeto(0, 0);
    recursoPedregulhoJogador = new Objeto(0, 0);
    recursoMetalJogador = new Objeto(0, 0);
    recursoDinheiroCpu = new Objeto(0, 0);
    recursoCeluloseCpu = new Objeto(0, 0);
    recursoPedregulhoCpu = new Objeto(0, 0);
    recursoMetalCpu = new Objeto(0, 0);
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

    delete bIniciar;
    bIniciar = NULL;
    delete menuInicial;
    menuInicial = NULL;
    delete mapa;
    mapa = NULL;
    delete compra;
    compra = NULL;
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
}

void ataca_base(Unidade* unidade, Player* jogador) {
    jogador->setVida(jogador->getVida() - unidade->getDano());
    printf("Atacou a base, Vida atual: %d", jogador->getVida());
    //delete unidade;
    //unidade = NULL;
    if (jogador->getVida() <= 0) {
        // Finalizar jogo
        // Jogo::isOn();
    }
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


void combate_unidade(Unidade** atacante, Unidade** defensor) {
    // Define dano de acordo com as fraquezas
    int danoAtacante = retorna_dano((*atacante), (*defensor)->getTipo());
    int danoDefensor = retorna_dano((*defensor), (*atacante)->getTipo());

    // Enquanto alguma unidade tem vida, ataca
    while ((*atacante)->getVida() > 0 && (*defensor)->getVida() > 0) {
        (*atacante)->setVida((*atacante)->getVida() - danoDefensor);
        (*defensor)->setVida((*defensor)->getVida() - danoAtacante);
    }

    // Se alguma unidade não tem vida, destrói
    if ((*defensor)->getVida() <= 0) {
        /*delete (*defensor);
        (*defensor) = NULL;*/
        printf("MORREU DEFENSOR");
    }
    if ((*atacante)->getVida() <= 0) {
        //delete (*atacante);
        //(*atacante) = NULL;
        printf("MORREU ATACANTE");
    } else {
        // Se o (*atacante) não foi destruído, anda
        anda(atacante, defensor);
    }
}

void anda(Unidade** unidade, Unidade** destino) {
    Unidade* aux;
    aux = *destino;
    *destino = *unidade;
    *unidade = aux;
}

void ataca_fabrica(Unidade* unidade1, Fabrica* fbrc1) {
    int dano = retorna_dano(unidade1, fbrc1->getTipo());
    // Unidade retira vida da fábrica
    fbrc1->set_vida(fbrc1->get_vida() - dano);
    // Unidade é destruida
    delete unidade1;
    unidade1 = NULL;
    // Se fábrica não tem vida, é destruida
    if (fbrc1->get_vida() <= 0) {
        delete fbrc1;
        fbrc1 = NULL;
    }
}

void ataca_geraRecurso(Unidade* unidade1, GeraRecursos* geradora) {
    int dano = retorna_dano(unidade1, geradora->getTipo());
    // Unidade retira vida da geradora
    geradora->set_vida(geradora->get_vida() - dano);
    // Unidade é destruida
    delete unidade1;
    unidade1 = NULL;
    // Se geradora não tem vida, é destruida
    if (geradora->get_vida() <= 0) {
        delete geradora;
        geradora = NULL;
    }
}

void Jogo::movimentacao() {
    /* Casos meio da matriz */
    for (int lin = 0; lin < 6 ; lin++) {
        /* Condicoes de atacar base principal*/
        if (Jogo::matriz_unidade[lin][11] != NULL
        && Jogo::matriz_unidade[lin][11]->getVelocidade() > 0) {
            // ataca base cpu, e despois se auto destroi
            printf("Atacou Base\n");
            ataca_base(Jogo::matriz_unidade[lin][11], cpu);
            delete(Jogo::matriz_unidade[lin][11]);
            Jogo::matriz_unidade[lin][11] = nullptr;
        }
        if (Jogo::matriz_unidade[lin][0] != NULL
        && Jogo::matriz_unidade[lin][0]->getVelocidade() < 0) {
            // ataca base player, e despois se auto destroi
            ataca_base(Jogo::matriz_unidade[lin][0], jogador);
        }

        /* Na 11 ja foi verificado, e so pode ser criado apartir da 2 os velocidade positiva */
        for (int col = 10; col >= 2; col --) {
            if (Jogo::matriz_unidade[lin][col] != NULL) {
                if (Jogo::matriz_unidade[lin][col]->getVelocidade() > 0) {
                   if (Jogo::matriz_unidade[lin][col + 1] != NULL) {
                       // ataca tropa
                       combate_unidade(&Jogo::matriz_unidade[lin][col], &Jogo::matriz_unidade[lin][col + 1]);
                   } else if (Jogo::matriz_geraRecurso[lin][col + 1] != NULL) {
                       // ataca geraRecurso
                       ataca_geraRecurso(Jogo::matriz_unidade[lin][col],
                               Jogo::matriz_geraRecurso[lin][col + 1]);
                   } else if (Jogo::matriz_fabrica[lin][col + 1] != NULL) {
                       // ataca fabrica
                       ataca_fabrica(Jogo::matriz_unidade[lin][col], Jogo::matriz_fabrica[lin][col +1]);
                   } else {
                       //*Jogo::matriz_unidade[lin][col]->srcRect = *Jogo::matriz_unidade[lin][col + 1]->srcRect;
                       Jogo::matriz_unidade[lin][col]->setDestRect((col + 2) * 80 ,(lin + 2) * 72, 64, 64);
                       //Jogo::matriz_unidade[lin][col]->srcRect->x -= 80;
                       anda(&Jogo::matriz_unidade[lin][col], &Jogo::matriz_unidade[lin][col + 1]);
                       printf("Andou de %d:%d, Para %d:%d\n", lin, col, lin , col +1);
                       // anda para direita
                   }
                } /* if velo positiva */
            } /* if != NULL*/
        } /* for col */

        /* Na 0 ja foi verificado, e so pode ser criado apartir da 9 os velocidade negativa */
        for (int col = 1; col < 9; col ++) {
            if (Jogo::matriz_unidade[lin][col] != NULL) {
                if (Jogo::matriz_unidade[lin][col]->getVelocidade() < 0) {
                    if (Jogo::matriz_unidade[lin][col - 1] != NULL) {
                        // ataca tropa
                        combate_unidade(&Jogo::matriz_unidade[lin][col], &Jogo::matriz_unidade[lin][col - 1]);
                    } else if (Jogo::matriz_geraRecurso[lin][col - 1] != NULL) {
                        // ataca geraRecurso
                        ataca_geraRecurso(Jogo::matriz_unidade[lin][col], Jogo::matriz_geraRecurso[lin][col - 1]);
                    } else if (Jogo::matriz_fabrica[lin][col - 1] != NULL) {
                        // ataca fabrica
                        ataca_fabrica(Jogo::matriz_unidade[lin][col], Jogo::matriz_fabrica[lin][col - 1]);
                    } else {
                        // anda para esquerda
                        anda(&Jogo::matriz_unidade[lin][col], &Jogo::matriz_unidade[lin][col - 1]);
                    }
                } /* if velo positiva */
            } /* if != NULL*/
        } /* for col */
    } /* for lin */

} /* Jogo::movimentacao */
void Jogo::init(const char* nome, int x, int y, int w, int h) {

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Sistema Inicializado!...." << std::endl;

        janela = SDL_CreateWindow( nome, x, y, w, h, 0);
        if (janela) {
            std::cout << "Janela criada!" << std::endl;
        }
        render = SDL_CreateRenderer(janela, -1, 0);
        if (render) {
            SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
            std::cout << "Render criado!" << std::endl;
            int imgFlags = IMG_INIT_PNG;
            if ( !( IMG_Init( imgFlags ) & imgFlags ) ) {
                printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                on = false;
            }
            if ( TTF_Init() == -1 ) {
            		printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
            		on = false;
            }
            /* Set e get depois*/
            menu_inicial = true;

            compra->mudaTipo(GERA_CELULOSE);


        }
        on = true;
    } else {
        on = false;
    }
}

bool Jogo::isOn() {
    return on;
}

void Jogo::handleEvents(){
    SDL_Event evento;
    SDL_PollEvent(&evento);
    switch(evento.type) {
        case SDL_QUIT:
            on = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
        case SDL_MOUSEMOTION:
            if (menu_inicial) {
                bIniciar->handleEvent(&evento);
                printf("aloo\n");
            } else {
                buttomEvents( &evento);
            break;
        }

        default:
            break;
    }

}

void Jogo::renderizar() {
    int cont = 0;
    SDL_RenderClear(render);
    //Adione aqui as coisas para renderizar
    if (menu_inicial) {
        menuInicial->render(render);
        bIniciar->render(render);
    } else {
        mapa->render(render);
        //compra->render(render);
        for (int i = 0;i < 6;++i) {
            for (int j = 0;j < 12; j++) {
                if (matriz_fabrica[i][j] != NULL) {
                    matriz_fabrica[i][j]->render(render);
                }
                if (matriz_geraRecurso[i][j] != NULL) {
                    matriz_geraRecurso[i][j]->render(render);
                    //printf("render %d\n",cont);
                }
                if (matriz_unidade[i][j] != NULL) {
                    matriz_unidade[i][j]->render(render);
                }
                cont++;
            }
        }
        recursoDinheiroJogador->render(render);
        recursoCeluloseJogador->render(render);
        recursoPedregulhoJogador->render(render);
        recursoMetalJogador->render(render);
        recursoDinheiroCpu->render(render);
        recursoCeluloseCpu->render(render);
        recursoPedregulhoCpu->render(render);
        recursoMetalCpu->render(render);
    }
    SDL_RenderPresent(render);
}

void Jogo::fim() {
    for (int i = 0;i < TEXTURAS::TEX_TOTAL;++i) {
        SDL_DestroyTexture(texturas[i]);
        texturas[i] = NULL;
    }
    SDL_DestroyWindow(janela);
    janela = NULL;
    SDL_DestroyRenderer(render);
    render = NULL;
    TTF_CloseFont( font );
    font = NULL;




    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    std::cout << "Jogo fechado" << std::endl;
}

void Jogo::load() {
}

void Jogo::update() {
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
    temp = TTF_RenderText_Solid(font, std::to_string(jogador->getDinheiro()).c_str(), cRecurso);
    texturas[RECURSO_DINHEIRO_PLAYER] = SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);
    temp = TTF_RenderText_Solid(font, std::to_string(jogador->getCelulose()).c_str(), cRecurso);
    texturas[RECURSO_CELULOSE_PLAYER] = SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);
    temp = TTF_RenderText_Solid(font, std::to_string(jogador->getPedregulho()).c_str(), cRecurso);
    texturas[RECURSO_PEDREGULHO_PLAYER] = SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);
    temp = TTF_RenderText_Solid(font, std::to_string(jogador->getMetal()).c_str(), cRecurso);
    texturas[RECURSO_METAL_PLAYER] = SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);
    //  Pega os valores dos recursos da cpu e transforma em texturas
    temp = TTF_RenderText_Solid(font, std::to_string(cpu->getDinheiro()).c_str(), cRecurso);
    texturas[RECURSO_DINHEIRO_CPU] = SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);
    temp = TTF_RenderText_Solid(font, std::to_string(cpu->getCelulose()).c_str(), cRecurso);
    texturas[RECURSO_CELULOSE_CPU] = SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);
    temp = TTF_RenderText_Solid(font, std::to_string(cpu->getPedregulho()).c_str(), cRecurso);
    texturas[RECURSO_PEDREGULHO_CPU] = SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);
    temp = TTF_RenderText_Solid(font, std::to_string(cpu->getMetal()).c_str(), cRecurso);
    texturas[RECURSO_METAL_CPU] = SDL_CreateTextureFromSurface(render, temp);
    SDL_FreeSurface(temp);
    if (!menu_inicial) {
        if (cont != 10) {
            cont++;
            cont2++;
        } else {
            jogador->setDinheiro(jogador->getDinheiro() + 1);
            jogador->atualizar_Recursos();
            //printf("%d---%d---%d\n",jogador->getDinheiro() ,jogador->getCelulose(), jogador->getPedregulho());

            cpu->setDinheiro(cpu->getDinheiro() + 1);
            cont = 0;
            cont2++;
        }
        if (cont2 == 20) {
            //jogador->atualizar_Recursos();
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

    //sTempo.clear();
    //sTempo.push_back(tempo);
    //SDL_Surface* textSurface = TTF_RenderText_Solid( font, .c_str(), textColor );

}

bool Jogo::loadMidia() {
    //Loading success flag
    bool success = true;

    //Load PNG texture
    texturas[TEXTURAS::TROPA_PAPEL] = loadTexture( "imagens/papel.png" );
    if ( texturas[TEXTURAS::TROPA_PAPEL] == NULL ) {
        printf( "Failed to load texture papel.png!\n" );
        success = false;
    }

    texturas[TEXTURAS::TROPA_PEDRA] = loadTexture( "imagens/pedra.png" );
    if ( texturas[TEXTURAS::TROPA_PEDRA] == NULL ) {
        printf( "Failed to load texture pedra.png!\n" );
        success = false;
    }

    texturas[TEXTURAS::TROPA_TESOURA] = loadTexture( "imagens/tesoura.png" );
    if ( texturas[TEXTURAS::TROPA_TESOURA] == NULL ) {
        printf( "Failed to load texture tesoura.png!\n" );
        success = false;
    }

    texturas[TEXTURAS::TROPA_PAPEL2] = loadTexture( "imagens/aviao_de_papel.png" );
    if ( texturas[TEXTURAS::TROPA_PAPEL2] == NULL ) {
        printf( "Failed to load texture aviao_de_papel.png!\n" );
        success = false;
    }

    texturas[TEXTURAS::TROPA_PEDRA2] = loadTexture( "imagens/Golem_de_pedra.png" );
    if ( texturas[TEXTURAS::TROPA_PEDRA2] == NULL ) {
        printf( "Failed to load texture Golem_de_pedra.png!\n" );
        success = false;
    }

    texturas[TEXTURAS::TROPA_TESOURA2] = loadTexture( "imagens/katana.png" );
    if ( texturas[TEXTURAS::TROPA_TESOURA2] == NULL ) {
        printf( "Failed to load texture katana.png!\n" );
        success = false;
    }

    texturas[TEXTURAS::FABRICA_PAPEL] = loadTexture( "imagens/GeraTropaPapel.png" );
    if ( texturas[TEXTURAS::FABRICA_PAPEL] == NULL ) {
        printf( "Failed to load texture GeraTropaPapel.png!\n" );
        success = false;
    }

    texturas[TEXTURAS::FABRICA_PEDRA] = loadTexture( "imagens/GeraTropaPedra.png" );
    if ( texturas[TEXTURAS::FABRICA_PEDRA] == NULL ) {
        printf( "Failed to load texture GeraTropaPedra.png!\n" );
        success = false;
    }

    texturas[TEXTURAS::FABRICA_TESOURA] = loadTexture( "imagens/GeraTropaTesoura.png" );
    if ( texturas[TEXTURAS::FABRICA_TESOURA] == NULL ) {
        printf( "Failed to load texture GeraTropaTesoura.png!\n" );
        success = false;
    }

    texturas[TEXTURAS::GERAR_PAPEL] = loadTexture( "imagens/Gerador_Madeira.png" );
    if ( texturas[TEXTURAS::GERAR_PAPEL] == NULL ) {
        printf( "Failed to load texture Gerador_Madeira.png!\n" );
        success = false;
    }

    texturas[TEXTURAS::GERAR_PEDRA] = loadTexture( "imagens/Gerador_Pedra.png" );
    if ( texturas[TEXTURAS::GERAR_PEDRA] == NULL ) {
        printf( "Failed to load texture Gerador_Pedra.png!\n" );
        success = false;
    }

    texturas[TEXTURAS::GERAR_TESOURA] = loadTexture( "imagens/Gerador_Metal.png" );
    if ( texturas[TEXTURAS::GERAR_TESOURA] == NULL ) {
        printf( "Failed to load texture Gerador_Metal.png!\n" );
        success = false;
    }

    texturas[TEXTURAS::BASE_PLAYER] = loadTexture( "imagens/castelo_azul.png" );
    if ( texturas[TEXTURAS::BASE_PLAYER] == NULL ) {
        printf( "Failed to load texture castelo_azul.png!\n" );
        success = false;
    }

    texturas[TEXTURAS::BASE_CPU] = loadTexture( "imagens/castelo_vermelho.png" );
    if ( texturas[TEXTURAS::BASE_CPU] == NULL ) {
        printf( "Failed to load texture castelo_vermelho.png!\n" );
        success = false;
    }

    texturas[TEXTURAS::MENU_PRINCIPAL] = loadTexture( "imagens/menu_inicial.png" );
    if ( texturas[TEXTURAS::MENU_PRINCIPAL] == NULL ) {
        printf( "Failed to load texture menu_inicial.png!\n" );
        success = false;
    }

    texturas[TEXTURAS::BOTAO_INICIAR] = loadTexture( "imagens/botao1.png" );
    if ( texturas[TEXTURAS::BOTAO_INICIAR] == NULL ) {
        printf("Failed to load texture bota1.png!\n");
        success = false;
    }

    texturas[TEXTURAS::BOTAO_INICIAR_S] = loadTexture("imagens/botao1S.png");
    if (texturas[TEXTURAS::BOTAO_INICIAR_S] == NULL) {
        printf("Failed to load texture botao1S.png!\n");
        success = false;
    }

    texturas[TEXTURAS::BOTAO_INICIAR_P] = loadTexture("imagens/botao1P.png");
    if (texturas[TEXTURAS::BOTAO_INICIAR_P] == NULL) {
        printf("Failed to load texture botao1P.png!\n");
        success = false;
    }

    texturas[TEXTURAS::MAPA] = loadTexture("imagens/Mapa.png");
    if (texturas[TEXTURAS::MAPA] == NULL) {
        printf("Failed to load texture Mapa.png!\n");
        success = false;
    }
    font = TTF_OpenFont("fonts/04B_08__.TTF", 28);

    bIniciar->mudaTextura(texturas[BOTAO_INICIAR]);
    bIniciar->setDestRect(300, 500, 300, 120);
    bIniciar->setSrcRect(0, 0, 300, 120);
    menuInicial->mudaTextura(texturas[MENU_PRINCIPAL]);
    menuInicial->setDestRect(0, 0, 1280, 720);
    menuInicial->setSrcRect(0, 0, 1280, 720);
    mapa->mudaTextura(texturas[MAPA]);
    mapa->setSrcRect(0, 0, 1280, 720);
    mapa->setDestRect(0, 0, 1280, 720);
    // compra->mudaTextura(texturas[GERAR_PAPEL]);
    compra->setSrcRect(0, 0, 64, 64);
    compra->setDestRect(480, 648, 64, 64);

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

    return success;
}

SDL_Texture* Jogo::loadTexture(const char* nome) {
    SDL_Texture* novaTextura = NULL;
    SDL_Surface* surfaceTmp = IMG_Load(nome);

    if (surfaceTmp == NULL) {
        printf("Não foi possível carregar a imagem %s! SDL_image Error: %s\n", nome, IMG_GetError() );
    } else {
        novaTextura = SDL_CreateTextureFromSurface(render, surfaceTmp);
        if (novaTextura == NULL) {
            printf("Unable to create texture from %s! SDL Error: %s\n", nome, SDL_GetError());
        }
        SDL_FreeSurface(surfaceTmp);
    }
    return novaTextura;
}

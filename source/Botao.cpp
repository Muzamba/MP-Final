#include "Botao.h"
#include "Jogo.h"
#include "Player.h"
extern Jogo* jogo;
extern Player* jogador;
extern Player* cpu;

void Botao_Iniciar::handleEvent(SDL_Event* evento) {
    //OPERACOES retorno = NADA;
    int x, y;
    SDL_GetMouseState(&x,&y);
    bool dentro = true;

    if(x < destRect->x) {
        dentro = false;
    } else if(x > (destRect->x + destRect->w)) {
        dentro = false;
    } else if(y < destRect->y) {
        dentro = false;
    } else if(y > (destRect->y + destRect->h)) {
        dentro = false;
    }

    if(!dentro){
        textura = jogo->texturas[BOTAO_INICIAR];
    } else {
        switch( evento->type ) {
            case SDL_MOUSEMOTION:
                textura = jogo->texturas[BOTAO_INICIAR_S];
                break;
            
            case SDL_MOUSEBUTTONDOWN:
                textura = jogo->texturas[BOTAO_INICIAR_P];
                break;
                
            case SDL_MOUSEBUTTONUP:
                textura = jogo->texturas[BOTAO_INICIAR_P];
                jogo->menu_inicial = false;
                break;
            }
    }
}

void Botao_Compra::handleEvent(SDL_Event* evento){
   /* 
    //if(evento->type == SDL_MOUSEBUTTONUP){
    switch(evento->type){

        case SDL_MOUSEMOTION:
            break;
        case SDL_MOUSEBUTTONDOWN:
            break;
        case SDL_MOUSEBUTTONUP:
        printf("-----------------------\n");
            switch(tipo){
                case NADA:
                case GERA_PAPEL:
                case GERA_PEDREGULHO:
                case GERA_METAL:
                    break;

                case GERA_CELULOSE:
                    int x, y;
                    SDL_GetMouseState(&x,&y);
                    if(!jogo->comprando){
                        if((destRect->x < x)&&((destRect->x + destRect->w) > x)&&(destRect->y < y)&&((destRect->y + destRect->h) > y)){
                            jogo->comprando = true;
                            printf("comprando\n"); 
                        }else{ printf("nao comprando\n");}
                    //printf("alooo\n"); 
                    } else {
                        printf("ola\n");
                        printf("%d--%d\n", x, y);
                        x -= 160;
                        y -= 144;        
                        printf("%d--%d\n", x, y);

                        //printf("modulo: %d--%d\n", x % 80, y % 72);
                        if((x % 80) != 0){
                            //printf("aquiiiiiiiiiiiiiiii\n");
                            x -= (x%80);
                            x = x / 80;
                        } else {
                            x = x / 80;
                        }
                        if((y % 74) != 0){
                            y -= (y%72);
                            y = y / 72;
                        } else {
                            y = y / 72;
                        }
                        printf("%d--%d\n", x, y);
                        if((x >= 0)&&(x < 12)&&(y >= 0)&&(y < 6)) {
                            //printf("deu certo\n");
                            if(jogador->compra_GeraRecurso(y, x, CELULOSE)){
                                printf("comprado\n");
                            }else {
                                printf("falha\n");
                            }
                            jogo->comprando = false;
                                
                        } else {
                            jogo->comprando = false;
                        }
                    }
                    break;

                case GERA_PEDRA:
                    break;

                case GERA_TESOURA:
                    break;
            }
                break;
    }
    //}
    */

}

void Botao_Compra::mudaTipo(TIPO novoTipo){
    tipo = novoTipo;
}

void buttomEvents(SDL_Event* evento) {
    int x = 0, y = 0;
    
    SDL_GetMouseState(&x,&y);

    switch(evento->type){

        case SDL_MOUSEMOTION:
            break;
        case SDL_MOUSEBUTTONDOWN:
            break;
        case SDL_MOUSEBUTTONUP:
            if(jogo->comprando) {
                to_Cord(&x, &y);
                x -= 2;
                y -= 2;
                switch(jogo->tipoCompra){
                    case NADA:
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        break;
                    case U_GERA_METAL:
                        if (jogo->matriz_geraRecurso[y][x]->getTipo() == RECURSO::METAL) {
                            printf("upgrade realizado gera metal\n ");
                            jogo->matriz_geraRecurso[y][x]->upgrade(&(jogador->dinheiro));
                        } else {
                            printf("Upgrade negado gera metal\n");
                        }
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        break;
                    case U_GERA_PEDREGULHO:
                        if (jogo->matriz_geraRecurso[y][x]->getTipo() == RECURSO::PEDREGULHO) {
                            printf("upgrade realizado gera pedregulho\n ");
                            jogo->matriz_geraRecurso[y][x]->upgrade(&(jogador->dinheiro));
                        } else {
                            printf("Upgrade negado gera pedregulho\n");
                        }
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        break;
                    case U_GERA_CELULOSE:
                        if (jogo->matriz_geraRecurso[y][x]->getTipo() == RECURSO::CELULOSE) {
                            printf("upgrade realizado gera celulose \n");
                            jogo->matriz_geraRecurso[y][x]->upgrade(&(jogador->dinheiro));
                        } else {
                            printf("Upgrade negado gera celulose\n");
                        }
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        break;
                    case FABRICAR_PAPEL:
                        jogador->compra_Fabrica(y, x, PAPEL);
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        break;
                    case FABRICAR_TESOURA:
                        jogador->compra_Fabrica(y, x, TESOURA);
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        break;
                    case FABRICAR_PEDRA:
                        jogador->compra_Fabrica(y, x, PEDRA);
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        break;
                    case GERA_CELULOSE:
                        //printf("deu certo\n");
                        if (jogador->compra_GeraRecurso(y, x, CELULOSE)) {
                            printf("Gera celulose comprado com sucesso\n");
                        } else {
                            printf("Falha na compra\n");
                        }
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                    break;

                    case GERA_PEDREGULHO:
                        //printf("deu certo\n");
                        if (jogador->compra_GeraRecurso(y, x, PEDREGULHO)) {
                            printf("Gera pedregulho comprado com sucesso\n");
                        } else {
                            printf("Falha na compra\n");
                        }
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        break;

                    case GERA_METAL:
                        if (jogador->compra_GeraRecurso(y, x, METAL)) {
                            printf("Gera pedregulho comprado com sucesso\n");
                        } else {
                            printf("Falha na compra\n");
                        }
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;
                        break;
                    
                    default:
                        printf("aaaa\n");
                        jogo->comprando = false;
                        jogo->tipoCompra = NADA;

                }//switch
                
            } /*if*/else{
                retornaBotao(&x, &y);
            }//else
            printf("tipo: %d , comprando: %d\n", jogo->tipoCompra,(jogo->comprando  ? 1 : 0 ));
            //printf("x: %d , y: %d\n", x, y);

    }
}

void retornaBotao(int* X,int* Y){
    jogo->comprando = true;
    to_Cord(X, Y);
    switch(*Y){
        case 8: 
            switch(*X) {
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
            switch(*X){
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
  
    if((*X % 80) != 0){
        *X -= (*X % 80);
        *X = *X / 80;
        //*X = *X / 72;
    } else {
        *X = *X / 80;
    }
    if((*Y % 74) != 0){
        *Y -= (*Y % 72);
        *Y = *Y / 72;
    } else {
        *Y = *Y / 72;
    }
    printf("x: %d , y: %d\n", *X, *Y);
}

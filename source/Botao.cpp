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

}

void Botao_Compra::mudaTipo(TIPO novoTipo){
    tipo = novoTipo;
}

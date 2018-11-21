#include "Botao.h"
#include "Jogo.h"
extern Jogo* jogo;

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
    printf("teste4");
    if(evento->type == SDL_MOUSEBUTTONUP){
    switch(tipo){
        case NADA:
        case GERA_CELULOSE:
        case GERA_PEDREGULHO:
        case GERA_METAL:
            break;

        case GERA_PAPEL:
        int x, y;
            SDL_GetMouseState(&x,&y);
        if(!jogo->comprando){
            if((destRect->x < x)&&((destRect->x + destRect->w) > x)&&(destRect->y < y)&&((destRect->y + destRect->h) > y)){
                jogo->comprando = true;
                printf("teste2"); 
            }
            printf("teste3"); 
        } else {
            x -= 160;
            y -= 144;        
            if((x % 80) != 0){
                x -= (x%80);
                x = x % 80;
            } else {
                x = 80;
            }
            if((y % 74) != 0){
                y -= (y%74);
                y = y % 72;
            } else {
                y = y % 72;
            }
            if((x > 0)&&(x < 12)&&(y > 0)&&(y <6)) {
                jogo->jogador->compra_GeraRecurso(x, y, CELULOSE);
                jogo->comprando = false;
                printf("teste");    
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
    }

}

void Botao_Compra::mudaTipo(TIPO novoTipo){
    tipo = novoTipo;
}

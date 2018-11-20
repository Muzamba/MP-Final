#include "Botao.h"

OPERACOES Botao_Iniciar::handleEvent(SDL_Event* evento, SDL_Texture* texBase, SDL_Texture* texSele, SDL_Texture* texPres) {
    OPERACOES retorno = NADA;
    int x, y;
    SDL_GetMouseState(&x,&y);
    bool dentro = true;

    if(x < pos_X) {
        dentro = false;
    } else if(x > (pos_X + destRect->w)) {
        dentro = false;
    } else if(y < pos_Y) {
        dentro = false;
    } else if(y > (pos_Y + destRect->h)) {
        dentro = false;
    }

    if(!dentro){
        textura = texBase;
    } else {
        switch( evento->type ) {
            case SDL_MOUSEMOTION:
                textura = texSele;
                break;
            
            case SDL_MOUSEBUTTONDOWN:
                textura = texPres;
                break;
                
            case SDL_MOUSEBUTTONUP:
                textura = texPres;
                retorno = INICIA_JOGO;
                break;
            }
    }
    return retorno;
}

Botao_Iniciar::~Botao_Iniciar(){

}
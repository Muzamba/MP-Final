#include "Jogo.h"
#include "Player.h"
#include "Objeto.h"
#include "Botao.h"
#include "Fabrica.h"
#include "GeraRecursos.h"
#include "Head.h"
#include "Predio.h"
#include "Unidade.h"

#include <iostream>

Jogo* jogo;
    
int main() {
    
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;
printf("\n\n\n1\n\n\n");
    jogo = new Jogo();

    jogo->init("teste", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720);
    jogo->loadMidia();

    while(jogo->isOn()) {
        
        frameStart = SDL_GetTicks();
        //printf("teste\n");
        jogo->handleEvents();
        
        jogo->update();
        jogo->renderizar();

        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }

    }

    jogo->fim();

    delete jogo;
     
     return 0;
}


 



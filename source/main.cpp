#include "Jogo.h"
#include <iostream>

int main() {

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    Jogo* jogo;
    jogo = new Jogo();

    jogo->init("teste", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720);


    while(jogo->isOn()) {
        frameStart = SDL_GetTicks();
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


 



#include "Jogo.h"
#include <iostream>
#include "Head.h"

Jogo::Jogo(){
    matriz_fabrica = new Fabrica **[6];
    matriz_unidade = new Unidade **[6];
    matriz_geraRecurso = new GeraRecursos**[6];
    for(int i=0; i < 6; i++){
        matriz_fabrica[i] = new Fabrica *[12];
        matriz_unidade[i] = new Unidade *[12];
        matriz_geraRecurso[i] = new GeraRecursos *[12];
    }
    for(int i=0; i< 6; i++){
        for(int j=0; j < 12; j++) {
            matriz_fabrica[i][j] = NULL;
            matriz_unidade[i][j] = NULL;
            matriz_geraRecurso[i][j] = NULL;
        }
    }
}

void Jogo::init(const char* nome, int x, int y, int w, int h) {
    
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Sistema Inicializado!...." << std::endl;
        
        janela = SDL_CreateWindow( nome, x, y, w, h, 0);
        if(janela){
            std::cout << "Janela criada!" << std::endl;
        }
        render = SDL_CreateRenderer(janela, -1, 0);
        if(render){

            SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
            std::cout << "Renderer criado!" << std::endl;
        }
        on = true;
    } else {
        on = false;
    }
}

bool Jogo::isOn(){
    return on;
}

void Jogo::handleEvents(){
    SDL_Event evento;
    SDL_PollEvent(&evento);
    switch(evento.type) {
        case SDL_QUIT:
            on = false;
            break;

        default:
        break;
    }
}

void Jogo::renderizar(){
    SDL_RenderClear(render);
    //Adione aqui as coisas para renderizar
    SDL_RenderPresent(render);
}

void Jogo::fim() {
    SDL_DestroyWindow(janela);
    SDL_DestroyRenderer(render);
    SDL_Quit();
    std::cout << "Jogo fechado" << std::endl;
}

void Jogo::load(){
}

void Jogo::update(){

}
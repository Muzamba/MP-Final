#include "Jogo.h"
#include <iostream>

Jogo::Jogo(){
}
Jogo::~Jogo(){
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
            std::cout << "Render criado!" << std::endl;
            int imgFlags = IMG_INIT_PNG;
			if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
				printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
			    on = false;
			}
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
    for(int i = 0;i < TEXTURAS::TEX_TOTAL;++i){
        SDL_DestroyTexture(texturas[i]);
        texturas[i] = NULL;
    }
    SDL_DestroyWindow(janela);
    janela = NULL;
    SDL_DestroyRenderer(render);
    render = NULL;
    IMG_Quit();
    SDL_Quit();
    std::cout << "Jogo fechado" << std::endl;
}

void Jogo::load(){
}

void Jogo::update(){

}

bool Jogo::loadMidia() {
    //Loading success flag
	bool success = true;

	//Load PNG texture
	texturas[TEXTURAS::TROPA_PAPEL] = loadTexture( "imagens/papel.png" );
	if( texturas[TEXTURAS::TROPA_PAPEL] == NULL ) {
		printf( "Failed to load texture papel.png!\n" );
		success = false;
	}

    texturas[TEXTURAS::TROPA_PEDRA] = loadTexture( "imagens/pedra.png" );
	if( texturas[TEXTURAS::TROPA_PEDRA] == NULL ) {
		printf( "Failed to load texture pedra.png!\n" );
		success = false;
	}

    texturas[TEXTURAS::TROPA_TESOURA] = loadTexture( "imagens/tesoura.png" );
	if( texturas[TEXTURAS::TROPA_TESOURA] == NULL ) {
		printf( "Failed to load texture tesoura.png!\n" );
		success = false;
	}

    texturas[TEXTURAS::TROPA_PAPEL2] = loadTexture( "imagens/aviao_de_papel.png" );
	if( texturas[TEXTURAS::TROPA_PAPEL2] == NULL ) {
		printf( "Failed to load texture aviao_de_papel.png!\n" );
		success = false;
	}

    texturas[TEXTURAS::TROPA_PEDRA2] = loadTexture( "imagens/Golem_de_pedra.png" );
	if( texturas[TEXTURAS::TROPA_PEDRA2] == NULL ) {
		printf( "Failed to load texture Golem_de_pedra.png!\n" );
		success = false;
	}

    texturas[TEXTURAS::TROPA_TESOURA2] = loadTexture( "imagens/katana.png" );
	if( texturas[TEXTURAS::TROPA_TESOURA2] == NULL ) {
		printf( "Failed to load texture katana.png!\n" );
		success = false;
	}

    texturas[TEXTURAS::FABRICA_PAPEL] = loadTexture( "imagens/GeraTropaPapel.png" );
	if( texturas[TEXTURAS::FABRICA_PAPEL] == NULL ) {
		printf( "Failed to load texture GeraTropaPapel.png!\n" );
		success = false;
	}

    texturas[TEXTURAS::FABRICA_PEDRA] = loadTexture( "imagens/GeraTropaPedra.png" );
	if( texturas[TEXTURAS::FABRICA_PEDRA] == NULL ) {
		printf( "Failed to load texture GeraTropaPedra.png!\n" );
		success = false;
	}

    texturas[TEXTURAS::FABRICA_TESOURA] = loadTexture( "imagens/GeraTropaTesoura.png" );
	if( texturas[TEXTURAS::FABRICA_TESOURA] == NULL ) {
		printf( "Failed to load texture GeraTropaTesoura.png!\n" );
		success = false;
	}

    texturas[TEXTURAS::GERAR_PAPEL] = loadTexture( "imagens/Gerador_Madeira.png" );
	if( texturas[TEXTURAS::GERAR_PAPEL] == NULL ) {
		printf( "Failed to load texture Gerador_Madeira.png!\n" );
		success = false;
	}

    texturas[TEXTURAS::GERAR_PEDRA] = loadTexture( "imagens/Gerador_Pedra.png" );
	if( texturas[TEXTURAS::GERAR_PEDRA] == NULL ) {
		printf( "Failed to load texture Gerador_Pedra.png!\n" );
		success = false;
	}

    texturas[TEXTURAS::GERAR_TESOURA] = loadTexture( "imagens/Gerador_Metal.png" );
	if( texturas[TEXTURAS::GERAR_TESOURA] == NULL ) {
		printf( "Failed to load texture Gerador_Metal.png!\n" );
		success = false;
	}

    texturas[TEXTURAS::BASE_PLAYER] = loadTexture( "imagens/castelo_azul.png" );
	if( texturas[TEXTURAS::BASE_PLAYER] == NULL ) {
		printf( "Failed to load texture castelo_azul.png!\n" );
		success = false;
	}

    texturas[TEXTURAS::BASE_CPU] = loadTexture( "imagens/castelo_vermelho.png" );
	if( texturas[TEXTURAS::BASE_CPU] == NULL ) {
		printf( "Failed to load texture castelo_vermelho.png!\n" );
		success = false;
	}

	return success;

}

SDL_Texture* Jogo::loadTexture(const char* nome) {
    SDL_Texture* novaTextura = NULL;
    SDL_Surface* surfaceTmp = IMG_Load(nome);

    if(surfaceTmp == NULL) {
        printf( "Não foi possível carregar a imagem %s! SDL_image Error: %s\n", nome, IMG_GetError() );
    } else {
        novaTextura = SDL_CreateTextureFromSurface(render, surfaceTmp);
        if(novaTextura == NULL) {
            printf( "Unable to create texture from %s! SDL Error: %s\n", nome, SDL_GetError() );
        }
        SDL_FreeSurface(surfaceTmp);
    }
    return novaTextura;

}
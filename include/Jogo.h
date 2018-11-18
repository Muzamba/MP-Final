#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Head.h"

class Jogo {
public:
    Jogo();
    void init(const char* titulo, int x_pos, int y_pos, int width, int height);
    bool loadMidia();
    SDL_Texture* loadTexture(const char* nome);
    void load();
    void fim();

    void update();
    void handleEvents();
    void renderizar();
    bool isOn();
    ~Jogo();

protected:
    int tempo;
    bool on;
    SDL_Window* janela = NULL;
    SDL_Texture* texturas[TEXTURAS::TEX_TOTAL];
    SDL_Renderer* render = NULL;

};

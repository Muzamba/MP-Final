#pragma once
#include <SDL2/SDL.h>

class Jogo {
public:
    Jogo();
    void init(const char* titulo, int x_pos, int y_pos, int width, int height);
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
    SDL_Window *janela;
    SDL_Renderer *render;

};

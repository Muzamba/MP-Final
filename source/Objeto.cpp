// Copyright 2018 João Pedro Assis
#include "../include/Objeto.h"

Objeto::Objeto(int X, int Y,int W,int H) {
    srcRect = new SDL_Rect;
    destRect = new SDL_Rect;
    pos_X = destRect->x = X;
    pos_Y = destRect->y = Y;
    srcRect->x = 0;
    srcRect->y = 0;
    srcRect->w = destRect->w = W;
    srcRect->h = destRect->h = H;
}

int Objeto::get_x() {
    return pos_X;
}

int Objeto::get_y() {
    return pos_Y;
}

void Objeto::set_x(int X) {
    pos_X = destRect->x = X;
}

void Objeto::set_y(int Y) {
    pos_Y = destRect->y = Y;
}

void Objeto::render(SDL_Renderer* r) {
    SDL_RenderCopy(r, this->textura, srcRect, destRect);
}

void Objeto::mudaTextura(SDL_Texture* textura) {
    this->textura = textura;
}

Objeto::~Objeto() {
    delete srcRect;
    delete destRect;
}

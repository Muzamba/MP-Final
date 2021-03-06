/**
 * @file Jogo.h
 * @author Nome do time (a definir)
 * @brief Definiçao e implementaçao da classe Jogo.
 * @version 0.99
 * @date 2018-12-02
 *
 * @copyright Copyright (c) 2018 (nao sei o que colocar aqui)
 *
 */
// copyright 2018 Switch Dreams
#pragma once
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <string>
#include "Player.h"
#include "Head.h"
#include "Botao.h"
#include "Fabrica.h"
#include "GeraRecursos.h"
#include "Unidade.h"
#include <iostream>
/**
 * @brief 
 * 
 */
struct Acao{
    bool* last;

    int ondeX;
    int ondeY;
};

/**
 * @class Jogo Jogo.h
 * @brief Classe base do jogo onde e aplicado quase todas as funcionalidades.
 *
 */
class Jogo {
 public:
    /**
     * @brief Controi um objeto Jogo.
     *
     */
    Jogo();

    /**
     * @brief Inicializa os pre-requisitos da parte grafica.
     *
     * @param titulo - Nome da janela.
     * @param x_pos - Coordenada X de onde ira aparecer a janela.
     * @param y_pos - Coordenada Y de onde ira aparecer a janela.
     * @param width - Largura da janela.
     * @param height - Altura da janela.
     */
    void init(const char* titulo, int x_pos, int y_pos, int width, int height);

    /**
     * @brief Carrega todas as imagens e inicializa todos os objetos necesarios
     * para o jogo.
     *
     * @return true - Carregou e inicializou tudo com sucesso.
     * @return false - Houve uma falha durante a execuçao da funçao.
     */
    bool loadMidia();
    /*<EU 010> e <EU 011> */


    /**
     * @brief Funçao auxiliar da loadMidia para o carregamento de imagens.
     *
     * @param nome - Endereço do imagem para a abertura.
     * @return SDL_Texture* - Ponteiro da textura carregada.
     */
    SDL_Texture* loadTexture(const char* nome);

    /**
     * @brief Carregar jogo previamente salvo e inicializa ele.
     *
     */
    void load();

    /**
     * @brief Salva estado atual do jogo em um arquivo.
     *
     */
    /* <EU 002> */
    void save();

    /**
     * @brief Carrega informaçoes para o cpu.
     *
     * @param arq - Ponteiro do arquivo de save.
     */
    void loadInfoCPU(FILE* arq);

    /**
     * @brief Carrega informaçoes para o jogador.
     *
     * @param arq - Ponteiro do arquivo de save.
     */
    void loadInfoPlayer(FILE* arq);

    /**
     * @brief Finaliza o que foi inicializado na init().
     *
     */
    void fim();

    /**
     * @brief Desliga o jogo.
     *
     */
    void turnOff();

    /**
     * @brief Realiza todas as atualizaçoes necessaria ao decorrer do jogo.
     *
     */
    void update();

    /**
     * @brief Lida com as açoes do jogador.
     *
     */
    void handleEvents();
    /* <EU 007> e <EU 008>*/

    /**
     * @brief Renderiza o estado do jogo atual.
     *
     */
    void renderizar();

    /**
     * @brief Verifica se o jogo esta ligado
     *
     * @return true - Jogo esta ligado.
     * @return false - Jogo esta desligado.
     */
    bool isOn();

    //-------------------- Métodos da cpu ------------------------------

    /**
     * @brief Limpa o vetor de que registra a última ação do jogador.
     * 
     */
    void clear_ultima_acao();

    /**
     * @brief A partir da última ação feita pelo jogador, calcula qual
     *  a jogada ótima a ser feita.
     * 
     * @param ultima_compra - Vetor de booleanos que diz qual foi
     *  a última jogada do Player.
     * 
     * @return int - número da jogada a ser feita pela CPU
     */
    int counter(bool* ultima_compra);

    /**
     * @brief Recebe a ação a ser feita pela CPU e retorna qual o tipo
     *  de unidade a jogada se refere.
     * 
     * @param acao - Jogada da CPU.
     * @return UNIDADE - Tipo da jogada.
     */
    UNIDADE retorna_tipo_und(int acao);

    /**
     * @brief Recebe a ação a ser feita pela CPU e retorna qual o tipo
     *  de recurso a jogada se refere.
     * 
     * @param acao - Jogada da CPU.
     * @return RECURSO - Recurso que deverá ser utilizado.
     */
    RECURSO retorna_tipo_rec(int acao);

    /**
     * @brief Calcula a posição X e Y de onde deve ser feita a próxima jogada
     * 
     *  Caso a próxima jogada seja colocar uma fábrica, sempre a colocar
     * na fileira de número 10. Caso a posição já esteja ocupada, procurar 
     * na posição abaixo. Caso não exista nenhum lugar disponível, a fábrica
     * não será posicionada.
     * 
     * Caso a próxima jogada seja colocar uma geraRecursos, sempre a colocar
     * na fileira de número 11. Caso a posição já esteja ocupada, procurar 
     * na posição abaixo. Caso não exista nenhum lugar disponível, a fábrica
     * não será posicionada.
     * 
     * Caso a próxima jogada seja colocar uma unidade, colocar na mesma linha
     * que o jogador posicionou a própria tropa. Caso o espaço esteja ocupado,
     * verificar horizontalmente por uma posição válida. Caso esta não seja
     * encontrada, voltar para o final da linha, visto que as unidades se movem
     * e o espaço pode estar vazio.
     * 
     * @param X - Posição X da jogada da CPU
     * @param Y - Posição Y da jogada da CPU
     * @param counter - Ação a ser tomada pela CPU
     */
    void onde_botar(int* X, int* Y, int counter);

    /**
     * @brief - Calcula, por meio de uma soma ponderada num histograma, a melhor 
     * fábrica para comprar uma unidade. 
     * 
     * @param tipo - tipo da fábrica
     * @return int - nível da melhor fábrica para se comprar uma unidade.
     */
    int qual_fbrc(UNIDADE tipo);

    /**
     * @brief - retorna o índice da posição que possui o maior valor
     * em um array
     * 
     * @param vector - array a ser analisadp 
     * @param n - tamanho do vetor
     * @return int - indice da posição que possui o maior valor
     */
    int max_index(int* vector, int n);

    /**
     * @brief - Retorna qual a posição da fábrica que possui o menor nível
     * 
     * @param tipo - tipo da fábrica a ser analisada
     * @param X - Posição X da fábrica de menor nível
     * @param Y - Posição Y da fábrica de menor nível
     */
    void menor_nivel(UNIDADE tipo, int* X, int* Y);

    /**
     * @brief Coloca no mapa a jogada da CPU
     * 
     */
    void bota_no_mapa();

    /**
     * @brief Destrutor do objeto Jogo.
     *
     */
    ~Jogo();

    /**
     * @brief Movimenta todas as tropas em campo.
     *
     */
    void movimentacao();

    /**************************************************************************
     *  Variaveis Publicas
     *************************************************************************/
    Unidade ***matriz_unidade = NULL;
    GeraRecursos ***matriz_geraRecurso = NULL;
    Fabrica ***matriz_fabrica = NULL;

    Mix_Music *musicas[MUSICAS::MUS_TOTAL];
    Mix_Chunk *efeitos[EFEITOS::EFEITO_TOTAL];
    SDL_Texture* texturas[TEXTURAS::TEX_TOTAL];

    bool menu_inicial = false;
    bool ganhou = false;
    bool perdeu = false;
    SDL_Texture* aloo;
    bool paused = false;
    // #ifdef TESTE
    // Player* jogador = NULL;
    // Player* cpu = NULL;
    // #endif
    // Player* jogador = NULL;
    bool comprando = false;
    TIPO tipoCompra = NADA;
    int nivelCompra = -1;
    // SDL_Texture *teste;
    Acao ultima_acao;



 protected:
    /**************************************************************************
     *  Variaveis Privadas
     *************************************************************************/
    Objeto* recursoDinheiroJogador = NULL;
    Objeto* recursoCeluloseJogador = NULL;
    Objeto* recursoPedregulhoJogador = NULL;
    Objeto* recursoMetalJogador = NULL;
    Objeto* recursoDinheiroCpu = NULL;
    Objeto* recursoCeluloseCpu = NULL;
    Objeto* recursoPedregulhoCpu = NULL;
    Objeto* recursoMetalCpu = NULL;
    Objeto* tempo_Obj = NULL;
    Objeto* vitoria = NULL;
    Objeto* derrota = NULL;

    SDL_Color cRecurso{0, 0, 0};  // decidir cor
    SDL_Texture* tRecurso;  // talvez possa remover
    TTF_Font* font = NULL;

    Botao_Iniciar* bIniciar = NULL;
    Botao_Load* bLoad = NULL;
    Botao_Pause* pause = NULL;
    Botao_Resume* resume = NULL;
    Botao_Sair* bSair = NULL;
    Botao_Save* bSalvar = NULL;

    Objeto* menuInicial = NULL;
    Objeto* mapa = NULL;
    std::string tempo_val;
    bool on;
    SDL_Window* janela = NULL;

    SDL_Renderer* render = NULL;
};

/**
 * @brief Realiza o combate entre duas unidades.
 *
 * @param unidade1 - Unidade atacante.
 * @param unidade2 - Unidade defensora.
 * @return int - Ver com o Wallif ou Pedro.
 */
int combate_unidade(Unidade** unidade1, Unidade** unidade2);

/**
 * @brief Unidade atacando uma GeraRecurso.
 *
 * @param unidade - Unidade atacante.
 * @param geradora - GeraRecursos alvo.
 * @return int - Ver com o Wallif ou Pedro.
 */
int ataca_geraRecurso(Unidade** unidade, GeraRecursos** geradora);

/**
 * @brief Unidade atacando uma fabrica.
 *
 * @param unidade - Unidade atacante.
 * @param fbrc - Fabrica alvo.
 * @return int - Ver com o Wallif ou Pedro.
 */
int ataca_fabrica(Unidade** unidade, Fabrica** fbrc);

/**
 * @brief Mover uma unidade.
 *
 * @param unidade - Posiçao atual.
 * @param destino - Posiçao alvo.
 */
void anda(Unidade** unidade, Unidade** destino);

/**
 * @brief Incremento da string de tempo.
 *
 * @param string - String de tempo.
 */
void tempoPP(std::string* string);

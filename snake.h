#include <bits/stdc++.h>
using namespace std;

#define __SNAKE_H__
#ifdef __SNAKE_H__

class Game{
    public:
        int x;
        int y;
        deque<pair<int, int>> body;
};

class Fruta{
    public:
        int x;
        int y;
};

void menu();

//Função para desenhar o mapa do jogo.
void draw(const int height, const int width, Game snake, Fruta fruit, long int score);

//Pega a entrada do teclado.
void movement();

//Parte lógica do jogo.
void logic(long int &score, bool &gameOver, bool &definido, Game &snake, Fruta &fruit);

//Define o tamanho da janela.
void setWindow(const int windowHeight, const int windowWidth);

#endif
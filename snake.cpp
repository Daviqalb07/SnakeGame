#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include "snake.h"
using namespace std;

void gotoxy(int x, int y){
    COORD c;

    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//Função para desenhar o mapa do jogo.
void draw(const int height, const int width, Game snake, Alvo fruit, long int score){
    for(int i = 0 ; i <= height ; i++){
        for(int j = 0 ; j <= width ; j++){
            bool desenhado = false;
            if(j == snake.x && i == snake.y){
                cout << "O";
                desenhado = true;
            }
            for(int k = 0 ; k < snake.body.size() ; k++){
                if(!desenhado && j == snake.body[k].first && i == snake.body[k].second){
                    cout << "o";
                    desenhado = true;
                }
            }

            if(i == 0 || i == height || j == 0 || j == width){
                cout << "+";
                desenhado = true;
            }

            else if(j == fruit.x && i == fruit.y){
                cout << "X";
                desenhado = true;
            }

            else if(!desenhado){
                cout << " ";
            }   
        }
        cout << endl;
    }
    cout << endl;
    cout << "\tScore: " << score << endl;
}

int controle = 0;

void movement(){
    //Pega a entrada do teclado.
    if(_kbhit()){
        switch(toupper(_getch())){
            case 'W':
                controle = 1;
                break;
            case 'S':
                controle = 2;
                break;
            case 'A':
                controle = 3;
                break;
            case 'D':
                controle = 4;
                break;
            case 'X':
                controle = -1;
            default:
                break;
        }
    }
}

//Parte lógica do jogo.
void logic(long int &score, bool &gameOver, bool &definido, Game &snake, Alvo &fruit){

    //Direção e sentido da cobra, de forma contínua.
    if(controle < 0){
        gameOver = true;
    }
    else if(controle == 1){
        snake.y--;
    }
    else if(controle == 2){
        snake.y++;
    }
    else if(controle == 3){
        snake.x--;
    }
    else if(controle == 4){
        snake.x++;
    }

    //Se bate nas bordas, perde.
    if(snake.x < 1 || snake.x > 41){
        gameOver = true;
    }
    else if(snake.y < 1 || snake.y > 21){
        gameOver = true;
    }

    for(int i = 1 ; i < snake.body.size() ; i++){
        pair<int, int> compara = {snake.x, snake.y};
        if(compara == snake.body[i]){
            gameOver = true;
        }
    }

    //Se a cabeça encontrar a fruta, o comando é dado para gerar uma nova fruta.
    if(snake.x == fruit.x && snake.y == fruit.y){
        score += 10;
        definido = false;
        snake.body.push_back({snake.x, snake.y});
    }

    else if(!snake.body.empty()){
        snake.body.push_front({snake.x, snake.y});
        snake.body.pop_back();
    }
}
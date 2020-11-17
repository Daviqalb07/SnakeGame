#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include "snake.h"
using namespace std;

void menu(){
    bool options[] = {true, false};
    bool menuLoop = true;
    char key;
    while(menuLoop){
        
        if(_kbhit()){
            key = _getch();
        }
        // 72 = seta para cima
        // 80 = seta para baixo
        // \r = enter
        if((key == 72 && options[1]) || (key == 80 && options[0])){
            options[0] = !options[0];
            options[1] = !options[1];
        }

        //Start.
        if(key == '\r' && options[0]){
            menuLoop = false;
        }

        //Credits.
        if(key == '\r' && options[1]){
            system("cls");
            key = 'a';
            cout << "\n\nSNAKE+" << endl;
            cout << "2020 EDITION" << endl << endl << endl;
            cout << "DEVELOPED BY: DAVI QUEIROZ ALBUQUERQUE" << endl << endl;

            system("pause");
        }

        for(int i = 0 ; i < 2 ; i++)
            cout << endl;
        
        
        cout << "\t\t  SNAKE+ " << endl;
        cout << "\t\t THE GAME" << endl << endl;

        cout << "\t\t";
        if(options[0]){
            cout << " <START>";
        }
        else{
            cout << "  START  ";
        }
        cout << endl;

        cout << "\t\t";
        if(options[1]){
            cout << "<CREDITS>";
        }
        else{
            cout << " CREDITS ";
        }
        cout << endl;

        for(int i = 0 ; i < 16 ; i++)
            cout << endl;

        cout << "↑/↓ - NAVIGATE" << "\nENTER - CONFIRM" << endl;
        Sleep(1000/60); //60 FPS
        system("cls");
    }
}

void draw(const int height, const int width, Game snake, Fruta fruit, long int score){
    for(int i = 0 ; i <= height ; i++){
        for(int j = 0 ; j <= width ; j++){
            bool desenhado = false;
            
            //Cabeça.
            if(j == snake.x && i == snake.y){
                cout << "O";
                desenhado = true;
            }

            for(int k = 0 ; k < snake.body.size() ; k++){
                //Corpo da cobra.
                if(!desenhado && j == snake.body[k].first && i == snake.body[k].second){

                    cout << "o";
                    desenhado = true;
                }
            }

            //Borda do mapa.
            if(i == 0 || i == height || j == 0 || j == width){
                cout << "+";
                desenhado = true;
            }

            //Fruta.
            else if(j == fruit.x && i == fruit.y){
                cout << "X";
                desenhado = true;
            }

            //Espaço vazio.
            else if(!desenhado){
                cout << " ";
            }   
        }
        cout << endl;
    }
    cout << endl;
    cout << "  Score: " << score << endl;
}

int controle = 0;

void movement(){
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

void logic(long int &score, bool &gameOver, bool &definido, Game &snake, Fruta &fruit){

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
        //Compara se as coordenadas da cabeça e de alguma parte do corpo são iguais.
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

    //SCORE MÁXIMO
    if(score == 8000){
        cout << endl << "PARABÉNS! VOCÊ GANHOU O JOGO!" << endl;
        gameOver = true;
    }
    
    //Define as novas coordenadas da fruta.
    if(!definido){
        do{
            definido = true;
            fruit.x = rand() % 41 + 1;
            fruit.y = rand() % 21 + 1;

            if(fruit.x == snake.x && fruit.y == snake.y){
                definido = false;
            }

            for(int i = 1 ; i < snake.body.size() ; i++){
                pair<int, int> temp = {fruit.x, fruit.y};
                if(temp == snake.body[i]){
                    definido = false;
                }
            }
        }while(!definido);
    }

    else if(!snake.body.empty()){
        snake.body.push_front({snake.x, snake.y});
        snake.body.pop_back();
    }
}

void setWindow(const int windowHeight, const int windowWidth){
    _COORD c;

    c.X = windowWidth;
    c.Y = windowHeight;

    _SMALL_RECT r;

    r.Top = r.Left = 0;

    r.Right = (windowWidth - 1);
    r.Bottom = (windowHeight - 1);

    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), c);
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &r);
}
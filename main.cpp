#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "snake.h"
using namespace std;
/*
g++ main.cpp snake.cpp -o Snake
.\"Snake.exe"
*/
int main(void){
    setWindow(27, 43);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    system("title Snake++");
    srand(time(0));
    SetConsoleOutputCP(CP_UTF8);

    const int height = 22, width = 42;
    long int score = 0;
    bool gameOver = false, definido = false;
    Game Snake;
    Fruta Fruit;
    Snake.x = 21;
    Snake.y = 11;

    Snake.body.push_front({Snake.x, Snake.y});
    while(!gameOver){
        system("cls");
        //Define as novas coordenadas da fruta.
        if(!definido){
            do{
                definido = true;
                Fruit.x = rand() % 41 + 1;
                Fruit.y = rand() % 21 + 1;

                if(Fruit.x == Snake.x && Fruit.y == Snake.y){
                    definido = false;
                }

                for(int i = 1 ; i < Snake.body.size() ; i++){
                    pair<int, int> temp = {Fruit.x, Fruit.y};
                    if(temp == Snake.body[i]){
                        definido = false;
                    }
                }
            }while(!definido);
        }
        draw(height, width, Snake, Fruit, score);
        movement();
        logic(score, gameOver, definido, Snake, Fruit);
        
    }

    system("pause");
    return 0;
}
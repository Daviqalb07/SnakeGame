#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "snake.h"
using namespace std;

int main(void){
    setWindow(27, 43);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    system("title Snake+");
    srand(time(0));
    SetConsoleOutputCP(CP_UTF8);

    menu();
    const int height = 22, width = 42;
    long int score = 0;
    bool gameOver = false, definido = false;
    Game Snake;
    Fruta Fruit;
    Snake.x = 21;
    Snake.y = 11;

    Snake.body.push_front({Snake.x, Snake.y});
    system("cls");
    while(!gameOver){
        system("cls");
        draw(height, width, Snake, Fruit, score);
        movement();
        logic(score, gameOver, definido, Snake, Fruit);
        Sleep(1000/60);
    }

    //Se o score não for o máximo permitido.
    if(score < 8000){
        cout << "  GAME OVER!" << endl;
    }
    system("pause");
    return 0;
}
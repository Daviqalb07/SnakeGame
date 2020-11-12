#include <bits/stdc++.h>
using namespace std;

#define __SNAKE_H__
#ifdef __SNAKE_H__

typedef struct{
    int x;
    int y;
    deque<pair<int, int>> body;
} Game;

typedef struct{
    int x;
    int y;
}Fruta;

void gotoxy(int x, int y);
void draw(const int height, const int width, Game snake, Fruta fruit, long int score);
void movement();
void logic(long int &score, bool &gameOver, bool &definido, Game &snake, Fruta &fruit);
void setWindow(const int windowHeight, const int windowWidth);
#endif
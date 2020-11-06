#include <iostream>
#include "gotoxy_setcursor.h"
#include "Obstacle.h"
using namespace std;


Obstacle::Obstacle(int x, int y){
    this->x=x;
    this->y=y;
}

Obstacle::~Obstacle(){
}

int Obstacle::getX(){
    return x;
}

int Obstacle::getY(){
    return y;
}

void Obstacle::draw(){
    gotoxy(x,y);
    cout<<'\xCB';
    for(int i=0;i<18;i++){
        gotoxy(x,y+i+1);
        if(i>7 && i<13);
        else if(i==17)
            cout<<'\xCA';
        else
            cout<<'\xBA';
        }
    gotoxy(x+20,y);
    cout<<'\xCB';
    for(int i=0;i<18;i++){
        gotoxy(x+20,y+i+1);
        if(i>2 && i<8);
        else if(i==17)
            cout<<'\xCA';
        else
            cout<<'\xBA';
        }

    }


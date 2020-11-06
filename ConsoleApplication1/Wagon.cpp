#include <iostream>
#include <windows.h>
#include <utility>
#include "clear.h"
#include "Wagon.h"
#include "Point.h"

Wagon::Wagon(){
    Size=1;
    capacity=500;
    hit=0;
    cells[0]=Point(25,9);
}
Wagon::~Wagon(){
    delete[] cells;
}

int Wagon::get_x(){
    return cells[0].get_x();
}

int Wagon::get_y(){
    return cells[0].get_y();
}
int Wagon::get_size(){
    return Size;
}

bool Wagon::check_hit(){
    return hit;
}
void Wagon::set_hit(){
    hit=1;
}
void Wagon::add_cell(int i){
    if(!i)
        cells[Size++]=Point();
    else{
        cells[Size++]=Point();
        cells[Size++]=Point();
    }
}
bool Wagon::Move(){
    int flag=0;
    for(int i=Size-1;i>0;i--)
        cells[i].copy_position(cells[i-1]);
    switch(direction){
        case 'w':
        flag=cells[0].moveUp();
        break;

        case 's':
        flag=cells[0].moveDown();
        break;

        case 'a':
        flag=cells[0].moveLeft();
        break;

        case 'd':
        flag=cells[0].moveRight();
        break;
    }
    for(int i=0;i<=Size;i++){
        if(i)
            cells[i].draw_wagon();
        else cells[i].draw_wagonHead();
    }

    for(int i=1;i<Size;i++)
        if(cells[0].get_x()==cells[i].get_x() && cells[0].get_y()==cells[i].get_y())
            hit=1;
    return flag;
}
void Wagon::turnUp(){
    if(direction!='s')
        direction='w';
}
void Wagon::turnDown(){
    if(direction!='w')
        direction='s';
}
void Wagon::turnLeft(){
    if(direction!='d')
        direction='a';
}
void Wagon::turnRight(){
    if(direction!='a')
        direction='d';
}

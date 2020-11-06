#include <iostream>
#include <windows.h>
#include <time.h>
#include "Passenger.h"
#include "clear.h"
#include "Point.h"
#include "gotoxy_setcursor.h"


Point::Point(){
    x=0;y=0;
}
Point::Point(int x, int y){
    this->x=x;this->y=y;
}
Point::~Point(){
    //dtor
}
void Point::set_point(int x,int y){
    this->x=x;
    this->y=y;
}
int Point::get_x(){
    return x;
}
int Point::get_y(){
    return y;
}
void Point::draw(Passenger*& p){
    gotoxy(x,y);
    if(p->get_type())
        std::cout<<'C';
    else std::cout<<'F';
}
void Point::draw_wagonHead(){
    gotoxy(x,y);
    std::cout<<'D';
}
void Point::draw_wagon(){
    gotoxy(x,y);
    std::cout<<'\x3';
}
void Point::copy_position(Point p){
    x=p.x;
    y=p.y;
}
bool Point::moveUp(){
    y--;
    if(y<2){
        y=18;
        return 1;
    }
    return 0;

}
bool Point::moveDown(){
    y++;
    if(y>18){
        y=2;
        return 1;
    }
    return 0;
}
bool Point::moveLeft(){
    x--;
    if(x<3){
        x=51;
        return 1;
    }
    return 0;
}
bool Point::moveRight(){
    x++;
    if(x>51){
        x=3;
        return 1;
    }
    return 0;
}


#include <iostream>
#include <limits>
#include <conio.h>
#include <windows.h>
#include <thread>
#include <chrono>
#include <time.h>
#include "gotoxy_setcursor.h"
#include "TrainingGame.h"
#include "Wagon.h"
#include "Point.h"
#include "TrainingCourse.h"
#include "Passenger.h"
#include "Obstacle.h"
using namespace std;

TrainingGame::TrainingGame(){
    start=0,score=0,time=120;
}

TrainingGame::~TrainingGame(){
}

void TrainingGame::welcome_screen(){
    gotoxy(0,0);
    cout<<"\n  "<<'\xC9';
    for (int i=0; i<50; i++) {
        cout<<'\xCD';
    }
    cout<<'\xBB'<<"\n  "<<'\xBA';
    for (int i=0; i<50; i++) {
        cout<<" ";
    }
    cout<<'\xBA';
    for (int j=0; j<9; j++) {
        cout<<"\n"<<"  "<<'\xBA';
        for (int i=0; i<50; i++) {
            cout<<" ";
        }
        cout<<'\xBA';
    }
    cout<<"\n  "<<'\xC8';
    for (int i=0; i<50; i++) {
        cout<<'\xCD';
    }
    cout<<'\xBC';
    gotoxy(19,2);
    cout<<"Omar Samak presents"<<endl<<endl;
    cout<<"  \xBA                  The Wagon Game"<<endl;
    cout<<endl<<"  \xBA 1-Start game"<<endl;
    cout<<"  \xBA 2-How to play"<<endl;
    cout<<"  \xBA 3-Exit"<<endl;
    gotoxy(21,11);
    cout<<"www.gammal.tech";
    gotoxy(4,9);
}

void TrainingGame::how_to_play(){
    char t;
    cout<<"\n Controls:"<<endl;
    cout<<"\n   W,S,A,D for movement"<<endl;
    cout<<"\n Press any key to go back"<<endl;
    _getch();
}

void TrainingGame::game_over(){
    system("cls");
    cout<<"\n  GAME OVER";
}
void TrainingGame::win(){
    system("cls");
    cout<<"\n  YOU WIN";
}
int TrainingGame::get_score(){
    return score;
}
bool TrainingGame::started(){
    return start;
}
void TrainingGame::print_score(float score){
    gotoxy(3,20);
    std::cout<<"score: "<<(int)score<<' ';
}

void TrainingGame::print_time(float time){
    gotoxy(15,20);
    std::cout<<"time: "<<(int)time<<' ';
}
void TrainingGame::increase_score(int i){
    score+=i;
}

void TrainingGame::decrease_score(){
    score-=3;
}
float TrainingGame::get_time(){
    return time;
}
void TrainingGame::decrease_time(bool flag){
    if(flag)
        time-=0.1;
}

void TrainingGame::check_passengerPos(Wagon*& w, Passenger*& p, Obstacle o){
    int x=o.getX();
    int y=o.getY();
    for(int i=0;i<19;i++)
        if(p->get_x()==x && i>9 && i<15);
        else if(p->get_x()==x && p->get_y()==i){
            p->generate_pos();
            break;
        }
        else if(p->get_x()==x+20 && i>4 && i<10);
        else if(p->get_x()==x+20 && p->get_y()==i){
            p->generate_pos();
            break;
        }
    for(int i=0;i<w->get_size();i++){
        if(w->get_x()==p->get_x() && w->get_y()==p->get_y()){
            p->generate_pos();
            return;
        }
    }
}
void TrainingGame::passenger_collision(Wagon*& w, Passenger*& p){
    if(w->get_x()==p->get_x() && w->get_y()==p->get_y()){
        increase_score(p->get_type()+1);
        w->add_cell(p->get_type());
        p->passenger_type();
        p->generate_pos();
        start=1;
    }
}

void TrainingGame::course_collision(Wagon*& w){
    if(w->get_x()<3 || w->get_x()>56 || w->get_y()<2 || w->get_y()>18)
        decrease_score();
}

void TrainingGame::obstacle_collision(Wagon*& w,Obstacle o){
    int x=o.getX();
    int y=o.getY();
    for(int i=0;i<19;i++)
        if(w->get_x()==x && i>9 && i<15);
        else if(w->get_x()==x && w->get_y()==i){
            w->set_hit();
            break;
        }
        else if(w->get_x()==x+20 && i>4 && i<10);
        else if(w->get_x()==x+20 && w->get_y()==i){
            w->set_hit();
            break;
        }
}
bool TrainingGame::wagon_collision(Wagon*& w){
    if(w->check_hit()){
        return 1;
    }
}

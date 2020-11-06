#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "gotoxy_setcursor.h"
#include "TrainingGame.h"
#include "TrainingCourse.h"
#include "Wagon.h"
#include "Passenger.h"
#include "Obstacle.h"
using namespace std;

void Clear(int x,int y,bool type);
int main(){
    bool start_time=0;
    int choice;
    TrainingGame game;
    WELCOME_SCREEN:game.welcome_screen();
    cin>>choice;
    switch(choice){
        case 1:{
            system("cls");
            char t;
            cout<<"\n\n  Collect 40 points before time is up"<<endl;
            cout<<"  Press any key to continue"<<endl;
            _getch();

            setcursor(0,0);
            TrainingCourse Map;
            Obstacle obs(15,1);
            Wagon* wagon=new Wagon;
            Passenger* p=new Passenger;
            char op='1';
            wagon->Move();
            p->generate_pos();
            game.check_passengerPos(wagon,p,obs);
            p->draw(p);
            Map.draw();
            obs.draw();
            game.print_score(game.get_score());
            game.print_time(game.get_time());
            while(true){
                if(_kbhit())
                    op=_getch();
                switch(op){
                    case 'w':
                    case 'W':
                    wagon->turnUp();
                    start_time=1;
                    break;

                    case 's':
                    case 'S':
                    wagon->turnDown();
                    start_time=1;
                    break;

                    case 'a':
                    case 'A':
                    wagon->turnLeft();
                    start_time=1;
                    break;

                    case 'd':
                    case 'D':
                    wagon->turnRight();
                    start_time=1;
                    break;
                }

                Clear(p->get_x(),p->get_y(),p->get_type());
                if(wagon->Move())
                   game.decrease_score();
                game.print_score(game.get_score());
                game.print_time(game.get_time());
                game.decrease_time(start_time);
                game.passenger_collision(wagon,p);
                game.check_passengerPos(wagon,p,obs);
                game.course_collision(wagon);
                game.obstacle_collision(wagon, obs);
                if(game.wagon_collision(wagon)){
                    game.game_over();
                    delete wagon;
                    delete p;
                    break;
                }
                if((game.get_score()<1 && game.started())||(game.get_score()<0) || (game.get_time()<0)){
                    game.game_over();
                    delete wagon;
                    delete p;
                    break;
                }
                if(game.get_score()>=40){
                    game.win();
                    delete wagon;
                    delete p;
                    break;
                }
                Sleep(60);
            }
        }
            break;
        case 2:
            system("cls");
            game.how_to_play();
            goto WELCOME_SCREEN;
            break;
        case 3:
            cout<<endl<<endl;
            return 0;
            break;
        default:
            goto WELCOME_SCREEN;
            break;
    }
    return 0;
}

void Clear(int x,int y,bool type){
    gotoxy(3,2);
    for(int i=0;i<18;i++){
        for(int j=0;j<49;j++){
            if((j==12 && (i<9 || i>13)) || (j==32 && (i<4 || i>8)))
                cout<<'\xBA';
            else if(j==x-3 && i==y-1){
                if(type)
                    cout<<'C';
                else cout<<'F';
            }
            else
                cout<<' ';
        }
        gotoxy(3,2+i);
    }
}


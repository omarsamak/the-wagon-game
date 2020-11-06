#include <iostream>
#include "clear.h"
#include "gotoxy_setcursor.h"
#include "TrainingCourse.h"
#include "Passenger.h"
#include "Obstacle.h"
using namespace std;

TrainingCourse::TrainingCourse(){
    length=20;width=50;
}
TrainingCourse::~TrainingCourse(){
    //dtor
}
void TrainingCourse::set_length(int l){
    length=l;
}
void TrainingCourse::set_width(int w){
    width=w;
}
int TrainingCourse::get_length(){
    return length;
}
int TrainingCourse::get_width(){
    return width;
}
 void TrainingCourse::draw(){
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
    for (int j=0; j<16; j++) {
        cout<<"\n  "<<'\xBA';
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
 }

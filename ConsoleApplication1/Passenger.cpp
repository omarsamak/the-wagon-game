#include <time.h>
#include <cstdlib>
#include "Passenger.h"

Passenger::Passenger(){
    x=0;y=0;
}
Passenger::Passenger(int x, int y){
    this->x=x;this->y=y;
}
Passenger::~Passenger(){
    //dtor
}

bool Passenger::get_type(){
    return type;
}
bool Passenger::passenger_type(){
    srand((unsigned)time(NULL));
    type=rand()%2;
    return type;
}

void Passenger::generate_pos(){
    srand((unsigned)time(NULL));
    x=rand()%48+3;y=rand()%16+2;
    //x=56;y=18;
}


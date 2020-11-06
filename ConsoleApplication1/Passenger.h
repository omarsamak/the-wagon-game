#ifndef PASSENGER_H
#define PASSENGER_H
#include "Point.h"


class Passenger:public Point{
    public:
        Passenger();
        Passenger(int, int);
        ~Passenger();
        bool get_type();
        bool passenger_type();
        void generate_pos();

    protected:

    private:
        int type;
};

#endif // PASSENGER_H

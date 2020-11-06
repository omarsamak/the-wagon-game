#ifndef WAGON_H
#define WAGON_H
#include "Point.h"

class Wagon{
    public:
        Wagon();
        ~Wagon();
        int get_x();
        int get_y();
        int get_size();
        bool check_hit();
        void set_hit();
        bool Move();
        void add_cell(int);
        void turnUp();
        void turnDown();
        void turnLeft();
        void turnRight();
    protected:
    private:
        int Size, capacity;
        char direction;
        bool hit;
        Point* cells=new Point[capacity];


};

#endif // WAGON_H

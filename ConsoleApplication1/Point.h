#ifndef POINT_H
#define POINT_H



class Passenger;
class Point{
    public:
        Point();
        Point(int x, int y);
        ~Point();
        void set_point(int x, int y);
        int get_x();
        int get_y();
        void draw(Passenger*&);
        void draw_wagonHead();
        void draw_wagon();
        void copy_position(Point p);
        bool moveUp();
        bool moveDown();
        bool moveLeft();
        bool moveRight();
    protected:
        int x,y;
    private:
};

#endif // POINT_H

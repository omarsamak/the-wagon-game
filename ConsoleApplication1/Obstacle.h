#ifndef OBSTACLE_H
#define OBSTACLE_H


class Obstacle{
    public:
        Obstacle(int,int);
        ~Obstacle();
        int getX();
        int getY();
        void draw();
    protected:

    private:
        int x, y;
};

#endif // OBSTACLE_H

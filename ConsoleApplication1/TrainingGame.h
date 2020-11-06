#ifndef TRAININGGAME_H
#define TRAININGGAME_H

class Wagon;
class Passenger;
class Obstacle;
class TrainingGame{
    public:
        TrainingGame();
        ~TrainingGame();
        void welcome_screen();
        void how_to_play();
        void game_over();
        void win();
        bool started();
        int get_score();
        void print_score(float);
        float get_time();
        void print_time(float);
        void increase_score(int);
        void decrease_score();
        void decrease_time(bool);
        void check_passengerPos(Wagon*&, Passenger*&, Obstacle);
        void course_collision(Wagon*&);
        void obstacle_collision(Wagon*&, Obstacle);
        void passenger_collision(Wagon*&, Passenger*&);
        bool wagon_collision(Wagon*&);
    protected:

    private:
        bool start;
        float score;
        float time;
};

#endif // TRAININGGAME_H

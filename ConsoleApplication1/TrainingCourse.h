#ifndef TRAININGCOURSE_H
#define TRAININGCOURSE_H


class TrainingCourse{
    public:
        TrainingCourse();
        ~TrainingCourse();
        void set_length(int);
        void set_width(int);
        int get_length();
        int get_width();
        void draw();

    protected:

    private:
        int length,width;
};
#endif // TRAININGCOURSE_H

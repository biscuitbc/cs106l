#ifndef CLASS_H
#define CLASS_H


class Student{
    public:
    void setage(int Age);
    int getage() const;

    Student();
    Student(int Age, int score);

    private:
    int age, score;
    bool validAge(int Age) const;
};

#endif
#include "class.h"

void Student::setage(int Age)
{
    if(validAge(Age)) age = Age;
}

int Student::getage() const 
{
    return age;
}

bool Student::validAge(int Age) const 
{
    return Age >= 0 && Age <= 150;
}

Student::Student() : age(0), score(0) {}

Student::Student(int Age, int score) : age(0), score(score) { setage(Age); }  
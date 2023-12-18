#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
        int age;
        const int rollNo;
        int &x; // reference variable of age
        Student(int r, int age) : rollNo(r), age(age), x(this->age){     // initialization list
            // rollNo = r;
        }
};

int main(){
    Student s(1,10);
    s.age = 10; // has no error
    //s.rollNo = 1;
}

/*
    Initialisation list is used to initialize constant data 
    members of the class at the time of memory allocation.

    Whenever we have constant data members it is compulasary 
    to make constructor and initialization list to initialize them.

    Even reference variables should be initialized in the initialization list.

    Even non-constant data members can be listed in initialisation list.

    It is not necessary to use "this" in case the name of data member and parameter is same.

    So here age(age)
    this->age is outside, the parameter is in braces.
*/
#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
        int rollNo;
        int age;
        static int totalStudents; //  static property

        Student(int rollNo, int age){
            this->rollNo = rollNo;
            this->age = age;
            totalStudents++;
        }

        int getRollNo(){
            return rollNo;
        }

        // STATIC FUNCTIONS
        static int getTotalStudent(){ 
            // to be static cause it returns a static property.
            return totalStudents;
        }
};

int Student :: totalStudents = 0; // initialize static data members

int main(){
    Student s1(1, 12);
    cout<< s1.getRollNo()<<" "<<s1.age<<endl;
    cout<< Student :: getTotalStudent() <<endl; // method to access static functions
}

/*
    The static properties belong to the class and not object.
    It doesnt belong to the object.
    Static attributes are accessed through ::
    Static functions can access only static properties=> data member or member functions
    'this' keyword isnt accessible in static functions
*/


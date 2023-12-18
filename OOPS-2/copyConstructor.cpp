#include<bits/stdc++.h>
using namespace std;

class Student{
    private:
        int age;
        // dont create strings/ char arrays statically
        
        public:
        char *name;
            Student(int age, char *name){
            this->age = age;
            this->name = name; // shallow copy - to be avoided
            // deep copy
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name); // copying strings
        }

        
        Student(Student const &s){    // pass by reference
        // to prevent changes from occuring in obj s we can make it constant
            this->age = s.age;
            //this->name = s.name; // shallow copy

            // DEEP COPY:
            this->name = new char[strlen(s.name) + 1];
            strcpy(this->name, s.name);
        }

        void display(){
            cout<< "Name: "<< name<<" Age: "<<age<<endl;
        }
};

int main(){
    char name[] = "Anu";
    Student s1(10, name); // pass by value
    s1.display();

    name[2]='y';
    Student s2(24, name); // pass by value
    s2.display();
    s1.display();
    Student s3(s1); // pass by value
    s3.display();
}

/*
    In-built copy constructor is shallow copy by default
    but it takes a constant reference only
    //Student(Student s){ // values are passed by value so implicitely we are calling copy constructor[default is shallow copy]
        // however as soon as we create our own copy constructor, our constructor is called by default
        // so in this case a whole new copy is made of s
        // to prevent this we can call by reference instead of value
*/
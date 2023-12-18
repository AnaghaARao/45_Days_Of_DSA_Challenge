#include<bits/stdc++.h>
using namespace std;

class Student{
    private:
        int age;
        // dont create strings/ char arrays statically
        char *name;

        public:
            Student(int age, char *name){
            this->age = age;
            this->name = name; // shallow copy - to be avoided
            // deep copy
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name); // copying strings
        }

        void display(){
            cout<< "Name: "<< name<<" Age: "<<age<<endl;
        }
};

int main(){
    char name[] = "Anu";
    Student s1(10, name);
    s1.display();

    name[2]='y';
    Student s2(24, name);
    s2.display();
    s1.display();
}
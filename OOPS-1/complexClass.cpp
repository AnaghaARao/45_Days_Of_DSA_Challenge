/**********
 
Following is the main function we are using internally.
Refer this for completing the ComplexNumbers class.
 
 
int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }
    
}
 
 ************/
#include<bits/stdc++.h>
using namespace std;

class ComplexNumbers {
    // Complete this class
    private: 
        int real , imaginary;
    public:
        ComplexNumbers(float real, float imaginary){
            this->real = real;
            this->imaginary = imaginary;
        }
        void plus(ComplexNumbers c2){
             // very important to store in TEMPORARY VARIABLES
            // else remaining ans will be wrong
            // DONT WRITE: int real = real + c2.real; ==> real will have garbage value -> wrong answer
            int real = this->real+c2.real;
            int imaginary = this->imaginary+c2.imaginary;
            this->real = real;
            this->imaginary = imaginary;
        }
        void multiply(ComplexNumbers c2){
            // very important to store in TEMPORARY VARIABLES
            // else remaining ans will be wrong
            int real = this->real*c2.real - this->imaginary*c2.imaginary;
            int imaginary = this->real*c2.imaginary + this->imaginary*c2.real;
            this->real = real;
            this->imaginary = imaginary;
        }
        void print(){
            cout<<real<<" + i"<<imaginary<<endl;
        }
    
};
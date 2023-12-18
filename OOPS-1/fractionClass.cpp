#include<bits/stdc++.h>
using namespace std;

class Fraction{
    private:
        // data members
        int numerator;
        int denominator;
    public:
        // parameterized constructor
        Fraction(int numerator, int denominator){
            this->denominator = denominator;
            this->numerator = numerator;
        }

        // printing()
        void print() {
            // data members of the calling function
            // SAME AS BELOW: cout << this->numerator <<"/"<< this->denominator<<endl;
            cout << numerator <<"/"<< denominator<<endl;
        }

        void simplify(){
            int gcd = 1;
            int x = min(numerator,denominator);
            for(int i = x; i>=1;i--){
                if(numerator%i==0 && denominator%i==0){
                    gcd = i;
                    break;
                }
            }
            numerator = numerator/gcd;
            denominator = denominator/gcd;
        }

        // function to add:
        void add(Fraction const &f2){
            // void add(Fraction f2)
            // the fraction f2 here is created as: Fraction f2 = main.f2;
            // basically f2 here is a copy constructor
            // to prevent this we do pass by reference instead of pass by value
            // we make this reference constant to prevent it from undergoing any changes


            int lcm = this->denominator * f2.denominator;
            int x = lcm / this->denominator;
            int y = lcm / f2.denominator;

            int num = x * numerator + (y * f2.numerator);
            
            numerator = num;
            denominator = lcm;

            simplify();
        }

        void multiply(Fraction const &f2){
            numerator = numerator*f2.numerator;
            denominator = denominator*f2.denominator;

            simplify();
        }

};

int main(){
    Fraction f1(10,2);
    Fraction f2(15,4);
    f1.print();
    f2.print();
    f1.add(f2);
    f1.print();
    f2.print()
}
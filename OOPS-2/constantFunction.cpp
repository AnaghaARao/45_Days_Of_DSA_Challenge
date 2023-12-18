#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

class Fraction{
    private:
        // data members
        int numerator;
        int denominator;
    public:

        Fraction(){

        }
        // parameterized constructor
        Fraction(int numerator, int denominator){
            this->denominator = denominator;
            this->numerator = numerator;
        }

        void setNumerator(int numerator){
            this->numerator = numerator;
        }

        void setDenominator(int denominator){
            this->denominator = denominator;
        }

        int getNumerator() const{ // const functions
            return numerator;
        }

        int getDenominator() const{ //const functions
            return denominator;
        }

        // printing()
        void print() { // const functions
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
    const Fraction f3; // constant object
    cout<<f3.getNumerator()<<" "<<f3.getDenominator()<<endl;
    f1.print();
    f2.print();
    f1.add(f2);
    f1.print();
    f2.print();
}

/*
    We can create constant objects of a class.
    Properties of a constant object can be changed.
    Constant objects can call only constant functions
    Constant functions are those that dont change any property of the current object.
*/
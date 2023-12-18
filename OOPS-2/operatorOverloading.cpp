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

        // OPERATOR OVERLOADING!!

        // to overload a particular operator the syntax is:
        // change the function to operator<symbol>(){}
        Fraction operator+(Fraction const &f2) const {
            int lcm = this->denominator * f2.denominator;
            int x = lcm / this->denominator;
            int y = lcm / f2.denominator;
            int num = x * numerator + (y * f2.numerator);
            // numerator = num;
            // denominator = lcm;
            Fraction f(num, lcm);
            f.simplify();
            return f;
        }

        // operator overloading function: *
        Fraction operator*(Fraction const &f2) const {
            int n = numerator*f2.numerator;
            int d = denominator*f2.denominator;
            Fraction f(n,d);
            f.simplify();
            return f;
        }

        //operator overloading function: ==
        bool operator==(Fraction const &f2) const{
            return (numerator==f2.numerator && denominator==f2.denominator);
        }

        //unary operator overloading function: ++ 
        // 2 options: pre/post increment
        // we are doing pre-increment
        Fraction& operator++(){
            // by making the return a reference the changes done is 
            // reflected on the calling object as well as assigned object.
            // remove & and see o/p to understand
            numerator = numerator+denominator;
            simplify();
            return *this; // means we are returning the whole object
        }

        // POST increment operator overloading :
        Fraction operator++(int){
            Fraction f(numerator, denominator); // copied to new fraction
            numerator = numerator+denominator; // changes reflected only for calling obj
            simplify();
            f.simplify();
            return f;
        }

        // operator overloading +=:
        Fraction& operator+=(Fraction const &f2){
            int lcm = this->denominator * f2.denominator;
            int x = lcm / this->denominator;
            int y = lcm / f2.denominator;
            int num = x * numerator + (y * f2.numerator);
            numerator = num;
            denominator = lcm;
            simplify();
            return *this; // to ensure nestin we send a reference
        }
};

int main(){
    Fraction f1(10,2);
    Fraction f2(15,4);
    f1.print();
    f2.print();
    Fraction f3 = f1+f2;
    Fraction f4 = f1*f2;
    f1.print();
    f2.print();
    f3.print();
    f4.print();
    if(f3==f4){
        cout<<"Equal"<<endl;
    }else{
        cout<<"Not equal"<<endl;
    }
    Fraction f5 = ++(++f1);
    f1.print();
    f5.print();
    Fraction f6 = f2++;
    f2.print();
    f6.print();
}

// nesting on post-increment is not allowed: eg: (i++)++ -> ERROR
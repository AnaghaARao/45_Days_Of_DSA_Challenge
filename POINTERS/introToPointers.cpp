#include<bits/stdc++.h>
using namespace std;

int main(){
    int i;
    cout<< &i << endl;
    int *p = &i;
    // INTERPRETATION: p is a pointer to i
    cout<< p <<endl;

    // To access value using address:
    cout<< *p <<endl;
    // here * is a dereference operator

    // size of p[depends on the compiler but is usually is 8 bytes]:
    cout<< sizeof(p)<<endl;

    i++;

    cout<< i <<endl;
    cout<< *p <<endl;

    int a  = i;
    a++;

    // changing a doesnt change i or p
    // this is cause a has only a copy of i
    // while p is sharing the original address of i
    cout<< a <<endl;
    cout<< i <<endl;
    cout<< *p <<endl;

    int b = *p;
    b++;

    cout<< b <<endl;
    cout<< i <<endl;
    cout<< *p <<endl; 

    //CONCLUSION: i & p are 2 ways of accessing the same variable   

    // q is pointing to the address of i itself
    int *q = p;
    // therefore, i, *p, *q are 3 ways to access the same memory space


    // very risky thing to do
    // it may be trying to access restricted memory
    // always declare as null pointer in case of not pointing to anything else
    /*
        int *p;
        cout<< p <<endl;
        cout<< *p <<endl;
        (*p)++;
    */
    int *p=0;
    cout<< p <<endl;
    cout<< *p <<endl;
    (*p)++;
    cout<< *p <<endl;








    // eg of few valid pointers:
    float f = 10.2;
    float *fp = &f;

    double d = 12.32;
    double *dp = &d;
}

/* 
    1. A symbol table is used to store the address of each variable
    2. & is used to access this address
    3. address is an hexadecimal value
    4. pointers are variables which store address of other variables
*/
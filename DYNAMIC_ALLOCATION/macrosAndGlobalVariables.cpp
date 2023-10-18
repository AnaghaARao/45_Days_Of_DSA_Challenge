#include<bits/stdc++.h>
using namespace std;
#define PI 3.14

// global variable
int a;

void g(){
    cout << a << endl; //11
    a++;
    cout << a << endl; //12
}

void f(){
    cout << a << endl; //10
    a++;
    g();
}

int main(){
    cout<< PI * 10 * 15 << endl;
    a = 10;
    f();
    cout << a << endl; //12
}

/*
    1. #define
     - using 3.14 as it is: makes it difficult to change the value later
     - using varible: easily changeable and has performance issues
     combination of both these features is utilized using #define
     #define is used to compile these values before any function os compiled
     eg: #define PI 3.14 //along with header
        cout<< PI * r * r << endl; //in function

    2. gloabal variables - very bad practice
    this is cause any function can change these varibles

    for argument sharing use reference varaibles
*/

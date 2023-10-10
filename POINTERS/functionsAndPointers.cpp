/* This file is about functions and pointer and how they work together*/

#include<bits/stdc++.h>
using namespace std;

void print(int* p){
    cout << *p <<endl;
}

void incrementPointer(int* p){
    p = p + 1;
}

void increment(int* p){
    (*p)++;
}

/* 
    can also declare this as:
    int sum(int a[] , int size){

    }
*/

int sum(int *a , int size){
    // prints 8 like that of a pointer
    cout<< sizeof(a) << endl;
    int ans = 0;
    for(int i = 0 ; i < size ; i++){
        ans += a[i];
    }
    return ans;
}

int main(){
    int i = 10;
    int *p = &i;

    print(p);


    // the value of p doesn't change after calling the function 
    // this is because the function only has a copy of the variable/pointer being passed
    // => PASS BY VALUE
    cout<< p << endl;
    incrementPointer(p);
    cout<< p << endl;

    // value referenced by pointer increases
    // this is because the address accessed by the variable in the function
    // is the actual address itself
    // and the function is making changes to the variable pointed by p
    cout<< *p << endl;
    increment(p);
    cout<< *p << endl;

    /* FUNCTIONS AND ARRAYS:    */
    int a[10];
    // prints 40 like that of an array
    cout<< sizeof(a)<<endl;
    cout << sum(a,10) << endl;
    /* We can pass arrays to functions and they effectively work like pointers */
    // the major advantage would be we can pass a part of the array to the function
    // like this

    cout<< sum(a+5 , 5) << endl;
}
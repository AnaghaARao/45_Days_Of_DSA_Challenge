/* This file is about double pointer or pointer to a pointer */

#include<bits/stdc++.h>
using namespace std;

// the changes made by this function isnt reflected
void increment1(int** p){
    p = p + 1;
}

// the changes made by this function is reflected
// p now points to the next address of the pointer it was pointing to
void increment2(int** p){
    *p = *p + 1 ;
}

// the changes made by this function is reflected
// the value pointed by the pointer this pointer is pointing to is increment by 1
void increment3(int** p){
    **p = **p + 1 ;
}

int main(){
    /* 
    generic rule for creating pointers:(datatype)* pointer_varible_name
    */
    int i = 10;
    int* p = &i;
    int **pp = &p;

    cout<< pp << endl;
    cout<< &p << endl;

    cout<< &i << endl;
    cout<< p << endl;
    cout<< *pp << endl;

    cout << i << endl;
    cout << *p << endl;
    cout<< **pp << endl;
}
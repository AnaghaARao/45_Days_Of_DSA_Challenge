#include<bits/stdc++.h>
using namespace std;

void f(const int * p){
    //(*p)++; // error
}

int main(){
    int i = 10;
    i = 12; // the data of this storage space is changeable
    // however we can declare any variable const => makin it unchangeable
    const int j = 10;
    j=12; 
    

    // CONSTANT REFERENCE FROM A NON-CONSTANT INT
    int x = 12;
    const int& y = x; // only the path is made constant ; not the storage
    y++; // error
    x++;

    // CONSTANT REFERENCE FROM A CONSTANT INT
    int const j2 = 12;
    int const &k2 = j2;
    j2++; // error
    k2++; // error
    // both path and variable are to be constant and unchangeable

    //REFERENCE FROM A CONST INT
    int const j3 = 123; // this is read-only value
    int& k3 = j3; // error // this indicates that the read-only value can also be changed
    // const variable can have only const reference

    int const i1 = 10;
    //int* p = &i1; 
    int const * p = &i1;
    //(*p)++; // error

    int j1 = 12;
    int const * p2 = &j1; // allowed // but cant change value thro p2
    int * p3 = &j1; // allowed // can change the value

    f(p3);

    // constant pointers:
    int m = 12; int n = 10;
    int const *p4 = &m; // p4 is a pointer to a const integer
    p4 = &n;
    int * const p5 = &m;// p5 is a constant pointer to int
    p5 = &n; // error 



    /*
        LINE 10 - 13:
        // results in error:- error: assignment of read-only variable 'j'
        //const int k ; // at this stage k is assigned a garbage value
        //k = 10;
        // this also results in an error...const varaibles shd be declared and initialized simultaneously
        // error 1 :uninitialized 'const k' [-fpermissive]
        // error 2 :uninitialized 'const k' [-fpermissive]
        // similar to reference variable

        LINE 16-20:
        // to methods of accessing the storage unit is through x and y
        // the method to access the location through y is constant => y++ is hence an error
        // the location can be accese and modified through non-constant approach => x ==> hence not an error

        LINE 37:
        // address of a const int can't be stored in a normal pointer
        // even the pointer shd be const
    */

    


}
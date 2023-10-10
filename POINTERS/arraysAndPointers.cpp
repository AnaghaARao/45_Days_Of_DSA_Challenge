#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[10];
    /* 
        meaning of this declaration:
        1. We are allocating 40 bytes of memory
        2. We name this block as a
        3. The symbol table entry corresponding to a is 
            the starting address of a or address of a[0]
    */
   cout<< a <<endl;
   cout<< &a[0] <<endl;

   // to indicate that a doesnt have a seperate memory location
   int *p = &a[0];
   cout<<a<<endl;
   cout<<p<<endl;

   cout<<&a<<endl;
   cout<<&a<<endl;

   p = p+1;
   //a = a+1; isn't allowed
   p = a+1; // this is allowed

   // to demonstrate array's pointer-like behaviour
   a[0] = 5;
   a[1] = 10;
   cout<< *a <<endl;
   // O/P is 5...ie, a is behaving like a pointer
   cout<< *(a+1) <<endl;
   cout<< (a+1) <<endl;
}

/* 
    DIFFERENCE BETWEEN ARRAY AND POINTERS:
        1. sizeof(): 
            sizeof(pointer): 8 or depends on compiler
            sizeof(array): sizeof(datatype)*number of elements => 40 in this case
        2.  Pointer variable is allocated 8 bytes of memory
            Array Name or Variable is not allocated any such memory
        3.  & operator:
            &p return the address of pointer variable
            &arr returns the address of arr[0]
            therefore cout<<a<<" "<<&a<<endl; return the same values
        4.  Arithmetic operations can't be done on the arrays
            This is because the value of arr is set and cant be changed
            ie, arr is a constant type of sorts.
*/
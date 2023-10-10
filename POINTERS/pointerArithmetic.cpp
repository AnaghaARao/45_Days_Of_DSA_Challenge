#include<bits/stdc++.h>
using namespace std;

int main(){
    int i = 10;
    int *p = &i;

    /* what can possibly happen wrt the following code?
        1. it adds 1 to the integer its pointing to
        2. points to the next address without bothering whether the next address 
        is of an integer or not
    */
    cout<< p << endl;
    cout<< *p <<endl;
    p = p+2;
    cout<< p << endl;
    cout<< *p <<endl;

    /* 
        where will such an operation be useful?
        they will be useful only for contiguous memory allocation: ARRAY
        operations like p1<p2 are alse valid and useful only for arrays 
    */

   double d = 100.2345;
   double *dp = &d;
   cout<< dp <<endl;
   cout<< *dp <<endl;
   dp++;
   cout<< dp <<endl;
   cout<< *dp <<endl;

    
}
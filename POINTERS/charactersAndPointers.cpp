/* This file is about character pointers */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {1,2,3};
    char b[] ="abc";

    // this prints address of a
    cout<< a << endl;
    // this prints content of b
    cout<< b << endl;

    char c1 = 'a';
    char *pc = &c1;

    cout<< c1 << endl;
    // the pointer prints all the content till it finds anull character
    // this is how cout works for character pointer
    cout<< pc << endl;

    // difference between string array and character pointer:
    
    // A memory space is created for the variable and allocated to str[]
    // in this case the array automatically terminates the string with null character
    // like this: abcde\0
    char str[] = "abcde";
    // this is a pointer is pointing to a temporary memory
    // ie, a temporary memory is made to store abcde
    // and the pointer is accessing the temporary memory itself
    // this is dangerous and wrong
    char* pstr = "abcde";

}
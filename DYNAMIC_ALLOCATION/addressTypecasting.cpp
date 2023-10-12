#include<bits/stdc++.h>
using namespace std;

int main(){
    int i = 65;
    char c = i ; // implicit typecating
    cout << i << endl;
    cout << c << endl;

    int* p = &i;
    char* pc = (char*)p; //explicit typecasting

    cout << p << endl; // prints address
    cout << pc << endl; //prints only A as next byte has null character

    cout << *p << endl;
    cout << *pc << endl;
    cout << *(pc+1) << endl; // printed 0
    cout << *(pc+2) << endl; // printed 0
    cout << *(pc+3) << endl; // printed 0
    /* 
        therefore the method of storing integer is 
        placing least significant byte first
        this is known as little endian method
        so 65 will be stored like : |65|0|0|0|->the sign bit is placed at the end
    */
}

/* 
    QUESTIONS ALERT !!
    why datatype * ptr = &i;
    why not pointer * ptr = &i;
    Ans: To know how many bytes to read and 
         how to interpret the memory accessed by the pointer
*/
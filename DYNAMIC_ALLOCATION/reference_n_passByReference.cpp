#include<bits/stdc++.h>
using namespace std;

void increment(int& x){
    x++;
}

// bad practice
int& f(int n){
    int a = n;
    return a;
}

int main(){
    int i = 10;
    int j = i;
    i++;
    cout<< j << endl;
    // these 2 are unrelated variables so change in one
    // doesnt affect the other
    int& k = i;
    // here k is a reference variable to i
    // k and i are 2 ways of accessing the same memory location
    i++;
    cout<< k <<endl;
    // k = j is not possible

    // utilizing in function calling:
    increment(i);
    cout<< i << endl;

    int& x = f(i);
}

/*
    NOTES:
    1. int &j;
        j = i; => NOT ALLOWED
        => so declaration and initialization should be done together
    2. where is this used?
        in function calling & function parameters
        here functions can share their local variables
    3. data can be returned by reference as well
        but there can be a huge problem here
        if we are returned a reference of a function then 
        the scope of the variable is only in the function => 
        once we return to the calling function we will be trying 
        to access a non-existing memory => which is dangerous
    4. an address can be returned by a function as well
        but this address may not be existing or it can contain garbage data

    CONCLUSION: eturning reference of pointer from a function is a bad practice
                it may go wrong very badly if not done properly
*/
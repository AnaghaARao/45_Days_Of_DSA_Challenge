#include<bits/stdc++.h>
using namespace std;

// avoided repetation on code
int max(int a , int b){
    return (a>b)?a:b;
}

// to improve code readability without compromising on performance
// by declaring as inline - 
// wherever the function is called the statement is replaced by the body of the function automatically by the compiler
inline int max1(int a , int b){
    return (a>b)?a:b;
}

int main(){
    int a , b ;
    cin >> a >> b ;

    int c = (a>b)?a:b; // tertiary operator
    // avoided repetation on code
    int d = max(a,b); // increases code readability // hit on performance
    int ans1 = max1(a,b); // best option
    int x = 12 , y = 34 ;
    int z = (x>y)?x:y; // tertiary operator
    int ans2 = max1(x,y); // best options
    
}

/*
    why all functions are not defined inline?
    -large functions give our heavy output package
    - compiler determines whether a function can be inline or not
*/
#include<bits/stdc++.h>
using namespace std;

void printnto1(int n){
    // base case
    if(n < 1) return;
    // induction step
    cout<< n << endl;
    // recursive calls
    printnto1(n-1);
}

int main(){
    printnto1(6);
}

/*
    base case 1: if n is 1 then print 1 and exit
    base case 2: if n is 0 then print nothing and exit => EASIER
    function will take care of n-1 to n
    we need to take care of f(n) => induction step
    => print n first then recursively call for n-1 to 1
    => base case will handle the termination

    Note: always start from base case in the function then 
        go ahead with other steps in required order.
*/
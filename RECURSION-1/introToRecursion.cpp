#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    /*
        int smallOutput = factorial(n-1);
        return n*smallOutput;
        This leads to segmentation fault => no terminating statement
    */
    if(n==1) return 1; //terminating statement
    int smallOutput = factorial(n-1);
    return n*smallOutput;
}

int main(){
    int n;
    cin>>n;
    cout<<factorial(n)<<endl;
}

/*
    we use recursion whenever the solution to a big problem 
    depends on a smaller problem's solution
        eg: n! = n*(n-1)!
                or
        fact(n) = n*fact(n-1)
        fact(n-1) = n-1*fact(n-2)
        ...
        fact(1) = 1

    CALL STACK IS USED IN THE WORKING OF THE RECURSION
    main() is the first function to enter this stack &
    the last function to exit this stack
*/
/*
    Multiplication(Recursive):
    given 2 integers M & N, calculate and return their multiplication using recursion.
    You can only use subtraction and addition for your calculations. No other operations are allowed.
*/

#include<bits/stdc++.h>
using namespace std;

int multiplyNumbers(int m, int n) {
    // base case:
    if(n==0) return 0;
    // induction step and recursion call
    int smallAns = m + multiplyNumbers(m,n-1);
    return smallAns;
}
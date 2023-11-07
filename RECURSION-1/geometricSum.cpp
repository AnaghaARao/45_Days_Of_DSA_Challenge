/*
    Geometric Sum:
    Given k, find the geometric sum,ie,
    1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) using recursion
*/

#include<bits/stdc++.h>
using namespace std;

int power(int n , int k){
    // base case
    if(k==0) return 1;
    // inductions step:
    int smallAns = n * power(n,k-1);
    return smallAns;
}

double geometricSum(int k) {
    // Write your code here
    // base case:
    if(k<0) return 0;

    // induction step
    double smallAns = 1.0/power(2,k) + geometricSum(k-1);
    // writing 1.0 / power(2,k) is very imp
    // else it becomes an int type of ans
    return smallAns;
}
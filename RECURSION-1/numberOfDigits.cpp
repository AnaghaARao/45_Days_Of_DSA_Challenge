/*
    PROBLEM STATEMENT:
    Number of Digits
    You are given a number 'n'.
    Return number of digits in 'n'.
*/
#include<bits/stdc++.h>
using namespace std;

int countDigits(int n){
    // base case
    if(n==0) return 0;
    // recursive call and induction step
    int smallAns = countDigits(n/10)+1;
    return smallAns;
}
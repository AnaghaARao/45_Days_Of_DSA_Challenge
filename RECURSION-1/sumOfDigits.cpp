/*
    Sum of Digits
    Write a recursive function that returns the sum of digits of a given integer
*/

#include<bits/stdc++.h>
using namespace std;

int sumOfDigits(int n){
    // base case
    if(n==0) return 0;

    // induction step and recursive call
    int smallAns = n%10 + sumOfDigits(n/10);

    return smallAns;
}
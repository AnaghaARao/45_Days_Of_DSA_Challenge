/*
    Count Zeros:
    Given an integer N, count & return the number of zeros 
    that are present in the given integer using recursion.
*/

#include<bits/stdc++.h>
using namespace std;

int countZeros(int n) {
    // base case:
    if(n==0) return 1;
    // for condition where n is originally 0

    // induction step and recursive call
    if(n/10==0) return countZeros(n/10)-1;
    // for condition when n is not originally 0
    if(n%10 == 0) return 1 + countZeros(n/10);
    else return countZeros(n/10);   
}
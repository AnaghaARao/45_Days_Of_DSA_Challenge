// A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. 
// For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.
// Given a string n that represents a positive decimal integer, return the minimum number of positive 
// deci-binary numbers needed so that they sum up to n.

// Approach:
// the largest digits in the number should be returned

#include<bits/stdc++.h>
using namespace std;

int minPartitions(string n) {
    char c = '0';
    for(char x : n){
        if(x>c) c= x;
        if(x == '9') return 9;
    }
    int ans = int(c)-48;
    return ans;
}
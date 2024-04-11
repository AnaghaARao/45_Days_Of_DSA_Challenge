/* You are given a 0-indexed string num representing a non-negative integer.
In one operation, you can pick any digit of num and delete it. Note that if you delete all the digits of num, num becomes 0.
Return the minimum number of operations required to make num special.
An integer x is considered special if it is divisible by 25. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(string num) {
        
    }
};

Divisibility rule of 25:
if the last two digits of a number are zeroes or the number formed by the last two digits is a multiple of 25, 
then the number is divisible by 25.
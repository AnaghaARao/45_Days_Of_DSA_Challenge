/* You are given a string number representing a positive integer and a character digit.
Return the resulting string after removing exactly one occurrence of digit from number such that 
the value of the resulting string in decimal form is maximized. 
The test cases are generated such that digit occurs at least once in number. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) {
        string res="";
        int n = number.size();
        for(int i = 0 ; i < n ; i++){
            if(number[i]==digit){
                string temp = number.substr(0,i) + number.substr(i+1, n);
                res = max(res,temp);
            }
        }
        return res;
    }
};

// Approach:
// check for all possible numbers and return the one with max value
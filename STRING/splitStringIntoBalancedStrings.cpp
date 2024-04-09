/* Balanced strings are those that have an equal quantity of 'L' and 'R' characters.
Given a balanced string s, split it into some number of substrings such that:
Each substring is balanced.
Return the maximum number of balanced strings you can obtain. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0 , x = 0;
        for(char c : s){
            if(c == 'L') x++;
            else x--;

            if(x == 0) cnt++; // when equal number of 'L' & 'R' are encountered cnt is increased
        }
        return cnt;
    }
};
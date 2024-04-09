/* You are given a 0-indexed string s of even length n. 
The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.

A string is called balanced if and only if:
    It is the empty string, or
    It can be written as AB, where both A and B are balanced strings, or
    It can be written as [C], where C is a balanced string.
You may swap the brackets at any two indices any number of times.
Return the minimum number of swaps to make s balanced. */


// Counting Approach:

// Count the number of opening '[' brackets and closing ']' brackets.
// If the counts are not equal, it's impossible to balance the string, return -1.
// Iterate through the string and keep track of the current imbalance (number of opening '[' brackets encountered minus number of closing ']' brackets encountered).
// Each time an imbalance occurs (imbalance becomes negative), count it as a swap required to balance the string.
// Return the total number of swaps counted.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int cnt = 0 , res;
        for(char c : s){
            if(c=='[') st.push(c); // if char is [ then we push onto stack
            else{
                if(st.empty()) cnt++; // if stack is empty then this is imbalanced ] ... therefore we increase the cnt
                else st.pop(); // we pop [ from stack because it has a corresponding ] as well
            }
        }

        // After processing all characters in the string, divide cnt by 2 and assign the result to res. 
        // This is because each swap resolves two excess closing brackets.
        // If cnt is odd (i.e., cnt % 2 == 1), it means there's an odd number of excess closing brackets. 
        // In this case, an additional swap is required to balance the string. So, increment res by 1.
        res = cnt/2; 
        if(cnt%2) res++; 
        return res; // return res
    }        
};


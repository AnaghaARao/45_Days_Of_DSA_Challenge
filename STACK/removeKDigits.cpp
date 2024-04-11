/* Given string num representing a non-negative integer num, and an integer k, 
return the smallest possible integer after removing k digits from num. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k>= num.size()) return "0";
        stack<char> st;
        for(char n : num){
            while(!st.empty() && st.top()>n && k>0){ // order of conditions matter!!
                st.pop();
                k--;
            }
            st.push(n);
        }

        while(k>0){
            st.pop();
            --k;
        }

        // Forming the number from the stack
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());

        // Remove leading zeros [THIS IS AMAZING]
        size_t start_pos = res.find_first_not_of('0');
        if (start_pos != string::npos) {
            res = res.substr(start_pos);
        } else res = "0";

        return res;
    }
};

// Initialize a stack: The stack will be used to keep track of the digits in a greedy manner. 
// The stack will contain the digits of the number in increasing order from the bottom to the top.

// Iterate over the digits of num: As you iterate over each digit in the string, compare it with the top of the stack:
// If the current digit is smaller than the top digit of the stack and there are still digits left to remove (k > 0), 
// remove the top digit from the stack (pop it) to form a smaller number, and decrease k by 1.
// Push the current digit onto the stack.

// Handle any remaining k: After processing all the digits in num, there may still be some remaining k 
// (if you haven't removed enough digits). If so, remove the top k digits from the stack.

// Form the resulting number: The digits left in the stack will form the smallest possible integer. Convert the stack to a string.

// Remove leading zeros: Convert the string to remove any leading zeros, except for a single zero if the result is empty.

// Return the result: The final result is the smallest possible integer after removing k digits.
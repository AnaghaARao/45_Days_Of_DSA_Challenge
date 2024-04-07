/* Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:
    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "". */

#include<bits/stdc++.h>
using namespace std;


// Approach:
// We traverse the string from left to right, maintaining two counters, low and high, representing the range of possible open parentheses.
// For each character encountered:
// If it's '(', both counters increase by 1.
// If it's ')', low decreases by 1, and high decreases by 1 unless low is already zero.
// If it's '*', low decreases by 1 (if possible) and high increases by 1.
// If at any point high becomes negative, it means there are too many ')' characters without matching '('. 
// In such a case, the string is invalid, and we return false.
// After traversing the string, if low is not zero, it means some '(' were not matched, making the string invalid.
// Return true if low is zero, indicating that all parentheses were matched.


class Solution {
public:
    bool checkValidString(string s) {
        int low = 0 , high = 0;
        for(char c : s){
            if(c=='(') {
                low++;
                high++;
            }
            else if(c==')'){
                if(low>0) low--;
                high--;
            }
            else if(c=='*'){
                if(low>0) low--;
                high++;
            }
            if(high<0) return false;
        }

        if(low!=0) return false;
        return true;
    }
};

// This line initializes two variables low and high to keep track of the range of possible counts of opening '(' brackets.
// low represents the minimum count of '(' brackets needed to match all ')' brackets so far.
// high represents the maximum count of '(' brackets needed to match all ')' brackets so far.
// This line starts a loop that iterates through each character c in the given string s.
// If the current character c is '(', it means we encounter an opening '(' bracket.
// Both low and high are incremented because we have encountered a new opening '(' bracket.
// If the current character c is ')', it means we encounter a closing ')' bracket.
// If there are unmatched '(' brackets (low > 0), we decrement low to indicate that one ')' bracket has been matched with a previous '(' bracket.
// We always decrement high to indicate that a closing ')' bracket has been encountered, regardless of whether there was an unmatched '(' bracket.
// If the current character c is '*', it means it could be treated as either '(' or ')'.
// If there are unmatched '(' brackets (low > 0), we decrement low to indicate that we can use '*' as a '(' bracket to match it.
// We always increment high when encountering '' because '' could also represent an unmatched '(' bracket.
// At each step, we check if high becomes negative.
// If high becomes negative, it means there are more closing ')' brackets than the sum of matched '(' brackets and '' characters encountered so far. 
// This violates the rule that ')' brackets must not exceed the total number of matched '(' brackets and '' characters.
// After processing all characters in the string, if low is not zero, it means there are unmatched '(' brackets left in the string. 
// This violates the rule that all '(' brackets must be matched with ')' brackets or '*' characters.
// So, we return false if low is not zero.
// If the code execution reaches this point, it means all checks for validity have passed, and the string is valid according to the given rules. 
// Hence, we return true.
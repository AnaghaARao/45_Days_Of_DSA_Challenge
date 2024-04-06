/* Given a string s of lower and upper case English letters.
A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

0 <= i <= s.length - 2
s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
To make the string good, you can choose two adjacent characters that make the string bad and remove them. 
You can keep doing this until the string becomes good.
Return the string after making it good. The answer is guaranteed to be unique under the given constraints.
Notice that an empty string is also good. */


/* 
    Approach
    1. Initialize an empty stack.
    2. Iterate through each character in the input string.
    3. For each character, check if it forms a bad pair with the top character of the stack. 
        If it does, pop the character from the stack.
    4. If the character doesn't form a bad pair, push it onto the stack.
    5. Finally, join the characters left in the stack to form the resultant string.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeGood(string s) {

        stack<char> temp;
 
        for(char c : s){
            if(!temp.empty() && abs(temp.top()-c)==32) temp.pop();
            else temp.push(c);
        }

        string res="";

        while(!temp.empty()){
            res = temp.top() + res;
            temp.pop();
        }
        return res;
    }
};


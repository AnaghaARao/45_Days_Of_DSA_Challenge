/*  Given a string s of '(' , ')' and lowercase English characters.
Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string. */

#include<bits/stdc++.h>
using namespace std;

// Stack-based Approach:
// Traverse the string character by character.
// Use a stack to keep track of the indices of opening parentheses '('.
// When encountering a closing parenthesis ')', if there is a matching opening parenthesis on the stack, remove both the opening and closing parentheses. Otherwise, mark the closing parenthesis for removal.
// After traversing the entire string, remove the marked parentheses.
// NOTE: RESULTED IN MEMORY LIMIT EXCEEDED ERROR
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> *index = new stack<int>();
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i]=='(') index->push(i);
            else if(s[i] == ')'){
                if(index->empty()) s[i]='*';
                else index->pop();
            }
        }
        
        string res = "";
        for(int i = s.length()-1 ; i>=0 ; i--){
            if(s[i]=='*') continue;
            else if(!index->empty() && i==index->top()){
                index->pop();
                continue;
            }
            else res=s[i]+res; // WHEN WORKING WITH STACK, NOTE THAT VALUES ARE TO BE PRINTED IN REVERSE DIRECTION
        }

        return res;
        
    }
};

// NON-STACK APPROACH
// Initialize a variable to keep track of the count of unmatched opening parentheses.
// Traverse the string character by character.
// When encountering an opening parenthesis '(', increment the count of unmatched opening parentheses.
// When encountering a closing parenthesis ')', if there are unmatched opening parentheses, decrement the count. Otherwise, mark the closing parenthesis for removal.
// After traversing the entire string, remove the marked parentheses.

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt = 0;
        for(int i = 0 ; i  < s.length() ; i++){
            if(s[i]=='(') cnt++;
            else if(s[i]==')'){
                if(cnt==0) s[i]='*';
                else cnt--;
            }
        }

        for(int i = s.length()-1 ; i >= 0 ; i--){
            if(cnt>0 && s[i]=='('){
                s[i]='*';
                cnt--;
            } 
        }


        string res = "";
        for(char c : s){
            if(c!='*') res+=c;
        }
        
        return res;
        
    }
};
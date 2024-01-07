/* Types of brackets taken into consideration
{,},(,),[,]*/

/* For a given a string expression containing only 
round brackets or parentheses, 
check if they are balanced or not. 
Brackets are said to be balanced if the bracket 
which opens last, closes first. */

#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string expression) 
{
    // Write your code here
    stack<char> s;
    for(char x : expression){
        if(x=='(' || x == '[' || x == '{') s.push(x);
        else if (x == ')') {
          if (s.empty() || s.top() != '(')
            return false;
          else
            s.pop();
        } else if (x == '}') {
          if (s.empty() || s.top() != '{') return false;
          else s.pop();
        }
        else if(x==']'){
            if(s.empty() ||s.top()!='[' ) return false;
            else s.pop();
        }
    }
    // returns true if stack is empty indicating balanced parenthesis
    return s.empty();
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}
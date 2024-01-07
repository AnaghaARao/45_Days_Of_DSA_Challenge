/*
Minimum bracket Reversal

For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. The expression will only contain curly brackets.
If the expression can't be balanced, return -1.
Example:
Expression: {{{{
If we reverse the second and the fourth opening brackets, the whole expression will get balanced. Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

Expression: {{{
In this example, even if we reverse the last opening bracket, we would be left with the first opening bracket and hence will not be able to make the expression balanced and the output will be -1.
Input Format :
The first and the only line of input contains a string expression, without any spaces in between.
Output Format :
The only line of output will print the number of reversals required to balance the whole expression. Prints -1, otherwise.
Note:
You don't have to print anything. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1sec
Sample Input 1:
{{{
Sample Output 1:
-1
Sample Input 2:
{{{{}}
Sample Output 2:
1
*/

/*
    idea:
    step-1: push if opening bracket
    step-2: pop for every closing bracket
    step-3: at the end of loop check the size of stack
    step-4: if size is even return size/2
    step-5: if size is odd return -1 
*/

#include<bits/stdc++.h>
using namespace std;

int countBracketReversals(string input) {
	// Write your code here
	// if number is odd then the brackets can never be balanced
	if(input.size()%2==1 || input.size()==0) return -1;

	// when the number of brackets are even

	stack<char> s;
    for (char x : input) {
        // if x == { then push onto the stack
        if(x=='{') s.push(x);
        // if x == } and top == { we pop from the stack
        else if (x == '}' && !s.empty() && s.top() == '{') s.pop();
        // if x == } and top != { we push x onto stack
        else s.push(x);		 
    }

    //the current stack structure would be like this: }}}...}{{{{...{
    
    // calculating the number of { brackets in the stack
    int lenOpen=0;
    while(!s.empty() && s.top()=='{'){
        s.pop();
        lenOpen++;
    }
    // m+n/2 == s.size() && m/2 == lenOpen
    // +1 is added for ceil function
    return (s.size() + 1)/2 + (lenOpen+1)/2;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}

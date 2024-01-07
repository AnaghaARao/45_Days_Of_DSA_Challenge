/*Check redundant brackets

For a given expression in the form of a string, find if there exist any redundant brackets or not. 
It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.
Example:
Expression: (a+b)+c
Since there are no needless brackets, hence, the output must be 'false'.

Expression: ((a+b))
The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.
Note:
You will not get a partial score for this problem. You will get marks only if all the test cases are passed.
Input Format :
The first and the only line of input contains a string expression, without any spaces in between.
Output Format :
The first and the only line of output will print either 'true' or 'false'(without the quotes) denoting whether the input expression contains redundant brackets or not.
Note:
You are not required to print the expected result. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1 second
Sample Input 1:
a+(b)+c 
Sample Output 1:
true
Explanation:
The expression can be reduced to a+b+c. Hence, the brackets are redundant.
Sample Input 2:
(a+b)
Sample Output 2:
false*/

//Note: true if redundant ; false if not redundant

/*HINT: 
    Redundant: ((a+b))  
    Not Redundant: (a+(b+c))

    how to check for redundant brackets?
    when there is no useful info between them 
    how to determine useful info?
    1. push everything other than a closing bracket into stack
    2. pop all chaacters and maintain cnt of otherthan (
    3. if cnt>1 then valid else invalid
    note: (c) is redundant
*/

#include<bits/stdc++.h>
using namespace std;

bool checkRedundantBrackets(string expression) {
	// Write your code here
    stack<char> s;
    for(char x : expression){
        if(x!=')') s.push(x);
        else{
            int cnt=0;
            while(s.top()!='('){
                s.pop();
                cnt++;
            }
            s.pop();
            if(cnt==0 || cnt==1) return false;
        }
    }
    return true;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}

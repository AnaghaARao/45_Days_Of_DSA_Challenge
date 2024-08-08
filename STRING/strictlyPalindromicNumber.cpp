// An integer n is strictly palindromic if, for every base b between 2 and n - 2 (inclusive), 
// the string representation of the integer n in base b is palindromic.
// Given an integer n, return true if n is strictly palindromic and false otherwise.
// A string is palindromic if it reads the same forward and backward.

// To find the value of number at base b:
// 1. divide num by b
// 2. store the remainder at string and keep appending it to the result
// 3. repeat the operations on the quotient of the division

// To convert int to string:
// syntax: string s = to_string(val);

// To reverse a string:
// syntax: reverse(s.begin(), s.end());

#include<bits/stdc++.h>
using namespace std;

bool NumberAtBase(int n, int b){
    string res = "";
    while(n!=0){
        int q = n%b;
        res.append(to_string(q));
        n/= b;
    }
    cout<<res<<endl;
    string rev = res;
    reverse(res.begin(), res.end());
    if(res == rev) return true;
    return false;
}
bool isStrictlyPalindromic(int n) {
    for(int i = 2 ; i <= n-2 ; i++){
        if(!NumberAtBase(n, i)) return false;
    }
    return true;
}
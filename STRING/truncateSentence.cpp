// A sentence is a list of words that are separated by a single space with no leading or trailing spaces. 
// Each of the words consists of only uppercase and lowercase English letters (no punctuation).
// For example, "Hello World", "HELLO", and "hello world hello world" are all sentences.
// You are given a sentence s​​​​​​ and an integer k​​​​​​. You want to truncate s​​​​​​ such that it contains only the first k​​​​​​ words. 
// Return s​​​​​​ after truncating it.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        int cnt = 0 ;
        string res = "";
        for(char c : s){
            if(c == ' ') cnt++;
            if(cnt==k) break;
            res += c;
        }
        return res;
    }
};

// BETTER SOLUTION:
string truncateSentence(string s, int k) {
    std::isstringstream iss(s);
    string word, truncated = "";

    for(int i = 0 ; i <= k ; i++){
        // read the next word
        iss >> word;

        truncated += word;

        if(i < k-1) truncated += " ";
    }

    return truncated;
}
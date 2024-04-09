/* Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
A string is represented by an array if the array elements concatenated in order forms the string. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "", s2 = "";
        for(string word : word1){
            s1 += word;
        }
        for(string word : word2){
            s2 += word;
        }

        return (s1==s2) ; 
    }
};
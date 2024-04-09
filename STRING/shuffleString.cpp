// You are given a string s and an integer array indices of the same length. 
// The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.
// Return the shuffled string.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = indices.size();
        char res[100];
        for(int i = 0 ; i < n ; i++){
            res[indices.at(i)] = s[i];
        }

        string result = "";
        for(int i = 0 ; i < n ; i++) result += res[i];
        return result;
    }
};
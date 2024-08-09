// You are given two strings s and t consisting of only lowercase English letters.
// Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.
// A subsequence is a string that can be derived from another string by deleting some or no characters without changing the 
// order of the remaining characters.

// Approach:
// 1. 2 pointer: 1 to each string
// 2. if character matches, increment the pointer
// 3. finally, at the end of the string, calculate number of indices left in string t
// 4. return this number

#include<bits/stdc++.h>
using namespace std;

int appendCharacters(string s, string t) {
    int i = 0 , j = 0;
    int t_cnt = t.length();
    while(s[i] != nullptr && t[j] != nullptr){
        if(s[i]!=t[j]) i++;
        else{
            i++;
            j++;
        }
    }
    return t_cnt - j; // dont do an additional subtraction of 1 cause the cnt for length and match cnt is starting from 0 itself
}
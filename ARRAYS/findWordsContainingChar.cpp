/* You are given a 0-indexed array of strings words and a character x.

Return an array of indices representing the words that contain the character x.

Note that the returned array may be in any order. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // METHOD-1
    // bool hasChar(string word, char x){
    //     // if(word.begin() == x || word.end() == x) return true;
    //     for (auto c : word){
    //         if(c == x) return true;
    //     }
    //     return false;
    // }
    // vector<int> findWordsContaining(vector<string>& words, char x) {
    //     vector<int> result;
    //     for(int i = 0 ; i < words.size() ; i++){
    //         if(hasChar(words[i], x)) result.push_back(i);
    //     }
    //     return result;
    // }

    vector<int> findWordsContaining(vector<string>& words, char x){
        int n = words.size();
        vector<int> res;
        for(int i = 0 ; i < n ; i++){
            if(words[i].find(x) != -1) res.push_back(i);
        }
        return res;
    }

};
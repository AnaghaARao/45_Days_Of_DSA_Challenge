/* A sentence is a list of words that are separated by a single space with no leading or trailing spaces.
You are given an array of strings sentences, where each sentences[i] represents a single sentence.
Return the maximum number of words that appear in a single sentence.

  */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxx = 0;
        for(auto s : sentences){
            int cnt = 0;
            for(int i = 0 ; i < s.length() ; i++){
                if(s[i]==' ' || s[i]=='\n') cnt++;
            }
            maxx = max(maxx,cnt);
        }
        return max;
    }
};
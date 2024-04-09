/* You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item. 
You are also given a rule represented by two strings, ruleKey and ruleValue.

The ith item is said to match the rule if one of the following is true:

ruleKey == "type" and ruleValue == typei.
ruleKey == "color" and ruleValue == colori.
ruleKey == "name" and ruleValue == namei.
Return the number of items that match the given rule. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int cnt = 0;
        int index;
        // determining index [ie, type/color/name] to be matched
        if(ruleKey == "type") index = 0;
        else if(ruleKey == "color") index = 1;
        else index = 2;

        // iterate to find the count
        for(vector<string> i : items){
            if(i[index]==ruleValue) cnt++;
        }
        
        return cnt;
    }
};
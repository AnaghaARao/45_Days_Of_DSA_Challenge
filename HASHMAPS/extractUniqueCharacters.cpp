// Problem statement
// Given a string S, you need to remove all the duplicates. 
// That means, the output string should contain each character only once. 
// The respective order of characters should remain same, as in the input string.

#include<bits/stdc++.h>
using namespace std;

string uniqueChar(string str) {
    unordered_map<int, bool> map;
    string res = "";
    for(char c: str){
        if(map.count(c)>0){
            continue;
        }else{
            res+=c;
            map[c] = true;
        }
    }
    return res;
}
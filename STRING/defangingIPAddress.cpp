/* Given a valid (IPv4) IP address, return a defanged version of that IP address.
A defanged IP address replaces every period "." with "[.]" */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for(char c : address){
            if(c=='.') res += "[.]";
            else res += c;
        }
        return res;
    }
};
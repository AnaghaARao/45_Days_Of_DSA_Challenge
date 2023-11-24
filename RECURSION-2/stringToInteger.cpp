#include<bits/stdc++.h>
using namespace std;

int stringToNumber(char a[]){
    string s = a;
    // base case:
    if(s.size()==0) return 0;

    // induction step and recursive call::
    return (s[0]-'0')*pow(10,s.size()-1)+stringToNumber(a+1);
}
/*
    Remove Duplicates Recursively
    Given a string S, remove consecutive duplicates from it recursively.
*/

#include<bits/stdc++.h>
using namespace std;

void removeConsecutiveDuplicates(char *s) {
	
    // base case:
    if(s[0] == '\0') return;

    // induction step and recursive calls
    if(s[0]!=s[1]) removeConsecutiveDuplicates(s+1);
    else{
        int i=1;
        for(; s[i]!='\0';i++){
            s[i-1] = s[i];
        }
        s[i-1] = s[i];
        removeConsecutiveDuplicates(s);
    }
}
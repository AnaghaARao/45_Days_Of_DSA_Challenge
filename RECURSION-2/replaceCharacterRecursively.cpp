/*
    Replace Character Recursively

    Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
    Do this recursively.
*/

#include<bits/stdc++.h>
using namespace std;

void replaceCharacter(char s[], char c1, char c2) {
    // base case:
    if(s[0]=='\0') return;

    // induction step and recursive call
    if(s[0]==c1) s[0] = c2;
    replaceCharacter(s+1,c1,c2);
}

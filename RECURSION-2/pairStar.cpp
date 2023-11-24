#include<bits/stdc++.h>
using namespace std;

void pairStar(char a[]){
    string s = a;
    // base case:
    if(s.size()==0) return;
    // induction step:
    if(a[0]==a[1]){
        string temp = s.substr(1);
        a[1]='*';
        int i;
        for(i = 0 ; i < temp.size();i++){
            a[2+i] = temp[i];
        }
        a[2+i]='\0'; // VERY IMPORTANT STEP
        pairStar(a+2);
    }
    else pairStar(a+1);
    
}
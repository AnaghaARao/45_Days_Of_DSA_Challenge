#include<bits/stdc++.h>
using namespace std;

void removeX(char a[]){
    // base case
    if(a[0]=='\0') return;
    // induction step and recursive call:
    if(a[0]!='x') removeX(a+1);
    else{
        int i=1;
        for(i = 1 ; a[i]!='\0';i++) a[i-1]=a[i];
        a[i-1]='\0'; // VERY IMPORTANT step to get the right ans!!!
        removeX(a);
    }
}
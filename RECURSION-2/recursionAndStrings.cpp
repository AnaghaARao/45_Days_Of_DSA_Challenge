#include<bits/stdc++.h>
using namespace std;

void removeX(char s[]){
    // base case
    if(s[0] == '\0') return;

    if(s[0]!='x') removeX(s+1);
    else{
        int i = 1 ;
        for(; s[i] != '\0' ; i++){
            s[i-1] = s[i];
        }
        s[i-1] = s[i];
        removeX(s);
    }
}

int length(char arr[]){
    // base case:
    if(arr[0]=='\0') return 0;

    //induction step and recursion call
    // recursive call to the array starting from the next character
    int smallAns = length(arr+1);
    return 1 + smallAns;
}

int main(){
    char str[100];
    cin>>str;

    int l = length(str);
    cout<<l<<endl;

    removeX(str);
    cout << str << endl;
    l = length(str) ;
    cout<<l<<endl;
}

/*
    1. Finding length of a string
    2. Removing all occurences of a character
    => case 1: s[0]!=x call for the array from next position
    => case 2: s[0]==x move each letter backwards to remove the x 
*/
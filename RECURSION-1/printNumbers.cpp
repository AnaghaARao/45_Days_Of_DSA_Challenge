/*
    Problem Statement:
    Print Numbers:
    Given the number 'n', write a code to print numbers from 1 to n 
    in increasing order recursively.
*/

#include<bits/stdc++.h>
using namespace std;

void print(int n){
    //write your code here
    // base case
    if(n<1) return;
    // recursive call
    print(n-1);
    // induction step
    cout<<n<<" ";
}

int main(){
    int n;
    cin >> n;
  
    print(n);
}
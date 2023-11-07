#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    // base case:
    if(n==0) return 1;
    int smallOutput = factorial(n-1);
    int output = n * smallOutput;
    return output;
}
int main(){
    cout<<factorial(4)<<endl;
}

/*
    RECURSION IS BASED ON PMI
    PMI = PRINCIPLE OF MATHEMATICAL INDUCTION
    It is used to prove functions
    eg: F(n) is true for all n
    STEPS:
    1. Prove F(0) or F(1) is true => Base Case
    2. Induction Hypothesis: Assume F(k) is true
    3. Induction step: Using step-2 prove that F(k+1) is true
    Finally only 2 steps to be taken case of: step - 1 & 3
*/
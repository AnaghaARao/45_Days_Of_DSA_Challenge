#include<bits/stdc++.h>
using namespace std;

void helper(int input[], int currIndex, int size, int x, int output[], int &k){
    if(currIndex==size) return;
    if(input[currIndex]==x){
        output[k]=currIndex;
        k++;
    }
    helper(input, currIndex+1, size,x,output,k);
}

int allIndexes(int input[], int size, int x, int output[]) {
    int k = 0;
    helper(input,0,size,x,output,k);
    return k;
}
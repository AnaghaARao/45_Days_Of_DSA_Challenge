/* Problem: to find the first index of an element in an array*/

#include<bits/stdc++.h>
using namespace std;

int firstIndex(int a[] , int size , int x){
    // base case:
    if(size==0) return -1;
    
    // induction step:
    if(a[0]==x) return 0;

    // induction hypothesis or recursive call:
    int smallAns = firstIndex(a+1,size-1,x);
    if(smallAns == -1) return smallAns;
    /*
        If the smaller array doesn't find the element and 
        the current 0th index also doesnt have the array 
        then that means the element is not present => hence we return 0
    */
    else return smallAns+1;
    /* 
        The element is present at the 0th index of the smaller index, 
        to print its actual index we add 1 at each iteration
    */
}
int main(){
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i = 0 ; i < n ; i++) cin>>a[i];
    int x;
    cin>>x;
    cout<<firstIndex(a,n,x);
    return 0;
}
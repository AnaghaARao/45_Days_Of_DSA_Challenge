#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int a[] , int size){
    // base case:
    if(size==0 || size==1) return true;
    // induction hypothesis and induction step
    if(a[0]!=a[size-1]) return false;
    bool smallAns = isPalindrome(a+1, size-2);
    // size-2 cause we remove 1 from each end
    return smallAns;
}

int main(){
    int a[] = {1,2,3,4,3,2,1};
    int b[] = {1,2,3,4,4,3,2,1};
    int c[] = {1,2,3,4};
    cout<<isPalindrome(a,7)<<endl;
    cout<<isPalindrome(b,8)<<endl;
    cout<<isPalindrome(c,7)<<endl;
}

/*
    Palindrome is a string or a number which is the same when read in reverse.
    In case the array is even in size then size becomes 0 at base case
    In case the array is odd in size then size beomes 1 at base case
*/
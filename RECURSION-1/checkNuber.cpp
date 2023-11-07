/*
    Check Number:
    Given an array of length N and an integer x, 
    you need to find if x is present in the array or not. 
    Return true or false.
    Do this recursively.
*/


#include<bits/stdc++.h>
using namespace std;

bool checkNumber(int arr[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */

    /* APPROACH 1
    //base case:
    if(size==0) return false;
    // induction step
    if(arr[0]==x) return true;
    // recursive call
    checkNumber(arr+1,size-1,x);*/

    // base case
    if(size==0) return false;
    // induction step
    if(arr[0]==x) return true;
    // recursive call
    bool smallerAns = checkNumber(arr+1,size-1,x);
    return smallerAns;



}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    if(checkNumber(input, n, x)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
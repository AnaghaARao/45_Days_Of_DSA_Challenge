#include<bits/stdc++.h>
using namespace std;

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int a,n;
    int ans=0;
    cin>>n;
    for(int i = 0 ; i < n ; i++) {
        cin>>a;
        ans = ans ^ a;
    }
    cout<<"unique element is "<< ans <<endl;

}

/*
    approach-1:
    consider array of size 2n+1
    1. sort the array
    2. check for n valid pairs
    3. every ith pair's indices are 2*i,2*i+1
    4. if a particular pair is invalid then:
    => then the 1st element of the pair is unique
    => flag is set to true
    5. if all pairs are valid then flag remains false 
        and last element is the unique element

    approach-2:
    consider array of size 2n+1
    1. take xor of all the elements
    => then xor of 2 same values = 0 
    => only the unique element will remain as the answer

*/
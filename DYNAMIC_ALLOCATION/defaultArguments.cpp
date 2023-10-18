#include<bits/stdc++.h>
using namespace std;

int sum(int a[] , int size , int si = 0) // makes the last argument optional
{
    int ans = 0;
    for(int i = si ; i < size ; i++){
        ans += a[i];
    }
    return ans;
}

int sum2(int a , int b = 0 , int c = 0 , int d = 0)
{
    //this function can take 1/ 2 / 3/ 4 args = 4 diff functions
    return a+b+c+d;
}

int main(){
    int a[20];
    cout << sum(a , 20) << endl; // ERROR: 3 arguments needed-int sum(int a[] , int size , int si)
}

// note: default arguments shd be placed at the right-most position
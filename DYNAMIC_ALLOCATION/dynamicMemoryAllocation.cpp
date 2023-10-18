#include<bits/stdc++.h>
using namespace std;

int main(){
    int* p = new int;
    *p = 10;
    cout << *p << endl;

    int n;
    cin>>n;
    int* arr = new int[n];
    arr[2] = 10; //same as *(arr+2) = 10
    int max = INT_MIN;
    for(int i = 0 ; i < n ; i++ ){
        cin>>arr[i];
        if(max < arr[i]) max = arr[i];
    }

    cout<< max << endl;

    // DE-ALLOCATIONS:
    // single element
    delete p;
    // array de-allocation
    delete []arr;
}
/*
    the following is not allowed:
    int n;
    cin>>n;
    int arr[n];
    WHY?
    there are 2 types of memory: stack and heap
    stack is utilized when memory is allocated at compile-time
    stack memory is small 
    In the above case it makes an array of random size at compile time and this cant be changed
    this is known as static memory allocation
    here the memory is functional only within its scope
    heap is a larger memory
    we can utilize at times where size is unknow
    this is known as dynamic memory allocation - using new keyword
    new datatypeName returns the address of the memory location
    here the variables dont have a scope...they shd be de-allocated manually by the programmer
    de-allocation can be done using delete keyword
*/
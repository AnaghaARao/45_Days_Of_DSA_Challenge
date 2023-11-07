#include<bits/stdc++.h>
using namespace std;

bool isSorted2(int a[], int size){
    // base case
    if(size == 1 || size == 0) return true;

    bool isSmallerOutput = isSorted2(a+1,size-1);
    if(!isSmallerOutput) return false;
    if(a[0]>a[1]) return false;
    else return true;
}

bool isSorted(int a[] , int size){
    // base case
    if(size == 1 || size == 0) return true;

    if(a[0]>a[1]){
        return false;
    }

    // recursive call
    bool isSmallerSorted = isSorted(a+1,size-1);
    // induction step
    return isSmallerSorted;
    /* 
        Explaination of return statement:
        if(isSmallerSorted){
            return true;
        }
        else{
            return false;
        }
    */
    
}

int main(){
    int arr[] = {3,56,0234,823,123};
    if(isSorted(arr,5)){
        cout<<"Sorted";
    }
    else cout<<"UnSorted";
}

/*
    We are recursively checking if an array is sorted or not
    Base case: if number of elements are 0 or 1 => sorted
    We check if the first 2 elements are sorted or not
    For elements from index 1 to n-1 would be dealt with recursively.
*/
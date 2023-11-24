#include<bits/stdc++.h>
using namespace std;

int helperBinarySearch(int a[] , int l , int r , int x){

    // base case:
    if(l>r) return -1;

    int mid = (l+r)/2;
    int smallAns;

    // induction step and recursive call
    if(a[mid]==x) smallAns = mid;
    else if(a[mid]>x) smallAns = helperBinarySearch(a,l,mid-1,x);
    else smallAns = helperBinarySearch(a,mid+1,r,x);
    return smallAns;
}

int binarySearch(int input[], int size, int element) {
    // Write your code here
    return helperBinarySearch(input , 0 , size-1 , element);
}

/*
    Binary Search is an algorithm used to search for a particular element in an array.
    However, a primary condition for this is the data shd be sorted
    Therefore this algorithm is used when searching is done on the same dataset =>
    in such a situation we sort the data once and search multiple times
    This algo follows DIVIDE AND CONQUER Concept
*/
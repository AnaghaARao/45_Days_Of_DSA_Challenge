#include<bits/stdc++.h>
using namespace std;

void merge(int *a , int left , int mid, int right){
    int i = left , j = mid+1 , k = 0;
    int *b = new int[right-left+1];
    while(i < mid && j < right){
        if(a[i]<a[j]){
            b[k++] = a[i++];
        }
        else{
            b[k++] = a[j++];
        }
    }

    while(i!=mid){
        b[k++] = a[i++];
    }
    while(j!=right){
        b[k++] = a[j++];
    }

    a = b;
}

void mergeSort(int a[] , int left, int right){
    // base case:
    if(left >= right) return;
    int mid = (left+right)/2;
    mergeSort(a, left,mid);
    mergeSort(a,mid+1,right);
    merge(a,left,mid,right);
}


/*
    Merge sort is a recursion based sorting algorithm that is extremely fast.
    base case: if size = 0 or 1 => array is already sorted
*/
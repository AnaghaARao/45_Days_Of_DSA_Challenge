// Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
// Note: Space complexity should be O(1).

#include<bits/stdc++.h>
using namespace std;

void createHeap(int &arr[], int n){
    for(int j = 1 ; j < n ; j++){
        int childIndex = j;
        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;
            if(arr[childIndex] < arr[parentIndex]){
                int temp = arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
            }
            childIndex = parentIndex;
        }
    }   
}

void removeMin(int &arr[], int n){
    swap(arr[0], arr[n-1]);
    int parentIndex = 0;
    int leftIndex = parentIndex*2+1;
    int rightIndex = parentIndex*2+2;
    
    while(leftIndex < n-1){
        
        int index = n;
        if(arr[parentIndex]>arr[leftIndex]){
            index = leftIndex;
        }
        if(rightIndex < n-1 && arr[rightIndex] < arr[index]){
            index = rightIndex;
        }

        if(index == parentIndex) break;

        swap(arr[parentIndex], arr[index]);

        parentIndex = index;
        leftIndex = parentIndex*2+1;
        rightIndex = parentIndex*2+2;
    }
}

void heapSort(int arr[], int n) {
    // Write your code
    createHeap(arr,n);
    for(int i = n ; i > 0 ; i--) removeMin(arr, i);
}
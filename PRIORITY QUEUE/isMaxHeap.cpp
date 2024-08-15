// Problem Statement:
// Given an array of integers, check whether it represents max-heap or not. 
// Return true if the given array represents max-heap, else return false.

bool isMaxHeap(int arr[], int n) {
    // Write your code here
    int i = 0 ;
    while(i<n){
        if((i*2+1 < n && arr[i] < arr[i*2+1]) || (i*2+2 < n && arr[i]<arr[i*2+2])) return false;
        i++;
    }
    return true;
}
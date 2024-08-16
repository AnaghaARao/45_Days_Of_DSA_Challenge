// Problem statement
// Given an array 'arr' of random integers and an integer 'k', return the kth largest element in the array.
// Note: Try to do this in O(n*log k) time.

#include<bits/stdc++.h>
using namespace std;

int kthLargest(vector<int>&arr, int k) {
    // Write your code here
    priority_queue<int, vector<int>,greater<int>> pq;
    for(int i = 0 ; i < k ; i++) pq.push(arr[i]);
    for(int i = k ; i < arr.size() ; i++){
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    // THE TOP OF THE PRIORITY QUEUE IS THE Kth LARGEST ELEMENT
    return pq.top();
}
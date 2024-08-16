// Problem Statement:
// You are given with an integer k and an array of integers that contain numbers in random order. 
// Write a program to find k smallest numbers from given array. 
// You need to save them in an array and return it.

// Time complexity should be O(n * logk) and space complexity should not be more than O(k).
// Note: Order of elements in the output is not important.

#include<bits/stdc++.h>
using namespace std;

vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    priority_queue<int> pq;
    for(int i = 0 ; i < k ; i++) pq.push(arr[i]);

    for(int i = k ; i < n ; i++){
        if(pq.top() > arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    vector<int> res;
    for(int i = 0 ; i < k ; i++) {
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}
// Problem statement
// You are given with an integer k and an array of integers that contain numbers in random order. 
// Write a program to find k largest numbers from given array. 
// You need to save them in an array and return it.

// Time complexity should be O(nlogk) and space complexity should be not more than O(k).
// Order of elements in the output is not important.

#include<bits/stdc++.h>
using namespace std;

vector<int> kLargest(int input[], int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0 ; i < k ; i++) pq.push(input[i]);
    for(int i = k ; i < n ; i++){
        if(input[i]>pq.top()){
            pq.pop();
            pq.push(input[i]);
        }
    }
    vector<int> res;
    while(!pq.empty()){
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}
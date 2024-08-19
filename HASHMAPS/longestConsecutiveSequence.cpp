// Problem statement
// You are given an array of unique integers that contain numbers in random order. 
// You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
// You need to return the output array which contains starting and ending element. 
// If the length of the longest possible sequence is one, then the output array must contain only single element.

// Note:
// 1. Best solution takes O(n) time.
// 2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.

#include<bits/stdc++.h>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    unordered_map<int, int> map;
    for(int i = 0 ; i < n ; i++){
        map[arr[i]] = arr[i]+1; // store key, consecutive value =>(key, key+1)
    }

    int maxL = INT_MIN; // to track the final results 
    vector<int> v;

    // iterate from last to first element to ensure that the resultant vector 
    // has consecutive nums starting from first appearing number
    for(int i = n-1 ; i >= 0 ; i--){
        int cnt = 0;
        if(map.count(arr[i])>0) { // check if key is present
            cnt++;
            int key = map[arr[i]]; // the next consecutive value -> key
            int prev; // to track the prev key
            while(map.count(key)>0){
                cnt++;
                prev = key; //update prev
                key = map[key]; // update key
            }
            maxL = max(maxL, cnt); // update maxL
            if (maxL == cnt) { // if maxL changed, change the resultant vector
                v.clear();
                v.push_back(arr[i]);
                v.push_back(prev);
            }
        }
    }
    return v;
}
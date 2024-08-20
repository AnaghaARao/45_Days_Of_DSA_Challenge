// Problem statement
// Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.

#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    unordered_map<int,int> map; // to store sum corresponding to each index
    int sum = 0;
    int maxLen = 0;

    for(int i = 0 ; i < n ; i++){
        sum += arr[i];
        // options:
        // 1. sum = 0
        if(sum == 0){ // indicates that current subarray sums to zero
            maxLen = i+1; // may or may not be the max length
        }
        // 2. sum is repeated -> indicates that the sum of a subarray is zero
        if(map.count(sum)>0){
            maxLen = max(maxLen, i-map[sum]);
        }// 3. new value of sum
        else{
            map[sum] = i;
        }
    }
    return maxLen; // return the result
}
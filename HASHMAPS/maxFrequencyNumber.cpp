// Problem statement
// You are given an array of integers that contain numbers in random order. 
// Write a program to find and return the number which occurs the maximum times in the given input.
// If two or more elements are having the maximum frequency, return the element which occurs in the array first.

#include<bits/stdc++.h>
using namespace std;

int highestFrequency(int arr[], int n) {
   unordered_map<int, int> nums;
    int maxF = INT_MIN, num = -1;
    for(int i = 0 ; i < n ; i++) {
        if(nums.count(arr[i]) > 0){
            // if key already exists then increment the value/ frequency
            nums.at(arr[i]) += 1;
        }else{
            // else create a new key using [] method
            nums[arr[i]] = 1;
        }
    }
    for(int i = n-1 ; i >= 0 ; i--){ 
        // loop from n-1 to 0 => to ensure that the largest frequency first occuring value is stored/returned
        maxF = max(maxF,nums.at(arr[i]));
        num = (maxF == nums.at(arr[i]) ? arr[i] : num);
    }
    return num;
}
// You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:
// Every element less than pivot appears before every element greater than pivot.
// Every element equal to pivot appears in between the elements less than and greater than pivot.
// The relative order of the elements less than pivot and the elements greater than pivot is maintained.
// More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. 
// For elements less than pivot, if i < j and nums[i] < pivot and nums[j] < pivot, then pi < pj. 
// Similarly for elements greater than pivot, if i < j and nums[i] > pivot and nums[j] > pivot, then pi < pj.
// Return nums after the rearrangement.

#include<bits/stdc++.h>
using namespace std;

vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> less, more;
    for(int ele : nums){
        if(ele < pivot) less.push_back(ele);
        else if(ele > pivot) more.push_back(ele); // important to give the condition and not just "else"
    }
    int cnt = nums.size()-less.size()-more.size();
    for(int i = 0 ; i < cnt ; i++) less.push_back(pivot);

    less.insert(less.end(), more.begin(), more.end());
    return less;
}
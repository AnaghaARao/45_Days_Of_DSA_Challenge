// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
// You should return the array of nums such that the the array follows the given conditions:
// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    // vector<int> positive, negative, res;
    // for(int ele : nums){
    //     if(ele > 0) positive.push_back(ele);
    //     else negative.push_back(ele);
    // }
    // int n = nums.size();
    // for(int i = 0 ; i < n/2 ; i++){
    //     res.push_back(positive[i]);
    //     res.push_back(negative[i]);
    // }
    // return res;

    
    int n = nums.size();
    vector<int> res(n);
    int  i = 0, j = 1;
    for(int ele : nums){
        if(ele > 0){
            res[i] = ele;
            i+=2;
        }else{
            res[j] = ele;
            j+=2;
        }
    }
    return res;
}
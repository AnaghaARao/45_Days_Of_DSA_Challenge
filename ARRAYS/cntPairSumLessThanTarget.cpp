/* Given a 0-indexed integer array nums of length n and an integer target, return the number of pairs (i, j) where 0 <= i < j < n and nums[i] + nums[j] < target. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size() , cnt = 0;
        sort(nums.begin(), nums.end());

        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                if(nums[i] + nums[j] >= target) break;
                cnt++;
            }
        }
        return cnt;
    }
};
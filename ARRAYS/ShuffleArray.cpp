/* Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn]. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;
        // METHOD - 1
        // int x = 0 , y = n;
        // for(int i = 0 ; i < n ; i++){
        //     result.push_back(nums[x++]);
        //     result.push_back(nums[y++]);
        // }
        // return result;

        for(int i = 0 ; i < n ; i++){
            result.push_back(nums[i]);
            result.push_back(nums[i+n]);
        }
        return result;
    }
};
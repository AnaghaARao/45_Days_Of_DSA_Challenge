/* Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // slow and fast pointer technique;
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];

            if(slow==fast) break;
        }while(slow != fast);

        int slow2 = nums[0];

        while(slow != slow2){
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        
        return slow;
    }
};
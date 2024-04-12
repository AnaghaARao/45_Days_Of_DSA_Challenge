/*  */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0 , right = height.size()-1; // 2 pointer method initialization
        // max height encountered on both sides:
        int leftMax = 0 , rightMax = 0; // value intially set to zero due to non -ve int in height vector
        int waterTrapped = 0; // initial condition

        while(left<=right){
            if(height[left] < height[right]){
                if(height[left]>leftMax) leftMax = height[left];
                else waterTrapped += leftMax-height[left];
                left++;
            }
            else{
                if(height[right] > rightMax) rightMax = height[right];
                else waterTrapped += rightMax-height[right];
                right--;
            }
        }

        return waterTrapped;

    }
};
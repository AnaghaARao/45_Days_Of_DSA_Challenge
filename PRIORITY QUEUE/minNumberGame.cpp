// Problem Statement:
// You are given a 0-indexed integer array nums of even length and there is also an empty array arr.
// Alice and Bob decided to play a game where in every round Alice and Bob will do one move. 
// The rules of the game are as follows:

// Every round, first Alice will remove the minimum element from nums, and then Bob does the same.
// Now, first Bob will append the removed element in the array arr, and then Alice does the same.
// The game continues until nums becomes empty.
// Return the resulting array arr.

class Solution {
public:
//     void down_heapify(vector<int>& nums){
//         int parentIndex = 0;
//         int leftIndex = parentIndex*2+1;
//         int rightIndex = parentIndex*2+2;

//         while(leftIndex < nums.size()){
//             int index = parentIndex;
//             if(nums[leftIndex] < nums[index]) index = leftIndex;

//             if(rightIndex < nums.size() && nums[index] > nums[rightIndex]) index = rightIndex;

//             if(parentIndex == index) break;

//             swap(nums[parentIndex], nums[index]);
//             parentIndex = index;
//             leftIndex = parentIndex*2+1;
//             rightIndex = parentIndex*2+2;
//         }
//         // return res;
//     }

//     void createHeap(vector<int>& nums){
//         for(int i = 1 ; i < nums.size() ; i++){
//             int childIndex = i;
//             while(i>0){
//                 int parentIndex = (childIndex-1)/2;
//                 if(nums[parentIndex]>nums[childIndex]){
//                     swap(nums[parentIndex],nums[childIndex]);
//                 }
//                 childIndex = parentIndex;
//             }
//         }
//     }
//     int removeMin(vector<int>& nums){
//         int res = nums.at(nums.size()-1);
//         swap(nums[0], nums[nums.size()-1]);
//         nums.pop_back();
//         down_heapify(nums);
//         return res;
//     }

    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size() ; i+=2){
            swap(nums.at(i), nums.at(i+1));
        }
        return nums;
        // createHeap(nums);
        // vector<int> res(nums.size());
        // for(int i = 0 ; i < nums.size()/2 ; i++){
        //     int alice = removeMin(nums);
        //     int bob = removeMin(nums);
        //     res.push_back(bob);
        //     res.push_back(alice);
        // }
        // return res;
    }
};
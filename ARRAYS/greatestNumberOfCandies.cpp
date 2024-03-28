/* There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int n = candies.size();
        int maxOrg = 0;
        // to find greatest num of candies a child has
        for(int i = 0 ; i < n ; i++){
            maxOrg = max(maxOrg, candies[i]);
        }

        for(int i = 0 ; i < n ; i++){
            if(candies[i]+extraCandies >= maxOrg) res.push_back(true);
            else res.push_back(false);
        }

        return res;
    }
};
/* You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        int m = accounts[1].size();
        int sum = 0, max = accounts[0][0];
        for(int i = 0 ; i < n ; i++){
          for(int j = 0 ; j < m ; j++){
            sum+=accounts[i][j];
          } 
          if(s>max) max = s;
          s=0;
        }
        return max;
    }
};
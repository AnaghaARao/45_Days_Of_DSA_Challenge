/* Given a rows x cols binary matrix filled with 0's and 1's, 
find the largest rectangle containing only 1's and return its area. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> heights(matrix.size(),0);
        int maxArea = 0;

        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix.size() ; j++){
                if(matrix[i][j]=='1') heights[j]++;
                else heights[j]=0;
            }
            int area = 0;
            for(int k = 0 ; k < matrix.size() ; k++){
                if(heights[k]!=0) area+=heights[k];
                else {
                    maxArea = max(maxArea,area);
                    area = 0;
                }
            }
        }

        return maxArea;
    }
};
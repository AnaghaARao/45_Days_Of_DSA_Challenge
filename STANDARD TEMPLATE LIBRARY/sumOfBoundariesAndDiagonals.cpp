/*
    PROBLEM STATEMENT:
    Total Sum on the Boundaries and Diagonals
    For a given two-dimensional square matrix of size (N x N). Find the total sum of elements on both the diagonals and at all the four boundaries.
*/

#include<bits/stdc++.h>
using namespace std;

int totalSum(vector<vector<int>> input, int n){
    int cnt=0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i==0 || j==0) cnt+=input[i][j];
            if(i==j) cnt+=input[i][j];
            if(j==n-i-1) cnt+=input[i][j];
        }
    }
    return cnt;
}
// You are given an m x n binary matrix grid.
// A row or column is considered palindromic if its values read the same forward and backward.
// You can flip any number of cells in grid from 0 to 1, or from 1 to 0.
// Return the minimum number of cells that need to be flipped to make either all rows palindromic or all columns palindromic.

#include<bits/stdc++.h>
using namespace std;

// int isPalindrome(string s){
//     int cnt = 0 ,  n = s.length();
//     for(int i = 0 ; i < n/2 ; i++){
//         if(s[i] != s[n-i-1]) cnt++;
//     }
//     return cnt;
// }

// BETTER APPROACH
int minFlips(vector<vector<int>>& grid) {

    int row = grid.size();
    int col = grid[0].size();
    int row_cnt = 0 , col_cnt  = 0;

    for(int i = 0 ; i <  row ; i++){
        for(int j = 0 ; j < col ; j++){
            if(grid[i][j] != grid[row-i-1][j]) col_cnt++;
            if(grid[i][j] != grid[i][col-j-1]) row_cnt++;
        }
    }

    return min(row_cnt/2, col_cnt/2); // divide by 2 cause the cnt is doubled
    // cnt is doubled cause we do n*m traversal and account each flip twice

    // int row = grid.size();
    // int col = grid[0].size();
    // vector<string> row_value(row);
    // vector<string> col_value(col);

    // for(int i = 0 ; i < row ; i++){
    //     row_value[i] = "";
    //     for(int j = 0 ; j <  col ; j++){
    //         col_value[j].append(to_string(grid[i][j]));
    //         row_value[i].append(to_string(grid[i][j]));
    //     }
    // }

    // int row_cnt = 0, col_cnt = 0;
    // for(int i = 0 ; i < row ; i++){
    //     row_cnt += isPalindrome(row_value[i]);
    // }
    // for(int i = 0 ; i < col ; i++){
    //     col_cnt += isPalindrome(col_value[i]);
    // }

    // return min(row_cnt, col_cnt);

}
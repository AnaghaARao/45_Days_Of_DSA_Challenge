// You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. 
// Each list of intervals is pairwise disjoint and in sorted order.
// Return the intersection of these two interval lists.
// A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.
// The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. 
// For example, the intersection of [1, 3] and [2, 4] is [2, 3].


// Approach:
// 1. use 2 pointer each pointing to 2 vector lists
// 2. if there exists an intersection between the 2 pointers then append the intersection into the resultant vector
// 3. if no intersection exists then increment both the pointers

// How to find if intersection exists?
// find max of start elements between the 2 list pointers
// and find min of end elements 
// if start <= end then push into resultant list
// check conditions for incrementing i and j (pointers)

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

    vector<vector<int>> res;

    int i = 0, j = 0;

    while(i < firstList.size() && j < secondList.size()){
        int start = max(firstList[i][0], secondList[j][0]);
        int end = min(firstList[i][1], secondList[j][1]);

        if(start<=end){
            res.push_back({start, end});
        }
        
        if(firstList[i][1] < secondList[j][1]) i++;
        else j++;
    }

    return res;




    // int n = firstList.size();
    // int m = secondList.size();
    // vector<vector<int>> res;

    // int i = 0 , j = 0;

    // while(i<n && j<m){
    //     int a = firstList[i][0], b = firstList[i][1] ;
    //     int x = secondList[j][0], y = secondList[j][1];
    //     if(b<x){
    //         i++;
    //     } else if(y<a){
    //         j++;
    //     }
    //     else{ 
    //         if(a<=x<=b<=y){
    //             vector<int> temp;
    //             temp.push_back(x);
    //             temp.push_back(b);
    //             res.push_back(temp);
    //             i++;
    //         }else if(x<=a<=y<=b){
    //             vector<int> temp;
    //             temp.push_back(a);
    //             temp.push_back(y);
    //             res.push_back(temp);
    //             j++;
    //         }
    //     }
    // }
    // return res;
}

        
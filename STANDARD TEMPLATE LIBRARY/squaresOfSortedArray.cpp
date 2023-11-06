/*
    PROBLEM STATEMENT:
    Squares of a Sorted Array
    You are given an array/list ‘ARR’ of ‘N’ integers. You have to generate an array/list containing squares of each number in ‘ARR’, sorted in increasing order.
*/

#include <bits/stdc++.h> 
using namespace std;

vector < int > sqsorted(vector < int > & arr) {
    // Write your code here.
    vector<int> square;
    for(auto item : arr){
        square.push_back(item*item);
    }
    sort(square.begin(),square.end());
    return square;
}
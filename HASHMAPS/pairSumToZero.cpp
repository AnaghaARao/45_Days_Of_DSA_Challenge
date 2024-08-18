// Problem statement
// Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.

// Note:
// Array A can contain duplicate elements as well.

#include<bits/stdc++.h>
using namespace std;

int pairSum(int *arr, int n) {
	unordered_map<int, int> map;
    int cnt = 0; // to keep a track of pairs
    for(int i = 0 ; i < n ; i++){ // to iterate through all the elements of the array
        int key = arr[i], neg = -arr[i];
        if(map.count(neg)>0) cnt += map.at(neg); // update count, if counter-part of the pair exists
        map[key]+=1; // insert/ update frquency of current element
    }
}
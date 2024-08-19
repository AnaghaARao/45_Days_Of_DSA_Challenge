// Problem statement
// You are given with an array of integers and an integer K. 
// You have to find and print the count of all such pairs which have difference K.

// Note: Take absolute difference between the elements of the array.

#include<bits/stdc++.h>
using namespace std;

int getPairsWithDifferenceK(int *arr, int n, int k) {
    unordered_map<int, int> map;
    int cnt = 0;

    for(int i = 0 ; i < n ; i++){
        int k1 = arr[i]+k; // possible pair for arr[i]
        int k2 = arr[i]-k; // possible pair for arr[i]

        if(map.count(k1)){ // check if present
            cnt += map[k1]; // then update cnt
        }
        if(k1 != k2 && map.count(k2)){ // ensure possible pairs arent same to prevent double counting
            cnt += map[k2]; // update cnt on condition matching
        }

        map[arr[i]]+=1; // include the element in the map and update its frequency
    }
    return cnt;
}
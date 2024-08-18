// Problem statement
// You have been given two integer arrays/lists (ARR1 and ARR2) of size N and M, respectively. 
// You need to print their intersection; 
// An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words,
// when there is a common value that exists in both the arrays/lists.

// Note :
// Input arrays/lists can contain duplicate elements.
// The intersection elements printed would be in the order they appear in the second array/list (ARR2).

#include<bits/stdc++.h>
using namespace std;

void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    unordered_map<int, int> map1;
    unordered_map<int, int> map2;

    // iterate over elements of first array and update their frequency as their values
    for(int i = 0 ; i < n ; i++){
        if(map1.count(arr1[i])>0){
            map1.at(arr1[i]) += 1;
        }else{
            map1[arr1[i]] = 1;
        }
    }

    // iterate over elements of second array and update their frequency as their values
    for(int i = 0 ; i < m ; i++){
        if(map2.count(arr2[i])>0){
            map2.at(arr2[i]) += 1;
        }else{
            map2[arr2[i]] = 1;
        }
    }

    // to print elements in order wrt arr2, iterate over its elements
    for(int i = 0 ; i < m ; i++){
        // check if there exists an intersection between elements of arr1 and arr2
        if(map1.count(arr2[i])>0){
            // if intersection exists then print the element/key based on min frequency count match
            for(int j = 0 ; j < min(map1.at(arr2[i]), map2.at(arr2[i])); j++){
                cout<<arr2[i]<<"\n";
            }
            map1.at(arr2[i]) = 0; // update the count to 0 => indicating visited
        } // else continue
        else{
            continue;
        }
    }
    return;
}


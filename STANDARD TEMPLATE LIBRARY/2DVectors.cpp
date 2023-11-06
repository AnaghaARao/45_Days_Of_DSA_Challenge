#include<bits/stdc++.h>
using namespace std;

int main(){

    // METHOD-1 OF MAKING A 2D VECTORS

    int r , c;
    cin >> r >> c;

    vector<int> arr[r];

    // making the vector of size r*c
    for(int i = 0 ; i < r ; i++) arr[i].resize(c);

    // taking input from user
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++) cin >> arr[i][j];
    }

    // printing sum of each row
    for(int i = 0 ; i < r ; i++){
        int sum = 0;
        for(int j = 0 ; j < c ; j++) sum += arr[i][j];
        cout << sum << endl;
    }

    // METHOD-2 OF MAKING 2D VECTORS
    
    // making the vector of size r*c
    vector<vector<int>> arr1(r , vector<int>(c , 0)); // direct method
    for(int i = 0 ; i < r ; i++) arr1.push_back(vector<int>(c)); // indirect method
    // used when initializing vector as vector<vector<int>>arr

    // printing sum of each row
    for(int i = 0 ; i < r ; i++){
        int sum = 0;
        for(int j = 0 ; j < c ; j++) sum += arr1[i][j];
        cout << sum << endl;
    }
}

/*
    2D vectors => vector of vectors
*/
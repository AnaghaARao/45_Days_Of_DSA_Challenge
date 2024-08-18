#include<bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates(int* a, int n){
    vector<int> res;
    unordered_map<int, bool> check; 
    // taking unordered_map cause time complexity is O(1) for each operation
    for(int i = 0 ; i < n ; i++){
        if(check.count(a[i])>0){ // check if key already there
            continue;
        }else{
            check[a[i]] = true;
            res.push_back(a[i]);
        }
    }
    return res;
}
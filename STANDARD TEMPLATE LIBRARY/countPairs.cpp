/*
    PROBLEM STATEMENT:
    Count Pairs
    You have been given a vectors of pairs. Your task is to complete the function given which counts the pairs which have first value greater than their second value and returns the count.
*/

#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<pair<int,int>> a){
    int cnt = 0;
    for( auto item : a){
        if(item.first > item.second) cnt++;
    }
    return cnt;
}

int main(){
    
    int n;
    cin>>n;
    
    vector<pair<int,int>> a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    cout<<countPairs(a);
    return 0;
}
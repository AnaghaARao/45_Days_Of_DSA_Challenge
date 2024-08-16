#include<bits/stdc++.h>
using namespace std;

void kSortedArray(vector<int>&v, int k){
    priority_queue<int>pq;
    for(int i = 0 ; i < k ; i++){
        pq.push(v[i]); // insert first k elements into the queue
    }
    int j = 0; // to keep track of index of sorted array
    for(int i = k ; i < v.size() ; i++){
        v[j] = pq.top(); // getting the max element and placing in the right index in original vector
        pq.pop(); // removing the max element from PQ
        pq.push(v[i]); // pushing the new element to match the next max element in the range of k for the next index
        j++; 
    }
    // till now only n-k elements are sort...the below code will sort the entire list
    while(!pq.empty()){
        v[j] = pq.top();
        pq.pop();
        j++;
    }
}

int main(){
    vector<int> v = {12, 15, 6,7,9};
    int k = 3;
    kSortedArray(v, k);
    for(int i = 0 ; i < v.size() ; i++) cout<<v[i]<<" ";
    return 0;
}
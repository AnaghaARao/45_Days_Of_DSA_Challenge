// Problem statement
// You are given a stream of 'N' integers. 
// For every 'i-th' integer added to the running list of integers, print the resulting median.
// Print only the integer part of the median.

#include<bits/stdc++.h>
using namespace std;

void findMedian(int arr*, int n){
    if(n == 0) return;
    if(n == 1){
        cout<<arr[0]<<endl;
        return;
    }

    priority_queue<int> left; //max heap for the elements on the left side of the sorted list
    priority_queue<int, vector<int>, greater<int>> right; // min heap for elements on the right side of the sorted list

    // print the first element - the median of 1st input
    left.push(arr[0]);
    cout<<arr[0]<<" ";

    // dealing with the remaining inputs
    for(int i = 1 ; i < n ; i++){
        // entering element into heap based on its value
        if(arr[i] < left.top()){
            left.push(arr[i]);
        }else{
            right.push(arr[i]);
        }

        // normalizing the sizes of both the heaps
        if(left.size() > right.size()+1){ 
            right.push(left.top());
            left.pop();
        }else if(right.size() > left.size()){
            left.push(right.top());
            right.pop();
        }

        // due to 0 based indexing, if i is even, then are even num of elements => median is middle term placed at left.top() 
        // else if i is odd, then there are odd num of elements => median is the avg of middle 2 terms
        if(i%2==0){
            cout<<left.top()<<" ";
        }else{
            cout<<(left.top()+right.top())/2<<" ";
        }
    }
    return;
}
// In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of 
// the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.
// For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. 
// These are the only nodes with twins for n = 4.
// The twin sum is defined as the sum of a node and its twin.
// Given the head of a linked list with even length, return the maximum twin sum of the linked list.

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int pairSum(ListNode* head) {
    
    if(head == nullptr) return 0; // base case
    vector<int> nodes;
    ListNode* temp = head; // temp root to traverse the linkedlist
    while(temp!=NULL){ // temp should visit all the nodes present in the linkedlist 
        nodes.push_back(temp->val);
        temp = temp->next;
    }

    int max_value = INT_MIN;
    int n = nodes.size();
    for(int i = 0 ; i < n/2 ; i++){
        max_value = max(max_value, nodes[i]+nodes[n-i-1]); // finding max of all twin pairs in the LL
    }
    return max_value;

}
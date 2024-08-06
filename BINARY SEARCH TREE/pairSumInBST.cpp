// Problem statement
// Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. 
// You can use extra space of the order of O(log n).

#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
#include "BinarySearchTree.h"
using namespace std;

void getNodes(BinaryTreeNode<int>* root, vector<int>& v){
    if(root == NULL) return;
    v.push_back(root->data);
    getNodes(root->left, v);
    getNodes(root->right, v);
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    if(root == NULL) return;

    vector<int> nodes;
    getNodes(root, nodes);

    sort(nodes.begin(), nodes.end());
    int start = 0, end = nodes.size()-1;
    while(start<end){
        if(nodes.at(start)+nodes.at(end) == s){
            cout<<nodes.at(start)<<" "<<nodes.at(end)<<endl;
            start++;
            end--;
        }else if(nodes[start]+nodes[end] > s) end--;
        else start++;
    }
    return;
}
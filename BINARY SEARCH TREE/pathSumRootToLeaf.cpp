// Problem statement
// For a given Binary Tree of type integer and a number K, 
// print out all root-to-leaf paths where the sum of all the node data along the path is equal to K.

#include<bits/stdc++.h>
#include "BinarySearchTree.h"
using namespace std;

// approach
// recursive function:
// reduces the value of k for each node encountered, ie, k -= root->data
// if its leaf node => if k==0 then  .....if yes print all the nodes in path
// then remove the curr_node from path
// if left and right sub tree exists, recursively call them
// finally pop_back() the last element

void helper(BinaryTreeNode<int>* root, int k, vector<int> &path){ // dont pass k as pass by reference....cause then all subtrees will get new updated value
    k -= root->data;
    path.push_back(root->data);

    if(root->left == NULL && root->right == NULL){
        if(k == 0){
            for(int i = 0 ; i < path.size() ; i++) cout<<path[i]<<" ";
            cout<<endl;
            path.pop_back();
            return;
        }
    }

    if(root->left) helper(root->left, k, path);
    if(root->right) helper(root->right, k, path);

    path.pop_back();
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    if(root == NULL) return;

    vector<int> path;
    helper(root, k, path);

    // for(int i = 0 ; i < path.size() ; i++) cout<<path[i]<<" ";
    return;
}
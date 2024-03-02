/*
Given a binary tree, remove all leaf nodes from it. 
Leaf nodes are those nodes, which don't have any children.
Note:
1. Root will also be a leaf node if it doesn't have left and right child. 
2. You don't need to print the tree, just remove all leaf nodes and return the updated root.

*/

#include<bit/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    if(root == NULL) return nullptr;
    // induction step
    if(root->left == NULL && root->right == NULL) return nullptr;

    // recursive call to check if the node is a leaf node:
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);

    return root;

}
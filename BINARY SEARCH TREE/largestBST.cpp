// Problem statement
// Given a Binary tree, find the largest BST subtree. 
// That is, you need to find the BST with maximum height in the given binary tree. 
// You have to return the height of largest BST.

// Note :
// The binary tree will be consisting of only unique elements.

#include<bits/stdc++.h>
#include "BinarySearchTree.h"
using namespace std;

bool isBST(BinaryTreeNode<int>* root, int& h){
    if(root == NULL) return true;

    bool leftFlag = false, rightFlag = false;
    if(root->left){
        if(root->left->data <= root->data && isBST(root->left, h)) leftFlag = true;
    }

    if(root->right){
        if(root->right->data > root->data && isBST(root->right, h)) rightFlag = true;
    }

    if(leftFlag && rightFlag){
        h++;
        return true;
    }

    h--;
    return false;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // logic to find bst from top to bottom
}
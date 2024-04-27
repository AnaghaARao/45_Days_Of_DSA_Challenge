/* Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). 
If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree. */


// APPROACH
// To check if a binary tree is a Binary Search Tree (BST), we need to traverse the tree and ensure that each node satisfies the BST property. 
// Perform an in-order traversal of the binary tree.
// While traversing, keep track of the previously visited node's value.
// At each node, compare its value with the previously visited node's value. If the current node's value is less than or equal to the previous node's value, the tree is not a BST.
// Recursively repeat steps 2 and 3 for the left and right subtrees.
// If all nodes satisfy the BST property, return true; otherwise, return false


#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

bool helper(BinaryTreeNode<int>* root, int &prev){
    if(root == nullptr) return true;

    if(!helper(root->left,prev)){
        return false;
    }

    // check for left subtree recursively
    if(root->data <= prev){
        return false;
    }

    // update prev
    prev = root->data;

    // check for right subtree recursively
    return helper(root->right, prev);
}

bool isBST(BinaryTreeNode<int> *root) {
    int prev = INT_MIN;
    return helper(root, prev);
}
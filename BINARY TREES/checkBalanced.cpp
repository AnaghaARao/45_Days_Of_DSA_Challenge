/*
Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.

Balanced Binary Tree:
A empty binary tree or binary tree with zero nodes is always balanced. For a non empty binary tree to be balanced, following conditions must be met:
1. The left and right subtrees must be balanced.
2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.   
*/

#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;
int height(BinaryTreeNode<int>* root){
    if(root == NULL) return 0;
    return max(1+height(root->left), 1+height(root->right));
}
bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL) return true;
    return (abs(height(root->left)-height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right));
}
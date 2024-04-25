/* Given a BST and an integer k. Find if the integer k is present in given BST or not. 
You have to return true, if node with data k is present, return false otherwise.
Note:
Assume that BST contains all unique elements. */

#include<bits/stdc++.h>
#include "BinaryTreeNode.h";
using namespace std;

bool searchInBST(BinaryTreeNode<int> *root , int k) {
	// base case 
    if(root == nullptr) return false;
    if(root->data == k) return true;
    // recursive & induction step
    else if(root->data > k) return searchInBST(root->left, k);
    else return searchInBST(root->right, k);
}
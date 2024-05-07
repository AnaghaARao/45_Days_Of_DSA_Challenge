#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

// we are working on the principle that all elements in left subtree must be smaller than the root
// and all the elements in right subtree should be greater than the root
// to check for this we compare the min of right subtree and max of left subtree with the root
// basically: max of lst shd be less than root and min of rst should be greater than or equal to the root
// this should be true for all subtrees are well

int minimum(BinaryTreeNode<int>* root){
    if(root == NULL) return INT_MAX;
    return min(root->data, min(minimum(root->right), minimum(root->left)));
}

int maximum(BinaryTreeNode<int>* root){
    if(root == NULL) return INT_MIN;
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool checkBST(BinaryTreeNode<int>* root){
    // base case:
    if(root == NULL) return true;

    // induction step
    int leftmax = maximum(root->left);
    int rightmin = inimum(root->right);
    bool res = (leftmax < root->data) && (rightmin >= root->data) && checkBST(root->left) && checkBST(root->right);
    return res;
}





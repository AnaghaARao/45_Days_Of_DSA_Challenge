// Problem statement
// Given a Binary tree, find the largest BST subtree. 
// That is, you need to find the BST with maximum height in the given binary tree. 
// You have to return the height of largest BST.

// Note :
// The binary tree will be consisting of only unique elements.

#include<bits/stdc++.h>
#include "BinarySearchTree.h"
using namespace std;

class Pair{
    public:
    int height;
    bool check;
    int minVal;
    int maxVal;
    Pair(bool flag, int h, int min, int max){
        height = h;
        check = flag;
        minVal = min;
        maxVal = max;
    }

};

Pair isBST(BinaryTreeNode<int>* root){

    if(root == NULL) return Pair(true, 0, INT_MAX, INT_MIN);

    Pair left = isBST(root->left);
    Pair right = isBST(root->right);

    if(left.check && right.check && root->data > left.maxVal && root->data < right.minVal){ // check if root is part of BST
        int max = max(root->data, right.maxVal); // update bst max
        int min = min(root->data, left.minVal); // update bst min
        int height = max(left.height , right.height) + 1; // increment height of true
        return Pair(true, height, min, max);
    }

    return Pair(false, max(left.height, right.height), 0, 0); 
    // if not, reset the min and max value, eturn max of previous BST height and return false

}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // logic to find bst from top to bottom
    if(root == NULL) return 0;
    Pair res = isBST(root);
    return res.height;
}
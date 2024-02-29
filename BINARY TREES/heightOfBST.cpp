/*For a given Binary Tree of integers, find and return the height of the tree. Height is defined as the total number of nodes along the longest path from the root to any of the leaf node.*/

#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

int height(BinaryTreeNode<int>* root) {
    // Write our code here
    if(root == NULL) return 0;
    return max(1+height(root->left), 1+height(root->right));    
}
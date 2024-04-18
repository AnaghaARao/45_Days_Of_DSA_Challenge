/* Diameter of a Binary Tree is the maximum distance between any 2 nodes.
Distance is determined based on number of edges encountered
It is usually computed as LeftHeight + RightHeight... but this 
may not always be true [especially when these heights have huge inequality] */

#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

int height(BinaryTreeNode<int>* root){
    if(root == NULL) return 0;

    return 1 + max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    // dia = leftHeight + rightHeight
    int option1 = height(root->left) + height(root->right);
    // dia = dia of left subtree
    int option2 = diameter(root->left);
    // dia = dia of right subtree
    int option3 = diameter(root->right);

    return max(option1, option2, option3);
}

// TIME COMPLEXITY : n*h
// h = logn in case of compact tree
// or h = n when tree grows in majorly/ only 1 direction
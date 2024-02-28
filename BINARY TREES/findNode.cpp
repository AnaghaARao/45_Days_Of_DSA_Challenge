/*For a given Binary Tree of type integer and a number X, find whether a node exists in the tree with data X or not.*/

#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here
    // base case
    if (root == NULL) return false;
    if(root->data == x) return true;
    //recursive statement and induction statement
    return (isNodePresent(root->left, x)||isNodePresent(root->right,x));
}
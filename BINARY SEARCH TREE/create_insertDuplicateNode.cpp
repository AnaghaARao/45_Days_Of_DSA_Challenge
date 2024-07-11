// Problem statement
// For a given a Binary Tree of type integer, duplicate every node of the tree and attach it to the left of itself.
// The root will remain the same. So you just need to insert nodes in the given Binary Tree.

#include<bits/stdc++.h>
#include "BinarySearchTree.h"
using namespace std;

void insertDuplicateNode(BinaryTreeNode<int> *root) {
    // Base case
    if (root == NULL) return;

    // duplication and insertion
    BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(root->data);
    newNode->left = root->left;
    root->left = newNode;

    // left recursive call
    if(root->left != NULL) insertDuplicateNode(root->left->left);
    // right recursive call
    if(root->right != NULL) insertDuplicateNode(root->right);
}
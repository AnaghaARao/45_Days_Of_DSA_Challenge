// Problem statement
// Given a binary search tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the BST.

// LCA
// LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants. 

#include<bits/stdc++.h>
#include "BinarySearchTree.h"
using namespace std;

bool path(BinaryTreeNode<int>* root, int x, vector<int>& v){
    if(root == NULL) return false;

    v.push_back(root->data);

    if(root->data == x) return true;

    if((root->data > x && path(root->left, x, v)) || (root->data < x && path(root->right, x, v))) return true;

    v.pop_back();
    return false;
}

int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){

    if(root == NULL) return -1;

    vector<int> path1, path2;

    if(!path(root, val1, path1) || !path(root, val2, path2)) return -1;

    int index = -1;
    for(int i = 0 ; i < min(path1.size(), path2.size()); i++){
        if(path1[i] == path2[i]) index = path1[i];
        else break;
    }

    return index;
}

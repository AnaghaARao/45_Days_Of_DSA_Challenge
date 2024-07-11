// Problem Statment:
// Given a binary tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the binary tree.
// LCA
// LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants. 

#include<bits/stdc++.h>
#include "BinarySearchTree.h"
using namespace std;

bool findPath(BinaryTreeNode<int>* root, int x, vector<int>& v){
    // base case
    if(root == NULL) return false;

    v.push_back(root->data);

    if(root->data == x) return true;

    if((root->left && findPath(root->left, x, v))|| (root->right && findPath(root->right, x, v))) return true;

    v.pop_back();
    return false;
}


int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    if(root == NULL) return -1;

    vector<int> pathA, pathB;

    if(!findPath(root, a, pathA) || !findPath(root, b, pathB)) return -1;

    int index = -1;
    for(int i = 0; i < min(pathA.size(), pathB.size()); i++){
        if(pathA[i]== pathB[i]) index = pathA[i];
        else break;
    }
    return index;
}
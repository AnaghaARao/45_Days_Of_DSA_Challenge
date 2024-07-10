/* Given a sorted integer array A of size n, which contains all unique elements. 
You need to construct a balanced BST from this input array. 
Return the root of constructed BST.
Note: If array size is even, take first mid as root. */

#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* constructTreeHelper(int *input, int start, int end){
    if(start > end) return nullptr;

    int mid = (end+start)/2;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
    root->left = constructTreeHelper(input, start, start+mid);
    root->right = constructTreeHelper(input,mid+1, end);
    return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
    BinaryTreeNode<int>* root = constructTreeHelper(input, 0, n-1);
    return root;
}
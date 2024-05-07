/* Given a sorted integer array A of size n, which contains all unique elements. 
You need to construct a balanced BST from this input array. 
Return the root of constructed BST.
Note: If array size is even, take first mid as root. */

#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* constructTree(int *input, int n) {
    int mid;
    if(n%2 == 0) mid = n/2-1;
    else mid = n/2;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
    BinaryTreeNode<int>* leftTree = constructTree(input, n/2-1);
    BinaryTreeNode<int>* rightTree = constructTree(input+mid+1, n/2-1);
    root->left = leftTree;
    root->right = rightTree;
    return root;
}
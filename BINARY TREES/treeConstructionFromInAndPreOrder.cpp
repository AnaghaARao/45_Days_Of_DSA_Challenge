/*
pre-order : root --> left subtree --> right subtree
in-order : left subtree --> root --> right subtree

root: we get it from pre-order's first element
left-subtree : we take it from in-order and pre-order. How?
determine LEFT INORDER START AND END: start - from first index ; end - len of preorder & inorder left ST is same == root+length
determine LEFT PRE-ORDER START & END: start - right after root ; end - when root is encountered == rootIndex - 1
note : length = pre-order(end-start)

right-subtree : similarly we determine positions of right inorder and pre-order start and end indices

*/

/* PROBLEM STATEMENT: 
For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, 
create the binary tree using the given two arrays/lists. 
You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements. 
*/

#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    
    if(preLength == 0 || inLength == 0){
        return nullptr;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[0]);

    int rootIndex;
    // finding root index in inorder traversal
    for(int i = 0 ; i < inLength ; i++){
        if(inorder[i] == preorder[0]){
            rootIndex = i;
            break;
        }
    }

    // recursive calls and induction statement:
    root->left = buildTree(preorder + 1 , rootIndex , inorder, rootIndex);
    root->right = buildTree(preorder + rootIndex + 1 , preLength - rootIndex - 1 , inorder + rootIndex + 1 , inLength - rootIndex - 1);

    return root;
    
}


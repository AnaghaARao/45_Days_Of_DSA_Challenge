/*
Problem statement
For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, 
create the binary tree using the given two arrays/lists. 
You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements.
*/

#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {

 if(postLength == 0 || inLength == 0)   {
    return nullptr;
 }

    BinaryTreeNode<int>* root  = new BinaryTreeNode<int>(postorder[postLength-1]);

    int rootIndex;
    for(int i = 0 ; i < inLength ; i++){
        if(inorder[i] == postorder[postLength-1]){
            rootIndex = i;
            break;
        }
    }

    root->left = buildTree(postorder , rootIndex , inorder, rootIndex);
    root->right = buildTree(postorder + rootIndex , postLength - rootIndex - 1 , inorder + rootIndex + 1 , inLength - rootIndex - 1);

    return root;
}
/*For a given Binary Tree of type integer, update it with its corresponding mirror image*/

#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    // Write your code here
	if(root == NULL) return;
	BinaryTreeNode<int>* temp = root->left;
	root->left = root->right;
	root->right = temp;
	mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}
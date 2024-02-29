/*
Level traversal: traversing level-wise
Pre-order: first print the root and then print the children: node->l->r
Post-order: first print the children and then print the root: l->r->node
INORDER TRAVERSAL: left->node->right
*/

#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

void inorderTraversal(BinaryTreeNode<int>* root){
    if(root == NULL) return;
    inorderTraversal(root->left);
    cout<<root->data<<"\t";
    inorderTraversal(root->right);
    cout<<endl;
}
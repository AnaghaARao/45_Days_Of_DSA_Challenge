#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

void postOrder(BinaryTreeNode<int> *root) {
	if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<"\t";
}
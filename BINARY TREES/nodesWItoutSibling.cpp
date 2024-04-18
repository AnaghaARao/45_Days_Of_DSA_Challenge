/* For a given Binary Tree of type integer, 
print all the nodes without any siblings. */

#include<bits/stdc++.h>
using namespace std;

void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    // Write your code here

    if(root == NULL) return;

    if((root->left != NULL && root->right == NULL ) || (root->left == NULL && root->right != NULL)){
        if(root->left == NULL) cout<<root->right->data<<"\t";
        else cout<< root->left->data<<"\t";
    }

    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);

    
}
#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

void preOrder(TreeNode<int> *root){
    if(root == nullptr) return;
    cout << root->data <<" ";
    for(int i = 0 ; i < root->children.size(); i++){
        preOrder(root->children[i]);
    }
}

void postOrder(TreeNode<int>* root){
    if(root == nullptr) return;
    for(int i = 0 ; i < root->children.size(); i++){
        postOrder(root->children.at(i));
    }
    cout<< root->data << " ";
}
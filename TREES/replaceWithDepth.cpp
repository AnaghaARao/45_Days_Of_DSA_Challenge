/*
You are given a generic tree. You have to replace each node with its depth value. 
You just have to update the data of each node, there is no need to return or print anything.
*/

#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

void helper(TreeNode<int>* root, int depth){
    if(root == nullptr) return;

    root->data = depth;

    for(int i = 0 ; i < root->children.size() ; i++){
        helper(root->children.at(i), depth+1);
    }

    return;
}

void replaceWithDepthValue(TreeNode<int>* root) {
    helper(root, 0);
}
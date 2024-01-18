/*
Given a generic tree, find and return the node with maximum data. You need to return the node which is having maximum data.
Return null if tree is empty.
*/

#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    if(root == nullptr){
        return nullptr;
    }

    TreeNode<int>* maxNode = root;
    for(int i = 0 ; i < root->children.size() ; i++){
        TreeNode<int>* childMax = maxDataNode(root->children[i]);
        if(childMax->data > maxNode->data) {
            maxNode = childMax;
        }
    }
    return maxNode;
}
/*
Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.
Note: Return NULL if no node is present with the value greater than n.
*/

#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    if(root == nullptr) return nullptr;
    TreeNode<int>* ans = nullptr;
    if(root->data > x){
        if(ans == nullptr || ans->data < root->data){
            ans = root;
        }
    }
    
    for(int i = 0 ; i < root->children.size() ; i++){
        TreeNode<int>* smallAns = getNextLargerElement(root->children.at(i), x);
        if(smallAns != nullptr && (ans == nullptr || smallAns->data < ans->data)){
            ans = smallAns;
        }
    }
    return ans;
}
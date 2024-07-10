/*Problem statement
Given a BST and an integer k. 
Find and return the path from the node with data k and root (if a node with data k is present in given BST) in a list. 
Return empty list otherwise.
Note: Assume that BST contains all unique elements.*/

#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
    if(root == NULL) return NULL;

    if(root->data == data){
        vector<int>* res = new vector<int>();
        res->push_back(root->data);
        return res;
    }
    else if(root->data > data){
        // traverse left subtree
        vector<int>* res = getPath(root->left, data);
        if(res != NULL){
            res->push_back(root->data);
        }
        return res;
        
    }else{
        // traverse right subtree
        vector<int>* res = getPath(root->right, data);
        if(res != NULL){
            res->push_back(root->data);
        }
        return res;
    }

    return NULL;

}
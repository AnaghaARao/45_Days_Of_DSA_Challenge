/*
Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
*/

#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Pair{
    public:
        TreeNode<int>* largest;
        TreeNode<int>* nextLargest;
        Pair(TreeNode<int>* node1, TreeNode<int>* node2){
            largest = node1;
            nextLargest = node2;
        }
};

Pair* helper(TreeNode<int>* root){
    if(root == nullptr) return new Pair(nullptr, nullptr);

    TreeNode<int>* largest = root;
    TreeNode<int>* secondLargest = nullptr;

    for(int i = 0 ; i < root->children.size() ; i++){
        Pair* temp = helper(root->children.at(i));

        if(temp->largest->data > largest->data){
            secondLargest = largest;
            largest = temp->largest;
        }
        else if(temp->largest->data < largest->data && (secondLargest==nullptr || temp->largest->data > secondLargest->data)){
            secondLargest = temp->largest;
        }

        if(temp->nextLargest!=nullptr && (secondLargest == nullptr || temp->nextLargest->data > secondLargest->data)){
            secondLargest = temp->nextLargest;
        }
    }

    return new(largest,secondLargest);
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    Pair* result = helper(root);
    return result->nextLargest;
}
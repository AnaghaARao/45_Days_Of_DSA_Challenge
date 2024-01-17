#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInput() {
    int rootData;
    cout<< "Enter data\n";
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    int n;
    cout<< "Enter no. of children of "<< rootData << endl;
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int>* root){
    if(root==NULL) return; // #Edge_Case
    cout<< root->data <<":";
    for(int i = 0 ; i < root->children.size() ; i++){
        cout<< root->children.at(i)->data << ",";
    }
    cout<< endl;
    for(int i = 0 ; i < root->children.size() ; i++){
        printTree(root->children.at(i));
    }
    // no need for a base case as the loop automatically works as one
}

int main(){
    // TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* node1 = new TreeNode<int>(2);
    // TreeNode<int>* node2 = new TreeNode<int>(3);

    // root->children.push_back(node1);
    // root->children.push_back(node2);

    TreeNode<int>* root = takeInput();
    printTree(root);
    // ToDo delete the tree
}
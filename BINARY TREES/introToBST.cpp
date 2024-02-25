#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

void printTree(BinaryTreeNode<int>* root){
    // base case:
    if(root == NULL) return;
    // induction step    
    cout<< root->data <<":" << endl;
    if(root->left != NULL){
        cout << "L " << root->left->data<<"\t";
    }
    if(root->right != NULL){
        cout << "R " << root->right->data;
    }
    cout<<endl;
    // recursive call
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout<< "Enter root data" << endl;
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

int main(){
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
    root->left = node1;
    root->right = node2;
    printTree(root);
    delete root;
}
// Problem statement
// Implement the BST class which includes following functions -

// 1. insert -
// Given an element, insert that element in the BST at the correct position. 
// If element is equal to the data of the node, insert it in the left subtree.

// 2. search
// Given an element, find if that is present in BST or not. Return true or false.

// 3. delete -
// Given an element, remove that element from the BST. 
// If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.

// 4. printTree (recursive) -
// Print the BST in in the following format -

// For printing a node with data N, you need to follow the exact format -

// N:L:x,R:y
// where, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. 
// Print the children only if it is not null.

// There is no space in between.

// You need to print all nodes in the recursive format in different lines.

#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

class BST<int>{
    private:
        BinaryTreeNode<int>* root;

        bool searchHelper(int data, BinaryTreeNode<int>* root){
            // helper function for search operation
            if(root == NULL){
                return false;
            }
            if(root->data == data) return true;

            if(root->data > data){
                // call on left subtree
                return searchHelper(data, root->left);
            }
            else{
                // call on right subtree
                return searchHelper(data, root->right);
            }
            
        }

        BinaryTreeNode<int>* insertHelper(int data, BinaryTreeNode<int>* root){
            if(root == NULL){
                BinaryTreeNode<int>* temp = new BinaryTreeNode<int>(data);
                root = temp;
                return root;
            }
            
            if(root->data >= data){
                // call left subtree
                root->left = insertHelper(data, root->left);
            }else{
                // call right subtree
                root->right = insertHelper(data, root->right);
            }
            return root;
        }

        // returns the value of the minimum node
        int findMinVal(BinaryTreeNode<int>* root){
            int k = root->data;
            if(root->left != NULL){
                k = min(k, findMinVal(root->left));
            }
            
            return k;
        }

        BinaryTreeNode<int>* deleteHelper(int data, BinaryTreeNode<int>* root){
            if(root == NULL) return root;

            if(root->data > data){
                root->right = deleteHelper(data, root->right);
            }
            else if(root->data < data){
                root->left = deleteHelper(data, root->left);
            }
            else if(root->data == data){
                // case 1: leaf node:
                if(root->left == NULL && root->right == NULL){
                    delete root;
                    return NULL;
                } // case 2: only 1 child present
                else if(root->left == NULL || root->right == NULL ){
                    if(root->left == NULL) return root->right;
                    return root->left;
                } // case 3: both children are present - so search for largest node in left-subtree or smallest node in right-subtree
                else{
                    int newRootData = findMinVal(root->right);
                    BinaryTreeNode<int>* rightRoot = deleteHelper(newRootData, root->right);
                    BinaryTreeNode<int>* newRoot = new BinaryTreeNode<int>(newRootData);
                    newRoot->left = root->left;
                    newRoot->right = rightRoot;
                    delete root;
                    return newRoot;
                }
            }

        }

        void printHelp(BinaryTreeNode<int>* root){
            if(root == NULL) return;

            cout<<root->data<<":";

            if(root->left!=NULL){
                cout<<"L:"<<root->left->data<<",";
            }
            if(root->right!=NULL){
                cout<<"R:"<<root->right->data;
            }
            cout<<endl;
            
            printHelp(root->left);
            printHelp(root->right);

        }

    public:
        BST() {
            root = NULL;
        }
        ~BST() {
            delete root;
        }
        
        bool search(int data){
            return searchHelper(data, root);
        }

        void remove(int data) { 
        // Implement the remove() function 
        root = deleteHelper(data, root);
        }

        void print() { 
            // Implement the print() function
            printHelp(root);
        }

        void insert(int data) { 
            // Implement the insert() function 
            root = insertHelper(data, root);
        }

};
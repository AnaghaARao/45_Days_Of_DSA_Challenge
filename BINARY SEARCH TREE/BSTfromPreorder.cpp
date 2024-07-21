// Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), 
// construct the tree and return its root.It is guaranteed that there is always possible to find a binary search tree 
// with the given requirements for the given test cases. A binary search tree is a binary tree where for every node, 
// any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value 
// strictly greater than Node.val. A preorder traversal of a binary tree displays the value of the node first, 
// then traverses Node.left, then traverses Node.right.

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// PROCEDURE TO CREATE BINARY TREE FROM PREORDER:

// // returns root index
// int getIndex(vector<int> order, int data){
//     int i;
//     for(i = 0 ; i < inorder.size() ; i++){
//         if(inorder[i] == data) break;
//     }
//     return i;
// }

// // creates Preorder of left subtree and right subtree
// void createSubTree(vector<int> preorder, vector<int> inorder){
//     int data = preorder[0];
//     vector<int> lst, rst;

//     int index = getIndex(inorder, data)
//     lst.assign(inorder.begin(), inorder.begin()+index);
//     rst.assign(inorder.begin()+index+1, inorder.end());

// }

// // return inorder of tree
// vector<int> getInorder(vector<int>& preorder){
//     // returns inorder

//     vector<int> inorder;
//     inorder.assign(preorder.begin(), preorder.end());
//     sort(inorder.begin(), inorder.end());
//     return inorder;
// }

// TreeNode* createNode(int data){
//     TreeNode* root = new TreeNode(data);
//     return root;
// }

TreeNode* placeNode(TreeNode* root, int data){
    if(root == NULL){
        root = new TreeNode(data);
    }else if(root->val >= data){
        root->left = placeNode(root->left, data);
    }else{
        root->right = placeNode(root->right, data);
    }

    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    
    Treenode* root = NULL;
    for(int ele: preorder){
        root = placeNode(root, ele);
    }
    return root;
}


// create root if not exists
// if current element is less than root->val move to left subtree
// else move to right subtree
// after it is placed u must return the original root only

// CHECK IF TREE IS BST USING TOP DOWN APPROACH

#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

bool isBST(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX){
    if(root == NULL) return true;
    if(root->data < min && root->data > max) return false;

    bool isLeftBST = isBST(root->left, min, root->data-1);
    bool isRightBST = isBST(root->data, root->data, max);
    return isLeftBST && isRightBST;
}
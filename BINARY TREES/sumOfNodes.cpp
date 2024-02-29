/*For a given Binary Tree of integers, find and return the sum of all the nodes data.*/

#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

int getSum(BinaryTreeNode<int>* root) {
    // Write your code here
    if(root == NULL) return 0;
    return root->data + getSum(root->left) + getSum(root->right);
}
#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

vector<int> preOrder(TreeNode<int> * root){
    vector<int> result;
    if(root == NULL){
        return result;
    }

    vector<int> leftPreorder = preOrder(root->left);
    result.insert(result.end(), leftPreorder.begin(), leftPreorder.end());

    vector<int> rightPreorder = preOrder(root->right);
    result.insert(result.end(), rightPreorder.begin(), rightPreorder.end());

    return result;
}
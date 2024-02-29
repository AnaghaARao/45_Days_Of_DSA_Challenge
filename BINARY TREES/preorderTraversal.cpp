#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

vector<int> preOrder(TreeNode<int> * root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    vector<int> leftPreorder = preOrder(root->left);
    ans.insert(ans.end(), leftPreorder.begin(), leftPreorder.end());

    vector<int> rightPreorder = preOrder(root->right);
    ans.insert(ans.end(), rightPreorder.begin(), rightPreorder.end());

    return ans;
}
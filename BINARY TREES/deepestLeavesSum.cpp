// Problem Statement:
// Given the root of a binary tree, return the sum of values of its deepest leaves.

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
void helper(TreeNode* root, vector<vector<int>> &v, int &h){
    if(root == NULL) return;

    vector<int> pair = [h, root->data];
    v.push_back(pair);
    h++;

    if(root->left){
        helper(root->left, v, h);
    }

    if(root->right){
        helper(root->right, v, h);
    }

    h--;

    return;
}

int deepestLeavesSum(TreeNode* root) {
    if(root == NULL) return 0;

    vector<vector<int>> v(vector<int>(0),0);
    int h = 0;
    helper(root, v, h);

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    int max = v[0][0];
    int res = 0;
    for(int i = 0 ; i < v.size() ; i++){
        if(v[i][0]==max) res+=v[i][1];
    }

    return res;
    
}
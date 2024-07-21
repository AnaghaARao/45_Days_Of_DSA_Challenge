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

void getSum(TreeNode* root, int& sum){
    if(root->left){
        sum += root->left->val;
    }
    if(root->right){
        sum += root->right->val;
    }
    return;
}

void traverse(TreeNode* root, int& sum){

    if((root->val)%2 == 0){
        if(root->left != NULL) getSum(root->left, sum);
        if(root->right != NULL) getSum(root->right, sum);
    }

    if(root->left) traverse(root->left, sum);
    if(root->right) traverse(root->right, sum);

    return;

}

int sumEvenGrandparent(TreeNode* root) {
    if(root == NULL || (root->left == NULL && root->right == NULL)) return 0;

    int sum = 0;
    traverse(root, sum);
    return sum;
}
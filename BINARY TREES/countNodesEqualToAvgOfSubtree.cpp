// Problem Statement
// Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

// Note:
// The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
// A subtree of root is a tree consisting of root and all of its descendants.

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


// we need 3 functions:
// 1. to find sum and number of elements
// 2. to traverse in left->right->root order and call for sum
// 3. main calling function -> presented by platform

int findSum(TreeNode* root, int& n){
    if(root == NULL) return 0;

    if(root->left == NULL && root->right  == NULL){
        n++;
        return root->val;
    }

    n++;
    // int leftSum = 0, rightSum = 0;
    int leftSum = findSum(root->left, n);
    int rightSum = findSum(root->right, n);
    int sum = root->val+leftSum+rightSum;
    return sum;
}

void myTraversal(TreeNode* root, int& cnt){
    
    if(root->left){
        myTraversal(root->left, cnt);
    }
    if(root->right){
        myTraversal(root->right, cnt);
    }

    int left = 0 , right = 0;
    int leftSum = 0 , rightSum = 0;
    leftSum = findSum(root->left, left);
    rightSum = findSum(root->right, right);

    int avg = (root->val+leftSum+rightSum)/(left+right+1);
    if(avg == root->val) cnt++;

}

int averageOfSubtree(TreeNode* root) {
    int cnt = 0;
    if(root == NULL) return 0;
    myTraversal(root, cnt);
    return cnt;
}































// int getSum(TreeNode* root, int& n, int& cnt){
//     if(root == NULL) return 0;

//     cout<<root->val<<" "<<n << " "<<cnt<<endl;

//     // call for lst
//     int leftSum = getSum(root->left, n,cnt);
//     // call for rst
//     int rightSum = getSum(root->right, n, cnt);
//     // updated sum
//     n++;
//     int sum = root->val + leftSum + rightSum;
//     // check for avg = root->val
//     if(sum/n == root->val) cnt++;

//     return sum;
// }

// // void helper(TreeNode* root, int sum, int& n, int& cnt){
// //     if(root == NULL) return;

// //     if(root->left){
// //         helper(root->left, sum, n, cnt);
// //     }

// //     if(root->right){
// //         helper(root->right, sum, n, cnt);
// //     }

// //     if(root->left == NULL && root->right == NULL){
// //         sum+= root->val;
// //         n++;
// //         cnt++;
// //     }else{
// //         n++;
// //         sum += root->val;
// //         if(sum/n == root->val) cnt++;
// //     }

// //     return;
    
// // }

// int averageOfSubtree(TreeNode* root) {
//     if(root == NULL) return 0;
//     if(root->left == NULL && root->right == NULL) return 1;

//     int n = 0, sum = 0, cnt = 0;
//     sum = getSum(root, n, cnt);

//     return cnt;

// }
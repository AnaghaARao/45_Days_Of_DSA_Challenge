// Problem Statement:
// Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
// Note:
// 1. Assume the given binary tree contains all unique elements.
// 2. In a pair, print the smaller element first. Order of different pairs doesn't matter.

#include<bits/stdc++.h>
#include "BinarySearchTree.h"
using namespace std;

// vector<vector>* pairSumHelper(BinaryTreeNode<int>* root, int sum, vector<vector<int>>* v){
//     if(root == NULL) return;

//     int x = root->data;
//     int i;
//     for(i = 0 ; i < v.size() ; i++){
//         if(!v[i].empty() && (v[i][0] + x == sum)) v[i].push_back(x);
//     }
//     v[i].push_back(x);

//     v = pairSumHelper(root->left, sum, v);
//     v = pairSumHelper(root->right, sum, v);
// }

// void pairSum(BinaryTreeNode<int> *root, int sum) {
//     // Write your code here
//     if(root == NULL) return;

//     vector<vector<int>> v(100000, vector<int>(2));

//     v = pairSumHelper(root, sum, v);

//     sort(v.begin(), v.end());

//     for(int i = 0 ; i < v.size() ; i++){
//         if(v[i].size() == 2){
//             cout<<v[i][0]<<" "<<v[i][1]<<endl;
//         }
//     }
//     return;
// }

void getElements(BinaryTreeNode<int>* root, vector<int>& v){
    if(root == NULL) return;

    v.push_back(root->data);
    v = getElements(root->left);
    v = getElements(root->right);
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    if(root == NULL) return;

    vector<int> v(0);

    getElements(root, v);

    sort(v.begin(), v.end());

    int start = 0, end = v.size()-1;

    // double pointer method
    while(start < end){
        if(v[start] + v[end] == sum){
            cout<< v[start] <<" "<< v[end]<<endl;
        }else if(v[start] + v[end] > sum) end--;
        else start ++;
    }

    return;
}
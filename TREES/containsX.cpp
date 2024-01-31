// Given a generic tree and an integer x, check if x is present in the given tree or not. Return true if x is present, return false otherwise.

#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// bool isPresent(TreeNode<int>* root, int x) {
//     if(root->data == x) return true;
//     for(int i = 0 ; i < root->children.size() ; i++){
//         isPresent(root->children.at(i));
//     }
//     return false;
// }

// METHOD 2: SIMILAR TO PRINT LEVEL WISE
// bool isPresent(TreeNode<int>* root, int x) {
//     // Write your code here
//     if(root == nullptr) return false;
//     queue<TreeNode<int>*> pending;
//     pending.push(root);
//     while(!pending.empty()){
//         TreeNode<int>* front = pending.front();
//         pending.pop();
//         if(front->data == x) return true;
//         for(int i = 0 ; i < front->children.size() ; i++){
//             pending.push(front->children.at(i));
//         }
//     }
//     return false;
// }

//METHOD 3:
bool isPresent(TreeNode<int>* root, int x){
    if(root == nullptr) return false;

    if(root->data == x) return true;

    for(int i = 0 ; i < root->children.size() ; i++){
        if(isPresent(root->children.at(i),x)) return true;
    }

    return false;
}
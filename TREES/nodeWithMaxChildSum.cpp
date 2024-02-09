/*
Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.
*/

#include<bits/stdc++.h>
using namespace std;

class Pair{
    public:
        TreeNode<int>* maxSumNode;
        int maxSum;
        Pair(TreeNode<int>* node, int sum){
            maxSumNode = node;
            maxSum = sum;
        }
};

Pair* Helper(TreeNode<int>* root){
    if(root == nullptr) return new Pair(nullptr, 0);

    int sum = root->data;
    for(int i = 0 ; i < root->children.size() ; i++){
        sum += root->children.at(i)->data;
    }

    Pair* ans = new Pair(root, sum);

    for(int i = 0 ; i < root->children.size() ; i++){
        Pair* temp = Helper(root->children.at(i));
        if (temp->maxSum > ans->maxSum) {
          delete ans;
          ans = temp;
        }
        else delete temp;
    }

    return ans;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    Pair* ans = Helper(root);
    TreeNode<int>* result = ans->maxSumNode;
    return result;
}
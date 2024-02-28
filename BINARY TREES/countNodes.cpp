#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

int countNodes(BinaryTreeNode<int>* root){
    if(root == NULL) return 0;

    int sum = 1;
    sum += countNodes(root->left);
    sum += countNodes(root->right);

    return sum;
}
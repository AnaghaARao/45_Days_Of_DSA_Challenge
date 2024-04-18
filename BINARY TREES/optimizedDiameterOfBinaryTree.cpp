#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

// using in-built pair class
// better approach function
// TIME COMPLEXITY: O(n)

pair<int, int> heightDiameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<int, int> res;
        res.first = 0;
        res.second = 0;
        return res;
    }

    pair<int, int> left = heightDiameter(root->left);
    pair<int, int> right = heightDiameter(root->right);

    int leftHeight = left.first;
    int leftDiameter = left.second;

    int rightHeight = right.first;
    int rightDiameter = right.second;

    int height = 1 + max(leftHeight, rightHeight);
    int diameter = max(leftHeight+rightHeight, leftDiameter, rightDiameter);

    pair<int, int> res;
    res.first = height;
    res.second = diameter;

    return res;
}
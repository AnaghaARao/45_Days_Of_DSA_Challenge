#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

// In this approach we dont traverse through the subtrees multiple times. 
// in a single traversal we determine all the attributes and use it for the computation.

class Triplet{
    public:
        int minimum;
        int maximum;
        bool isBST;
};

Triplet isBSThelper(BinaryTreeNode<int>* root){
    if(root == NULL){
        Triplet res;
        res.minimum = INT_MAX;
        res.maximum = INT_MIN;
        res.isBST = true;
        return res;
    }

    Triplet leftRes = isBSThelper(root->left);
    Triplet rightRes = isBSThelper(root->right);
    int Max = max(root->data, max(leftRes.maximum, rightRes.maximum));
    int Min = min(root->data, min(leftRes.minimum, rightRes.minimum));
    bool isBSTRes = (root->data > leftRes.maximum) && (root->data <= rightRes.minimum) && leftRes.isBST && rightRes.isBST;
    Triplet res;
    res.isBST = isBSTRes;
    res.maximum = Max;
    res.minimum = Min;
    return res;
}

bool isBST(BinaryTreeNode<int>* root){
    Triplet res = isBSThelper(root);
    return res.isBST;
}
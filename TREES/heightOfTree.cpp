/*Given a generic tree, find and return the height of given tree. The height of a tree is defined as the longest distance from root node to any of the leaf node. Assume the height of a tree with a single node is 1.*/

#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

int getHeight(TreeNode<int>* root) {
    if(root == nullptr) return 0;
    int height = 0;
    for(int i = 0 ; i < root->children.size() ; i++){
        int smallAns = 0;
        smallAns += getHeight(root->children.at(i));
        height = (height < smallAns) ? smallAns:height;
    }
    return height+1;
}
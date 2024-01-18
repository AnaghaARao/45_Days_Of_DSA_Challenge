/* Given a generic tree, count and return the number of leaf nodes present in the given tree. */

#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

int getLeafNodes(TreeNode<int>* root){
    if(root == nullptr) return 0;
    if(root->children.empty()){
        return 1;
    }

    int leafCount = 0;
    for(int i = 0 ; i < root->children.size() ; ++i){
        leafCount += getLeafNodes(root->children[i]);
    }

    return leafCount;
}
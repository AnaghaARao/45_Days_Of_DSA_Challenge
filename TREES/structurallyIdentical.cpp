/*
    Given two generic trees, return true if they are structurally identical. Otherwise return false.
    Structural Identical
    If the two given trees are made of nodes with the same values and the nodes are arranged in the same way, then the trees are called identical.  
*/

#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    // Write your code here
    if(root1 == nullptr && root2 == nullptr) return true;

    if(root1->children.size() != root2->children.size()) return false;

    for(int i = 0 ; i < root1->children.size() ; i++){
        if(!(areIdentical(root1->children.at(i), root2->children.at(i)))) return false;
    }

    return true;
}
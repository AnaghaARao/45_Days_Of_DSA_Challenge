/*Given a generic tree, find and return the sum of all nodes present in the given tree.*/

#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

int sumOfNodes(TreeNode<int>* root) {
    // Write your code here
    int sum = 0;
    sum += root->data;
    for(int i = 0 ; i < root->children.size(); i++){
        sum += sumOfNodes(root->children.at(i));
    }
    return sum;
}
// Given a tree and an integer x, find and return the number of nodes which contains data greater than x.

#include<bits/stdc++.h>
using namespace std;

int getLargeNodeCount(TreeNode<int>* root, int x) {
    if(root == nullptr) return 0;
    int cnt = 0;
    if(root->data > x) cnt++;
    for(int i = 0 ; i < root->children.size() ; i++){
        cnt+=getLargeNodeCount(root->children.at(i),x);
    }

    return cnt;
}
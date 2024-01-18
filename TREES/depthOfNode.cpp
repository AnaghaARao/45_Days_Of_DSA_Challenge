/* Print all nodes at depth/ level d */

#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

void printAtLevelK(TreeNode<int>* root, int k){
    if(root == nullptr) return;
    if(k == 0){
        cout<< root->data << endl;
        return;
    }
    for(int i = 0 ; i < root->children.size() ; i++){
        printAtLevelK(root->children.at(i), k-1);
    }
}
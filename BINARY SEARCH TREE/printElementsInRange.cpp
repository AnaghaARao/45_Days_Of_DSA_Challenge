/* Given a Binary Search Tree and two integers k1 and k2, 
find and print the elements which are in range k1 and k2 (both inclusive).
Print the elements in increasing order. */

#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

helper(BinaryTreeNode<int>* root, int k1, int k2, vector<int>& res){
    if(root == NULL) return;

    if(root->data >= k1 && root->data <= k2) res.push_back(root->data);
    if(k1<root->data) helper(root->left, k1, k2, res);
    if(k2>root->data) helper(root->right, k1, k2, res);
}

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	// Write your code here
    vector<int> res;
    helper(root, k1, k2, res);
    sort(res.begin(), res.end());
    for(int ele : res) cout<< ele << "\t";
    return;
}
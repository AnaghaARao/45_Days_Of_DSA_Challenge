/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

/*
	The first value of the pair must be the minimum value in the tree and 
	the second value of the pair must be the maximum value in the tree
*/

#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
    if(root == NULL){
        pair<int, int> res;
        res.first = 0;
        res.second = 0;
        return res;
    }

    pair<int, int> res;
    res.first = root->data;
    res.second = root->data;

    pair<int, int> left = getMinAndMax(root->left);
    pair<int, int> right = getMinAndMax(root->right);

    res.first = min(left.first, right.first, res.first);
    res.second = max(left.second, right.second, res.second);

    return res;
}
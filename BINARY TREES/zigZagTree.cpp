/*
Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. 
This means odd levels should get printed from left to right and even level right to left.
*/

#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

template <typename T>
class Node {
    public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data=data;
        this->next=NULL;
    }
};

void printZigZag(vector<vector<int>> tree){
    int n = tree.size();
    for(int i = 0 ; i < n ; i++){
        int m = tree[i].size();
        for(int j = 0 ; j < m ; j++){
            cout<<tree[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return;
}

void zigZagOrder(BinaryTreeNode<int> *root) {
    
    // base case
    if(root == nullptr){
        return;
    }

    // initialization
    vector<vector<int>> res;
    queue<BinaryTreeNode<int>*> pendingNodes;
    bool leftToRight = true;

    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        int levelWiseSize = pendingNodes.size();
        vector<int> row(levelWiseSize);
        
        for(int i = 0 ; i < levelWiseSize ; i++){
            // find front for each iteration
            BinaryTreeNode<int>* front = pendingNodes.front();
            pendingNodes.pop();
            
            // VERY IMPORTANT STEP:
            int index = (leftToRight) ? i : (levelWiseSize-i-1);
            row[index] = front->data;

            if(front->left) pendingNodes.push(front->left);
            if(front->right) pendingNodes.push(front->right);
        }

        leftToRight = !leftToRight;
        res.push_back(row);
    }
    printZigZag(res);
    return;
}

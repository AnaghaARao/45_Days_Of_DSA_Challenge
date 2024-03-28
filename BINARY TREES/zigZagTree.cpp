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

void zigZagOrder(BinaryTreeNode<int> *root) {
    if(root == nullptr) return;

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    int flag = 1;

    while(! pendingNodes.empty()){

        Node<int>* levelHead = nullptr;
        Node<int>* levelTail = nullptr;
        int levelSize = pendingNodes.size();

        for(int i = 0 ; i < )
    }
}

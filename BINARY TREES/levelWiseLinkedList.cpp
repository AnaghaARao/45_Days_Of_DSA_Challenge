/*
Given a binary tree, write code to create a separate linked list for each level. 
You need to return the array which contains head of each level linked list.
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

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    
    vector<Node<int>*> result;

    if(root == NULL){
        return result;
    }

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(! pendingNodes.empty()){
        Node<int>* levelHead = nullptr; // declaring level head
        Node<int>* levelTail = nullptr; // declaring level tail
        int levelSize = pendingNodes.size(); // declaring level size

        for(int i = 0 ; i < levelSize ; i++){
            // determining the front of pendingNodes => head of the level linked list
            BinaryTreeNode<int>* front = pendingNodes.front();
            pendingNodes.pop(); 

            Node<int>* temp = new Node<int>(front->data);

            if(levelHead == nullptr){
                levelHead = temp;
                levelTail = temp;
            }else{
                levelTail->next = temp;
                levelTail = temp;
            }

            if(front->left != nullptr) pendingNodes.push(front->left);
            if(front->right != nullptr) pendingNodes.push(front->right);
        }
        result.push_back(levelHead);
    }
    return result;
}
/* Given a BST, convert it into a sorted linked list. You have to return the head of LL. */
#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

template <typename T>
class Node{
    public:
    T data;
    Node<T> *next;

    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

Node<int>* helper(BinaryTreeNode<int>* root, Node<int>* lhead, Node<int>* ltail, Node<int>* rhead, Node<int>* rtail ){
    if(root == nullptr) return nullptr;

    Node<int>* ltemp = helper(root->left, lhead, ltail, rhead, rtail);
    if(ltemp != nullptr){
        if(lhead == nullptr && ltail == nullptr){
            lhead = ltail = ltemp;
        }else{
            ltail->next = ltemp;
            ltail = ltemp;
        }
    }

    Node<int>* mid = new Node<int>(root->data);

    Node<int>* rtemp = helper(root->right, lhead, ltail, rhead, rtail);
    if(rtemp != nullptr){
        if(rhead == nullptr && rtail == nullptr){
            rhead = rtail = rtemp;
        }else{
            rtail->next = rtemp;
            rtail = rtemp;
        }
    }
	
	if(ltail != nullptr && mid != nullptr){
		ltail->next = mid;
		ltail->next = mid;
	}
	else if(ltail == nullptr && mid != nullptr && rhead != nullptr){
		mid->next = rhead;
		return mid;
	}else return mid;

    if(rhead != nullptr && ltail != nullptr){
        ltail->next = rhead;
		return ltail;
    }
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    Node<int>* ans = helper(root, nullptr, nullptr, nullptr, nullptr);
    return ans;
}
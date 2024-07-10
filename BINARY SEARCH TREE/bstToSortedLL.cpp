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

Node<int>* mergeList(Node<int>* list1 , Node<int>* list2){
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    Node<int>* head = NULL;
    Node<int>* tail = NULL;

    while(list1 != NULL && list2 != NULL){
        if(list1->data <= list2->data){
            if(head == NULL){
                head = tail = list1;
            }
            else{
                tail->next = list1;
                tail = list1;
            }
            list1 = list1->next;
        }
        else{
            if(head == NULL){
                head = tail = list2;
            }
            else{
                tail->next = list2;
                tail = list2;
            }
            list2 = list2->next;
        }
    }

    if(list1 != NULL) tail->next = list1;
    if(list2 != NULL) tail->next = list2;

    return head;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	if(root == NULL) return nullptr;

    Node<int>* leftList = constructLinkedList(root->left);
    Node<int>* rightlist = constructLinkedList(root->right);

    Node<int>* rootNode = new Node<int>(root->data);

    Node<int>* mergeHead = mergeList(leftList, rootNode);
    mergeHead = mergeList(mergeHead, rightlist);

    return mergeHead;
}
/*
    You have been given a singly linked list of integers where the elements are sorted in ascending order. 
    Write a function that removes the consecutive duplicate values such that the given list only contains unique elements and returns the head to the updated list.
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            next = NULL;
        }
};

Node *removeDuplicates(Node *head){
    // base case:
    if(head == NULL || head->next == NULL) return head;
    Node *temp = head; 
    while(temp->next!=NULL){
        Node *nextTemp = temp->next;
        if(temp->data == nextTemp->data){
            temp->next = nextTemp->next;
            delete nextTemp;
        }else temp = temp->next;
    }
    return head;
}
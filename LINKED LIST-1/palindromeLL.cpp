/*
You have been given a head to a singly linked list of integers. 
Write a function check to whether the list given is a 'Palindrome' or not.
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
};

Node* reverseLL(Node *head){
    if(head==NULL || head->next==NULL) return head;
    Node *curr = head;
    Node *prev = NULL;
    Node *nextNode;
    while(curr != NULL){  
        // when while condition is true, both curr and nextNode will have null while prev is pointing to the last element => head of reversed LL
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

Node* copyLL(Node *head){
    Node *temp = head;
    Node *newHead = NULL;
	Node *newTail = NULL;
    while(temp != NULL){
        Node *newNode = new Node(temp->data);
        if(newHead == NULL){
            newHead = newNode;
            newTail = newNode;
        }else{
            newTail->next = newNode;
            newTail = newTail->next;
        }
        temp = temp->next;
    }
    return newHead;
}

bool isPalindrome(Node *head)
{
    //Write your code here
    if(head==NULL || head->next==NULL) return true;
    Node *temp = head;
    Node *rev = copyLL(head);
    Node *reverse = reverseLL(rev);
    while(temp!=NULL && reverse!=NULL){
        if(temp->data != reverse->data) return false;
		temp = temp->next;
		reverse = reverse->next;
    }
    return true;
}
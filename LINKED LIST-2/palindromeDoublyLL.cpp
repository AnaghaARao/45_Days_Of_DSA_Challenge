/*You have been given a head to a doubly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

bool palindromeDLL(Node* head){
    if(head==NULL || head->next == NULL) return true;
    Node *temp = head;
    Node *tail;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    tail = temp;
    temp = head;
    while(temp!=tail){
        if(temp->data != tail->data) return false;
        temp = temp->next;
        tail = tail->prev;
    }
    return true;
}
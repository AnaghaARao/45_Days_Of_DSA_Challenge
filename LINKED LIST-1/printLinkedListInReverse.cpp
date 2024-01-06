/*
    Problem statement
    You have been given a singly linked list of integers. Write a function to print the list in a reverse order.
    To explain it further, you need to start printing the data from the tail and move towards the head of the list, printing the head data at the end.
    Note :
    You can’t change any of the pointers in the linked list, just print the linked list in the reverse order.
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

void printReverse(Node *head){
    // base case:
    if(head == NULL) return;
    // recusive call
    printReverse(head->next);
    // induction step
    cout<<head->data<<" ";
}
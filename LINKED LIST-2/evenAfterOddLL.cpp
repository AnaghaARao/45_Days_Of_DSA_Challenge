/*
    For a given singly linked list of integers, arrange the nodes such that all the even number nodes are placed after the all odd number nodes. The relative order of the odd and even terms should remain unchanged.
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

Node *evenAfterOdd(Node *head){
    if(head == NULL || head->next == NULL) return head;

    Node *temp = head;
    Node *oddHead = NULL, *oddTail = NULL;
    Node *evenHead = NULL, *evenTail = NULL;
    
    while(temp!=NULL){

        // check for odd:
        if(temp->data%2 == 1){
            // check for 1st node case
            if(oddHead == NULL){
                oddHead = temp;
                oddTail = temp;
            }
            else{
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
            temp = temp->next;
        }
        // case: even
        else{
            // check for 1st node case:
            if(evenHead == NULL){
                evenTail = temp;
                evenHead = temp;
            }
            else{
                evenTail->next = temp;
                evenTail = evenTail->next;
            }
            temp = temp->next;
        }
    }

    if(oddHead == NULL){
        evenTail->next = NULL;
        return evenHead;
    }
    if(evenHead == NULL){
        oddTail->next = NULL;
        return oddHead;
    }

    oddTail->next = evenHead;
    evenTail->next = NULL;
    return oddHead;
}
/*
ou have been given two sorted(in ascending order) singly linked lists of integers.

Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) and return the new head to the list.

Note :
Try solving this in O(1) auxiliary space.

No need to print the list, it has already been taken care.
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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2){
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    Node *head = NULL;
    Node *tail = NULL;
    Node *temp1 = head1;
    Node *temp2 = head2;
    while(temp1!=NULL && temp2!=NULL){
        if(head == NULL){
            if(temp1->data <= temp2->data){
                head = temp1;
                tail = temp1;
				temp1 = temp1->next;
            }
            else{
                head = temp2;
                tail = temp2;
				temp2 = temp2->next;
            }
        }
        else{
            if(temp1->data <= temp2->data){
                tail->next = temp1;
                tail = tail->next;
				temp1 = temp1->next;
            }
            else{
                tail->next = temp2;
                tail = tail->next;
				temp2 = temp2->next;
            }
        }
		tail->next = NULL;        
    }
    if(temp1 == NULL && temp2!=NULL) tail->next = temp2;
    if(temp2 == NULL && temp1!=NULL) tail->next = temp1;
    return head;
}
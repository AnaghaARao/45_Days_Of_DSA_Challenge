/*
Given a singly linked list of integers, reverse it iteratively and return the head to the modified list.
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

Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
	if(head==NULL || head->next==NULL) return head;
	Node *temp;
	Node *curr = head;
	Node *prev = NULL;
	while(curr!=NULL){
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	return prev;
}
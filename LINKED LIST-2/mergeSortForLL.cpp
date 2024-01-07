/* Given a singly linked list of integers, sort it using 'Merge Sort.' */

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

// function to find the middle term
Node *middle(Node *head){
	Node *slow = head, *fast = head;
	while(fast->next!=NULL && fast->next->next!=NULL){
		slow= slow->next;
		fast = fast->next->next;
	}
	return slow;
}

// function to merge 2 sorted LL's
Node* merge(Node *head1, Node *head2){
	if(head1 == NULL) return head2;
	if(head2 == NULL) return head1;

	Node *temp1 = head1;
	Node *temp2 = head2;
	Node *head = NULL, *tail = NULL;

	while(temp1 != NULL && temp2 != NULL){
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
		}else{
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

	if(temp1 == NULL && temp2 != NULL) tail->next = temp2;
	if(temp2 == NULL && temp1 != NULL) tail->next = temp1;
	return head;
}

Node *mergeSort(Node *head)
{
	//Write your code here
	if(head == NULL || head->next==NULL) return head;
	Node *mid = middle(head);
	Node *head2 = mid->next;
	mid->next = NULL;
	Node *temp1 = mergeSort(head);
	Node *temp2 = mergeSort(head2);
	Node *finalHead = merge(temp1, temp2);
}
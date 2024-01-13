/*Given a singly linked list of integers, reverse it using recursion and return the head to the modified list. 
You have to do this in O(N) time complexity where N is the size of the linked list.*/

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

Node *reverseLL_1(Node *head){
	if(head==NULL || head->next == NULL){
		return head;
	}
	Node *smallAns = reverseLL_1(head->next);

	Node *tail = head->next;
	tail->next = head;
	head->next = NULL;
	return smallAns;
}

class Pair{
	public:
		Node *head;
		Node *tail;
};

Pair helper(Node *head)
{
    //Write your code here
	if(head==NULL || head->next==NULL) return head;
	
	Pair smallAns = reverseLinkedListRec(head->next);

	smallAns.tail->next = head;
	head->next = NULL;
	Pair temp;
	temp.head = smallAns.head;
	temp.tail = head;
	return temp;
}

Node* reverseLL(Node *head){
	return helper(head).head;
}
/*
    Problem statement
    You have been given a singly linked list of integers along with an integer 'N'. 
    Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.
    Hint:
    Identify how many pointers you require and try traversing them to right places and connect nodes accordingly also don't forget to disconnect what's required else it could create cycles.
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

int length(Node *head){
    Node *temp = head;
	int len = 0;

	while(temp!=NULL){
		len++;
		temp=temp->next;
	}

	return len;
}

Node *appendLastNToFirst(Node *head, int n)
{
    // base case:
    if(n == 0 || head == NULL) return head;

    Node *temp = head;
    Node *newHead = NULL,*newTail = NULL, *tail = NULL;
    int len = length(head);
    int cnt = 0;

    while(temp->next!=NULL){
        if(cnt == len-n-1){
            newTail = temp;
            newHead = temp->next;
        }
        temp = temp->next;
        cnt++;
    }
    
    tail = temp;
    tail->next = head;
    newTail->next = NULL;
    return newHead;
}

/*
    4 4 7 8 3 36 8 17 26 7 7 -1
    7
*/
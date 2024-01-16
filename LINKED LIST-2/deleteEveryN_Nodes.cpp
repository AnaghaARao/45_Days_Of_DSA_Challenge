/*
    You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list. Indexing starts from 1.
    To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.
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

Node *skipMdeleteN(Node *head, int M, int N){
    if(head == NULL || N == 0) return head;
    if(M==0) return NULL;
	Node *temp = head;
    while(temp!=NULL){
        int x = 0;
        while(x!=M){
            if(temp == NULL) return head;
            temp = temp->next;
            x++;
        }
        Node *deleteTemp = temp;
        int y = 0;
        while(y!=N){
            if(deleteTemp == NULL) return head;
            deleteTemp = deleteTemp->next;
            y++;
        }
        temp->next = deleteTemp->next;
        delete deleteTemp;
    }
    return head;    
}

Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
	if(head == NULL || N == 0) return head;
    if(M==0) return NULL;
	Node *temp = head;

    while(temp!=NULL){
		int x = 0;
		while(x!=M-1){
			if(temp == NULL) break;
			temp = temp->next;
			x++;
		}
		Node *end;
		if(x==M-1){
			end = temp;
			int y = 0;
			temp = temp->next;
			while(y!=N-1){
				if(temp == NULL) break;
				Node *t = temp;
				temp = temp->next;
				delete t;
				y++;
			}
			if(y==N-1){
				end->next = temp->next;
				delete temp;
				temp = end->next;
			}else{
				end->next = NULL;
			}
		}else{
			return head;
		}
		return head;
	} 
}
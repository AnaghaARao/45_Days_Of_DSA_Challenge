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


void printIthNode(Node *head, int i)
{
	Node *temp = head;
	int pos = 0;
	while(temp!=NULL){
		if(pos==i) break;
		temp = temp->next;
		pos++;
	}

	if(temp == NULL) return;
	cout<< temp->data;
}
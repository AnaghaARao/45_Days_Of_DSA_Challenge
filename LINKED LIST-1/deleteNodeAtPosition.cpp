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

// function to find the length of the linkedlist:
int length(Node *head){
    int cnt = 0;
    Node *temp = head;
    while(temp->next != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// function to take inputs for the linkedlist:
Node* takeInput(){
    int ele;
    cin>>ele;
    Node *head = NULL;
    Node *tail = NULL;
    while(ele != -1){
        Node *newNode = new Node(ele);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }
        cin>>ele;
    }
    return head;
}

// function to delete node at a particular position:
Node *deleteNode(Node *head, int pos){
    Node *prev = NULL;
    Node *curr = head;
	if(curr==NULL ) return head;
    if(pos<0) return head;

    else if(pos == 0){
        head = head->next;
        delete curr;
		delete prev;
        return head;
    }

	else{
		int cnt = 0;
		while(curr != NULL){
			if(cnt == pos){
				prev->next = curr->next;
				delete curr;
				return head;
			}
			cnt++;
			prev = curr;
			curr = curr->next;
		}
	}

	return head;
}
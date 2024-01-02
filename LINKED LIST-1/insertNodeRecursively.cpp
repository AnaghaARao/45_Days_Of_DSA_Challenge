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

void helper( Node *temp, Node *prev, int pos,int cnt, Node* newNode){
    if(temp!=NULL){ // induction step
        if(pos==cnt){
            prev->next = newNode;
            newNode->next = temp;
            return;
        }
        helper(temp->next, temp, pos, cnt+1, newNode); // recursive call
    }
    else if(pos == cnt){ // for last index position
        prev->next = newNode;
        newNode->next = temp;
        return;
    }
    else return;
}

Node* InsertNode(Node* head, int pos, Node* newNode){
    if(pos<0) return head;
    else if(pos==0) { // for 0th index
        newNode->next = head;
        head = newNode;  
        return head;
    }
    else helper(head, NULL, pos, 0, newNode);
    return head;
}
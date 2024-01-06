/*
    Given a singly linked list of integers and position 'i', delete the node present at the 'i-th' position in the linked list recursively.
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

void helper(Node *curr, Node *prev, int pos, int cnt){
    // base case:
    if(curr == NULL){
        if(cnt == pos){
            prev->next = NULL;
            delete curr;
        }
        return;
    }

    // recursive call and induction step:
    if(cnt == pos){
        prev->next = curr->next;
        delete curr;
        return;
    }
    else helper(curr->next, curr, pos, cnt+1);
}

Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
    if(pos == 0){
        Node *temp = head;
        head = head->next;
        delete temp;
    }else{
        helper(head, NULL, pos, 0);
    }
    return head;
}
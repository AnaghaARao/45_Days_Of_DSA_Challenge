#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int data){
            next = NULL;
            this->data = data;
        }

        
};

Node* takeInput(){
    Node* head = NULL;
    Node* tail = NULL;
    int ele;
    cin>> ele;
    while(ele != -1){
        Node *temp = new Node(ele);
        if(head == NULL){
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            tail = tail->next;
        }
        cin>>ele;
    } 
    return head;
}

void print(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<< temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node *head = takeInput();
    print(head);
}
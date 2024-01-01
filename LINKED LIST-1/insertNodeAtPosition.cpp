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

int length(Node *head){
    int cnt = 0;
    Node *temp = head;
    while(temp->next!=NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

Node* insertAtPosition(Node *head, int pos, int data){
    Node *newNode = new Node(data);
    Node *temp = head;
    int cnt = 0;

    if(pos == 0){
        newNode->next = head;
        head = newNode;
        return head;
    }

    while(temp != NULL && cnt < pos-1){
       temp = temp->next;
       cnt++;
    }
    if(temp != NULL){
        Node *a = temp->next;
        temp->next = newNode;
        newNode->next = a;
    }
    return head;
}

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
    cout<<endl;
}

int main(){
    Node *head = takeInput();
    print(head);
    head = insertAtPosition(head , 4, 1);
    print(head);
    head = insertAtPosition(head , 0, 2);
    print(head);
}
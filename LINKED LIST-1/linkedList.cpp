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

void print(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<< temp->data;
        temp = temp->next;
    }
}

int main(){
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    Node *head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head);
}
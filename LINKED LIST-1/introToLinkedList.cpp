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

int main(){
    // static creation of node
    Node n1(10);
    Node n2(20);
    n1.next = &n2;
    cout << n1.data << " " << n2.data << endl;
    Node *head = &n1;
    cout << head -> data <<endl;

    // dynamic creation of nodes:
    Node *n3 = new Node(10);
    Node *n4 = new Node(22);
    Node *head = n3;
    n3->next = n4;
}
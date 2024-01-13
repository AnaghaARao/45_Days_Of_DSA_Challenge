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

int helper(Node *head, int n, int index){
    if(head == NULL) return -1;
    if(head->data == n) return index;
    else helper(head->next, n, index+1);
}

int findNodeRec(Node *head, int n){
    return helper(head, n, 0);
}
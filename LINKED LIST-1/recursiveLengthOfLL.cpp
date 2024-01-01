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
    
int helperFunction(Node *head , int cnt){
    if(head == NULL) return cnt;
    helperFunction(head->next, cnt + 1);
}

int length(Node *head) {
    return helperFunction(head,0);
}
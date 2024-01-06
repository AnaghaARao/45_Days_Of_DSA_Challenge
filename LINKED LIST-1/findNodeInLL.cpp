/*
You have been given a singly linked list of integers. 
Write a function that returns the index/position of integer data denoted by 'N' (if it exists). 
Return -1 otherwise.
*/

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

int findNode(Node *head, int n){
    // Write your code here.
    Node *temp = head;
    int cnt = 0;
    while(temp!=NULL){
        if(temp->data == n) break;
        else{
            cnt++;
            temp = temp->next;
        }
    }
    if(temp!=NULL) return cnt;
    else return -1;
}

